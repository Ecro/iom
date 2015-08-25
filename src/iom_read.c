#include <stdio.h>
#include <linux/input.h>
#include <pthread.h>
#include "iom.h"
#include "iom_util.h"

int iom_read_key(int fd, IOM_KeyCode *keycode)
{
	struct input_event ev[2];
	int ret = IOM_SUCCESS;

	ret = read(fd, ev, sizeof(struct input_event)*2);
	
	//printf("0: %d %d %d\n", ev[0].type, ev[0].value, ev[0].code);
	//printf("1: %d %d %d\n", ev[1].type, ev[1].value, ev[1].code);

	if((ev[0].code==MSC_SCAN) && (ev[0].type==EV_MSC) && (ev[1].type==EV_KEY))
	{
		keycode->value = ev[1].code;
		keycode->isPressed = ev[1].value;
		keycode->seconds = ev[1].time.tv_sec;
		keycode->micro_seconds = ev[1].time.tv_usec;
		//printf("[%s][%s]key : %d, isPressed : %d\n", APP_NAME, __FUNCTION__, keycode->value, keycode->isPressed);
	}
	else
		return IOM_ERROR;

	return IOM_SUCCESS;
}

int iom_read(int fd)
{
	FILE *keyuser_fp;
	IOM_KeyCode *keycode = (IOM_KeyCode *)malloc(sizeof(struct IOM_KeyCode));
	IOM_KeyUser *keyuser = (IOM_KeyCode *)malloc(sizeof(struct IOM_KeyCode));
	char keycode_char[KEY_CHAR_TOTAL_SIZE+2];
	int i;

	keyuser_fp = fopen(KEY_USER_FILE_NAME, "w+");
	if(keyuser_fp == NULL)
	{
		printf("[%s][ERR] fail to open %s\n", APP_NAME, KEY_USER_FILE_NAME);
		return IOM_ERROR;
	}

	while(1)
	{
		if(iom_read_key(fd, keycode) == IOM_SUCCESS)
		{
			if(keycode->value != KEY_F12)
			{
				//sprintf(keycode_char, "%04d%04d%012lu|", keycode->value, keycode->isPressed, keycode->time);
				//fwrite(keycode_char, strlen(keycode_char), 1, keycode_fp);
				
				if(iom_convert_keycode_to_keyuser(keycode, keyuser) == IOM_SUCCESS)
				{
					if(keyuser->isChanged == 1)
					{
						if(keyuser->key[0] == '<')
						{
							for(i=0;i<KEY_USER_MAX_CHAR;i++)
							{
								fwrite(&keyuser->key[i], 1, 1, keyuser_fp);
							}
						}
						else
						{
							fwrite(&keyuser->key[0], 1, 1, keyuser_fp);
						}
					}
				}
			}
			else
			{
				fclose(keyuser_fp);
				free(keyuser);
				free(keycode);
				return IOM_SUCCESS;
			}
		}
	}
}
