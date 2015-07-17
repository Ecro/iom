#include <stdio.h>
#include <linux/input.h>
#include "iom.h"

void iom_convert_keycode_to_keyuser(unsigned int value, unsigned int isPressed, IOM_KeyUser* key)
{
	static unsigned int isShiftPressed = 0;

	switch (value)
	{
		case KEY_LEFTSHIFT :
		case KEY_RIGHTSHIFT :
			if(isPressed == 0)
				isShiftPressed = 0;
			else
				isShiftPressed = 1;
			break;
		case KEY_A :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'A';
				else
					key->keyuser[0] = 'a';
				key->isChanged = 1;
			}
			break;
		case KEY_B :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'B';
				else
					key->keyuser[0] = 'b';
				key->isChanged = 1;
			}
			break;
		case KEY_C :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'C';
				else
					key->keyuser[0] = 'c';
				key->isChanged = 1;
			}
			break;
		case KEY_D :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'D';
				else
					key->keyuser[0] = 'd';
				key->isChanged = 1;
			}
			break;
		case KEY_E :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'E';
				else
					key->keyuser[0] = 'e';
				key->isChanged = 1;
			}
			break;
		case KEY_F :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'F';
				else
					key->keyuser[0] = 'f';
				key->isChanged = 1;
			}
			break;
		case KEY_G :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'G';
				else
					key->keyuser[0] = 'g';
				key->isChanged = 1;
			}
			break;
		case KEY_H :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'H';
				else
					key->keyuser[0] = 'h';
				key->isChanged = 1;
			}
			break;
		case KEY_I :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'I';
				else
					key->keyuser[0] = 'i';
				key->isChanged = 1;
			}
			break;
		case KEY_J :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'J';
				else
					key->keyuser[0] = 'j';
				key->isChanged = 1;
			}
			break;
		case KEY_K :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'K';
				else
					key->keyuser[0] = 'k';
				key->isChanged = 1;
			}
			break;
		case KEY_L :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'L';
				else
					key->keyuser[0] = 'l';
				key->isChanged = 1;
			}
			break;
		case KEY_M :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'M';
				else
					key->keyuser[0] = 'm';
				key->isChanged = 1;
			}
			break;
		case KEY_N :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'N';
				else
					key->keyuser[0] = 'n';
				key->isChanged = 1;
			}
			break;
		case KEY_O :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'O';
				else
					key->keyuser[0] = 'o';
				key->isChanged = 1;
			}
			break;
		case KEY_P :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'P';
				else
					key->keyuser[0] = 'p';
				key->isChanged = 1;
			}
			break;
		case KEY_Q :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'Q';
				else
					key->keyuser[0] = 'q';
				key->isChanged = 1;
			}
			break;
		case KEY_R :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'R';
				else
					key->keyuser[0] = 'r';
				key->isChanged = 1;
			}
			break;
		case KEY_S :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'S';
				else
					key->keyuser[0] = 's';
				key->isChanged = 1;
			}
			break;
		case KEY_T :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'T';
				else
					key->keyuser[0] = 't';
				key->isChanged = 1;
			}
			break;
		case KEY_U :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'U';
				else
					key->keyuser[0] = 'u';
				key->isChanged = 1;
			}
			break;
		case KEY_V :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'V';
				else
					key->keyuser[0] = 'v';
				key->isChanged = 1;
			}
			break;
		case KEY_W :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'W';
				else
					key->keyuser[0] = 'w';
				key->isChanged = 1;
			}
			break;
		case KEY_X :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'X';
				else
					key->keyuser[0] = 'x';
				key->isChanged = 1;
			}
			break;
		case KEY_Y :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'Y';
				else
					key->keyuser[0] = 'y';
				key->isChanged = 1;
			}
			break;
		case KEY_Z :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = 'Z';
				else
					key->keyuser[0] = 'z';
				key->isChanged = 1;
			}
			break;
		case KEY_0 :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = ')';
				else
					key->keyuser[0] = '0';
				key->isChanged = 1;
			}
			break;
		case KEY_1 :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '!';
				else
					key->keyuser[0] = '1';
				key->isChanged = 1;
			}
			break;
		case KEY_2 :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '@';
				else
					key->keyuser[0] = '2';
				key->isChanged = 1;
			}
			break;
		case KEY_3 :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '#';
				else
					key->keyuser[0] = '3';
				key->isChanged = 1;
			}
			break;
		case KEY_4 :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '$';
				else
					key->keyuser[0] = '4';
				key->isChanged = 1;
			}
			break;
		case KEY_5 :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '%';
				else
					key->keyuser[0] = '5';
				key->isChanged = 1;
			}
			break;
		case KEY_6 :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '^';
				else
					key->keyuser[0] = '6';
				key->isChanged = 1;
			}
			break;
		case KEY_7 :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '&';
				else
					key->keyuser[0] = '7';
				key->isChanged = 1;
			}
			break;
		case KEY_8 :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '*';
				else
					key->keyuser[0] = '8';
				key->isChanged = 1;
			}
			break;
		case KEY_9 :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '(';
				else
					key->keyuser[0] = '9';
				key->isChanged = 1;
			}
			break;
		case KEY_MINUS :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '_';
				else
					key->keyuser[0] = '-';
				key->isChanged = 1;
			}
			break;
		case KEY_EQUAL :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '+';
				else
					key->keyuser[0] = '=';
				key->isChanged = 1;
			}
			break;
		case KEY_BACKSPACE :
			if(isPressed == 0)
			{
				key->keyuser[0] = '^';
				key->isChanged = 1;
			}
			break;
		case KEY_ENTER :
			if(isPressed == 0)
			{
				key->keyuser[0] = '\n';
				key->isChanged = 1;
			}
			break;
		case KEY_SPACE :
			if(isPressed == 0)
			{
				key->keyuser[0] = ' ';
				key->isChanged = 1;
			}
			break;
		case KEY_LEFTBRACE :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '{';
				else
					key->keyuser[0] = '[';
				key->isChanged = 1;
			}
			break;
		case KEY_RIGHTBRACE :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '}';
				else
					key->keyuser[0] = ']';
				key->isChanged = 1;
			}
			break;
		case KEY_SEMICOLON :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = ':';
				else
					key->keyuser[0] = ';';
				key->isChanged = 1;
			}
			break;
		case KEY_APOSTROPHE :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '"';
				else
					key->keyuser[0] = '\'';
				key->isChanged = 1;
			}
			break;
		case KEY_BACKSLASH :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '|';
				else
					key->keyuser[0] = '\\';
				key->isChanged = 1;
			}
			break;
		case KEY_COMMA :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '<';
				else
					key->keyuser[0] = ',';
				key->isChanged = 1;
			}
			break;
		case KEY_DOT :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '>';
				else
					key->keyuser[0] = '.';
				key->isChanged = 1;
			}
			break;
		case KEY_SLASH :
			if(isPressed == 0)
			{
				if(isShiftPressed == 1)
					key->keyuser[0] = '?';
				else
					key->keyuser[0] = '/';
				key->isChanged = 1;
			}
			break;
		default :
			break;
	}
}

