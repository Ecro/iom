#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include "iom.h"

int iom_write_key(int fd, IOM_KeyCode *keycode)
{
	struct input_event ev[2];
	int ret = 0;
	static unsigned long time = 0;

	//printf("[%s][%s]key : %d, isPressed : %d\n", APP_NAME, __FUNCTION__, keycode->value, keycode->isPressed);

	if(keycode->isShiftPressed == 1)
	{
		ev[0].code=MSC_SCAN; ev[0].type=EV_MSC; ev[0].value=KEY_LEFTSHIFT;
		ev[1].code=KEY_LEFTSHIFT; ev[1].type=EV_KEY; ev[1].value=1;
		ret = write(fd, ev, sizeof(struct input_event)*2);
		usleep(100);
	}

	ev[0].code=MSC_SCAN; ev[0].type=EV_MSC; ev[0].value=keycode->value;
	ev[1].code=keycode->value; ev[1].type=EV_KEY; ev[1].value=1;
	ret = write(fd, ev, sizeof(struct input_event)*2);
	usleep(100);

	ev[0].code=SYN_REPORT; ev[0].type=EV_SYN; ev[0].value=0;
	ev[1].code=keycode->value; ev[1].type=EV_KEY; ev[1].value=0;
	ret = write(fd, ev, sizeof(struct input_event)*2);
	usleep(100);
	
	if(keycode->isShiftPressed == 1)
	{
		ev[0].code=SYN_REPORT; ev[0].type=EV_SYN; ev[0].value=0;
		ev[1].code=KEY_LEFTSHIFT; ev[1].type=EV_KEY; ev[1].value=0;
		ret = write(fd, ev, sizeof(struct input_event)*2);
		usleep(100);
	}
	return ret;
}

int iom_write(int fd)
{
	int ret = 0;
	FILE *keyuser_fp;
	IOM_KeyUser *keyuser = (IOM_KeyUser *)malloc(sizeof(struct IOM_KeyUser));
	IOM_KeyCode *keycode = (IOM_KeyCode *)malloc(sizeof(struct IOM_KeyCode));
	char keyuser_char = '\0';

	keyuser_fp = fopen(KEY_USER_FILE_NAME, "r");
	if(keyuser_fp == NULL)
	{
		printf("[%s][ERR] fail to open %s\n", APP_NAME, KEY_USER_FILE_NAME);
		return IOM_ERROR;
	}

	while(!feof(keyuser_fp))
	{
		if((keyuser_char = fgetc(keyuser_fp)) != -1)
		{
			if(iom_convert_keyuserchar_to_keycode(keyuser_char, keycode) == IOM_SUCCESS)
				iom_write_key(fd, keycode);
			usleep(100);
		}
	}

	fclose(keyuser_fp);
	free(keyuser);
	free(keycode);

	return ret;
}

