#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include "iom.h"
#include "iom_util.h"

int iom_write_key(int fd, IOM_KeyCode *keycode, int type)
{
	struct input_event ev[2];
	int ret = 0;

	//printf("[%s][%s]key : %d, type : %d, isPressed : %d\n", APP_NAME, __FUNCTION__, keycode->value, type, keycode->isPressed);

	if(type == IOM_KEY_NORMAL)
	{
		ev[0].code=MSC_SCAN; ev[0].type=EV_MSC; ev[0].value=keycode->value;
		ev[1].code=keycode->value; ev[1].type=EV_KEY; ev[1].value=1;
		ret = write(fd, ev, sizeof(struct input_event)*2);
		usleep(100);

		ev[0].code=MSC_SCAN; ev[0].type=EV_MSC; ev[0].value=0;
		ev[1].code=keycode->value; ev[1].type=EV_KEY; ev[1].value=0;
		ret = write(fd, ev, sizeof(struct input_event)*2);
	}
	else
	{
		if(keycode->isPressed == 1)
		{
			ev[0].code=MSC_SCAN; ev[0].type=EV_MSC; ev[0].value=keycode->value;
			ev[1].code=keycode->value; ev[1].type=EV_KEY; ev[1].value=1;
			ret = write(fd, ev, sizeof(struct input_event)*2);
		}
		else
		{
			ev[0].code=MSC_SCAN; ev[0].type=EV_MSC; ev[0].value=0;
			ev[1].code=keycode->value; ev[1].type=EV_KEY; ev[1].value=0;
			ret = write(fd, ev, sizeof(struct input_event)*2);
		}
	}
	
	return ret;
}

int iom_write(int fd)
{
	int i, ret = 0;
	FILE *keyuser_fp;
	IOM_KeyUser *keyuser = (IOM_KeyUser *)malloc(sizeof(struct IOM_KeyUser));
	IOM_KeyCode *keycode = (IOM_KeyCode *)malloc(sizeof(struct IOM_KeyCode));
	IOM_ControlWord *cw = (IOM_ControlWord *)malloc(sizeof(struct IOM_ControlWord));

	keyuser_fp = fopen(KEY_USER_FILE_NAME, "r");
	if(keyuser_fp == NULL)
	{
		printf("[%s][ERR] fail to open %s\n", APP_NAME, KEY_USER_FILE_NAME);
		return IOM_ERROR;
	}

	while(!feof(keyuser_fp))
	{
		if((keyuser->key[0] = fgetc(keyuser_fp)) != -1)
		{
			if(keyuser->key[0] == '<')
			{
				for(i=1;i<KEY_USER_MAX_CHAR;i++)
					keyuser->key[i] = fgetc(keyuser_fp);
			}

			ret = iom_check_control_word(keyuser, cw);
			if(ret == IOM_DELAY)
			{
				sleep(cw->delay_seconds);
			}
			else
			{
				if(iom_convert_keyuser_to_keycode(keyuser, keycode) == IOM_SUCCESS)
				{
					if((keyuser->key[0] == '<' && keycode->isPressed == 1) || keyuser->key[0] == '>' && keycode->isPressed == 0)
						iom_write_key(fd, keycode, IOM_KEY_CONTROL);
					else
						iom_write_key(fd, keycode, IOM_KEY_NORMAL);
				}
				usleep(15000);
			}
		}
	}

	fclose(keyuser_fp);
	free(keyuser);
	free(keycode);
	free(cw);

	return ret;
}