int iom_read_key(int fd, IOM_KeyCode *key)
{
	struct input_event ev[2];
	int ret = IOM_SUCCESS;

	ret = read(fd, ev, sizeof(struct input_event)*2);
	
	if((ev[0].code==MSC_SCAN) && (ev[0].type==EV_MSC))
	{
		if((ev[1].type==EV_KEY) && (ev[0].value==ev[1].code))
		{
			key->value = ev[1].code;
			key->isPressed = ev[1].value;
			key->time = ev[1].time.tv_sec;
			//printf("[%s][%s]key : %d, isPressed : %d\n", APP_NAME, __FUNCTION__, key->value, key->isPressed);
		}
		else
			return IOM_ERROR;
	}
	else
		return IOM_ERROR;

	return IOM_SUCCESS;
}

int iom_read(int fd)
{
	FILE *keycode_fp, *keyuser_fp;
	IOM_KeyCode *keycode = (IOM_KeyCode *)malloc(sizeof(struct IOM_KeyCode));
	IOM_KeyUser *keyuser = (IOM_KeyCode *)malloc(sizeof(struct IOM_KeyCode));
	char key_char[KEY_CHAR_TOTAL_SIZE];
	
	keycode_fp = fopen(KEY_CODE_FILE_NAME, "w+");
	if(keycode_fp == NULL)
	{
		printf("[%s][ERR] fail to open %s\n", APP_NAME, KEY_CODE_FILE_NAME);
		return IOM_ERROR;
	}

	keyuser_fp = fopen(KEY_USER_FILE_NAME, "w+");
	if(keyuser_fp == NULL)
	{
		fclose(keycode_fp);
		printf("[%s][ERR] fail to open %s\n", APP_NAME, KEY_USER_FILE_NAME);
		return IOM_ERROR;
	}

	while(1)
	{
		if(iom_read_key(fd, keycode) == IOM_SUCCESS)
		{
			if(keycode->value != KEY_F12)
			{
				sprintf(key_char, "[%04d%04d%08d]", keycode->value, keycode->isPressed, keycode->time);
				fwrite(key_char, KEY_CHAR_TOTAL_SIZE, 1, keycode_fp);

				iom_convert_keycode_to_keyuser(keycode->value, keycode->isPressed, keyuser);
				if(keyuser->isChanged != 0)
				{
					sprintf(key_char, "%c", keyuser->keyuser[0]);
					fwrite(key_char, 1, 1, keyuser_fp);
				}
				keyuser->isChanged = 0;
			}
			else
			{
				fclose(keycode_fp);
				fclose(keyuser_fp);
				free(keyuser);
				free(keycode);
				return IOM_SUCCESS;
			}
		}
	}
}
