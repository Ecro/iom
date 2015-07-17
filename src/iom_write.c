#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include "iom.h"

int iom_convert_keychar_to_key(char *keychar, IOM_KeyCode *key)
{
	char tmp[KEY_CHAR_TOTAL_SIZE];
	int i;
	
	for(i=0; i<KEY_CHAR_VALUE_SIZE; i++)
	{
		tmp[i] = keychar[i+1];
	}
	tmp[KEY_CHAR_VALUE_SIZE] = '\0';
	key->value = atoi(tmp);

	for(i=0; i<KEY_CHAR_ISPRESSED_SIZE; i++)
	{
		tmp[i] = keychar[i+1+KEY_CHAR_VALUE_SIZE];
	}
	tmp[KEY_CHAR_ISPRESSED_SIZE] = '\0';
	key->isPressed = atoi(tmp);

	for(i=0; i<KEY_CHAR_ISPRESSED_SIZE; i++)
	{
		tmp[i] = keychar[i+1+KEY_CHAR_VALUE_SIZE+KEY_CHAR_ISPRESSED_SIZE];
	}
	tmp[KEY_CHAR_TIME_SIZE] = '\0';
	key->time = atoi(tmp);

	return 0;
}

int iom_write_key(int fd, IOM_KeyCode *key)
{
	struct input_event ev[2];
	int ret = 0;
	static unsigned long time = 0;

	//printf("[%s][%s]key : %d, isPressed : %d\n", APP_NAME, __FUNCTION__, key->value, key->isPressed);
	if(key->isPressed == 0)
	{
		ev[0].code=SYN_REPORT; ev[0].type=EV_SYN; ev[0].value=0;
		ev[1].code=key->value; ev[1].type=EV_KEY; ev[1].value=key->isPressed;
		
	}
	else if(key->isPressed == 1)
	{
		ev[0].code=MSC_SCAN; ev[0].type=EV_MSC; ev[0].value=key->value;
		ev[1].code=key->value; ev[1].type=EV_KEY; ev[1].value=key->isPressed;
	}
	else
	{
		//TODO : Repeat
		return 0;
	}

	if(time != 0)
		usleep((key->time - time) * 1300 );
		
	ret = write(fd, ev, sizeof(struct input_event)*2);

	time = key->time;
	
	return ret;
}

int iom_write(int fd)
{
	int ret = 0;
	FILE *keycode_fp;
	IOM_KeyCode *keycode = (IOM_KeyCode *)malloc(sizeof(struct IOM_KeyCode));
	char key_char[KEY_CHAR_TOTAL_SIZE];

	keycode_fp = fopen(KEY_CODE_FILE_NAME, "r");
	if(keycode_fp == NULL)
	{
		printf("[%s][ERR] fail to open %s\n", APP_NAME, KEY_CODE_FILE_NAME);
		return IOM_ERROR;
	}

	while(!feof(keycode_fp))
	{
		fread(key_char, KEY_CHAR_TOTAL_SIZE, 1, keycode_fp);
		iom_convert_keychar_to_key(key_char, keycode);
		iom_write_key(fd, keycode);
		usleep(100);
	}

	fclose(keycode_fp);
	free(keycode);

	return ret;
}

