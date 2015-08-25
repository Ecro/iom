#include <stdio.h>
#include <linux/input.h>
#include "iom.h"
#include "iom_util.h"

IOM_Error iom_check_control_word(IOM_KeyUser* keyUser, IOM_ControlWord* cw)
{
	if(keyUser->key[0] == '<' && keyUser->key[1] == 'D' && (keyUser->key[2] >= '0' && keyUser->key[2] <= '9'))
	{
		cw->delay_seconds = atoi(&keyUser->key[2]);
		//printf("delay %d\n", cw->delay_seconds);
		return IOM_DELAY;
	}
	else
		return IOM_SUCCESS;
}

unsigned int iom_convert_keyuser_control(IOM_KeyUser* keyUser)
{
	if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_LEFTSHIFT, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_LEFTSHIFT;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_RIGHTSHIFT, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_RIGHTSHIFT;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_LEFTCTRL, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_LEFTCTRL;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_RIGHTCTRL, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_RIGHTCTRL;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_LEFTALT, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_LEFTALT;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_RIGHTALT, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_RIGHTALT;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_BACKSPACE, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_BACKSPACE;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_TAB, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_TAB;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_ESC, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_ESC;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_PAGEUP, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_PAGEUP;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_PAGEDOWN, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_PAGEDOWN;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_HOME, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_HOME;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_END, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_END;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_UP, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_UP;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_DOWN, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_DOWN;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_LEFT, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_LEFT;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_RIGHT, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_RIGHT;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_INSERT, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_INSERT;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_DELETE, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_DELETE;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_F1, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_F1;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_F2, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_F2;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_F3, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_F3;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_F4, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_F4;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_F5, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_F5;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_F6, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_F6;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_F7, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_F7;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_F8, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_F8;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_F9, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_F9;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_F10, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_F10;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_F11, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_F11;
	else if(strncmp(keyUser->key, IOM_CONTROL_KEY_STRING_F12, KEY_USER_MAX_CHAR-1) == 0)
		return KEY_F12;
	//else
		//printf("[%s][ERR] unexpected control key!\n", APP_NAME);
		
	return 0;
}

IOM_Error iom_convert_keyuser_to_keycode(IOM_KeyUser* keyUser, IOM_KeyCode* keyCode)
{
	static int last_controlKeyValue = KEY_RESERVED;

	switch (keyUser->key[0])
	{
		case '<' :
			keyCode->value = iom_convert_keyuser_control(keyUser);
			if(keyCode->value == KEY_LEFTSHIFT || keyCode->value == KEY_RIGHTSHIFT || \
				keyCode->value == KEY_LEFTCTRL || keyCode->value == KEY_RIGHTCTRL || \
				keyCode->value == KEY_LEFTALT || keyCode->value == KEY_RIGHTALT)
			{
				last_controlKeyValue = keyCode->value;
				keyCode->isPressed = 1;
			}
			else
			{
				keyCode->isPressed = 0;
			}
			break;
		case '>' :
			//if(last_controlKeyValue == KEY_RESERVED)
			//{
			//	printf("[%s][ERR] last control key is not exist!\n", APP_NAME);
			//}
			if(last_controlKeyValue != KEY_RESERVED)
			{
				keyCode->value = last_controlKeyValue;
				keyCode->isPressed = 0;
				last_controlKeyValue = KEY_RESERVED;
			}
			break;
		case 'a' :
			keyCode->value = KEY_A;
			break;
		case 'b' :
			keyCode->value = KEY_B;
			break;
		case 'c' :
			keyCode->value = KEY_C;
			break;
		case 'd' :
			keyCode->value = KEY_D;
			break;
		case 'e' :
			keyCode->value = KEY_E;
			break;
		case 'f' :
			keyCode->value = KEY_F;
			break;
		case 'g' :
			keyCode->value = KEY_G;
			break;
		case 'h' :
			keyCode->value = KEY_H;
			break;
		case 'i' :
			keyCode->value = KEY_I;
			break;
		case 'j' :
			keyCode->value = KEY_J;
			break;
		case 'k' :
			keyCode->value = KEY_K;
			break;
		case 'l' :
			keyCode->value = KEY_L;
			break;
		case 'm' :
			keyCode->value = KEY_M;
			break;
		case 'n' :
			keyCode->value = KEY_N;
			break;
		case 'o' :
			keyCode->value = KEY_O;
			break;
		case 'p' :
			keyCode->value = KEY_P;
			break;
		case 'q' :
			keyCode->value = KEY_Q;
			break;
		case 'r' :
			keyCode->value = KEY_R;
			break;
		case 's' :
			keyCode->value = KEY_S;
			break;
		case 't' :
			keyCode->value = KEY_T;
			break;
		case 'u' :
			keyCode->value = KEY_U;
			break;
		case 'v' :
			keyCode->value = KEY_V;
			break;
		case 'w' :
			keyCode->value = KEY_W;
			break;
		case 'x' :
			keyCode->value = KEY_X;
			break;
		case 'y' :
			keyCode->value = KEY_Y;
			break;
		case 'z' :
			keyCode->value = KEY_Z;
			break;
		case '1' :
			keyCode->value = KEY_1;
			break;
		case '2' :
			keyCode->value = KEY_2;
			break;
		case '3' :
			keyCode->value = KEY_3;
			break;
		case '4' :
			keyCode->value = KEY_4;
			break;
		case '5' :
			keyCode->value = KEY_5;
			break;
		case '6' :
			keyCode->value = KEY_6;
			break;
		case '7' :
			keyCode->value = KEY_7;
			break;
		case '8' :
			keyCode->value = KEY_8;
			break;
		case '9' :
			keyCode->value = KEY_9;
			break;
		case '0' :
			keyCode->value = KEY_0;
			break;
		case ' ' :
			keyCode->value = KEY_SPACE;
			break;
		case '[' :
			keyCode->value = KEY_LEFTBRACE;
			break;
		case ']' :
			keyCode->value = KEY_RIGHTBRACE;
			break;
		case ';' :
			keyCode->value = KEY_SEMICOLON;
			break;
		case '\'' :
			keyCode->value = KEY_APOSTROPHE;
			break;
		case '\\' :
			keyCode->value = KEY_BACKSLASH;
			break;
		case ',' :
			keyCode->value = KEY_COMMA;
			break;
		case '.' :
			keyCode->value = KEY_DOT;
			break;
		case '/' :
			keyCode->value = KEY_SLASH;
			break;
		case '\n' :
			keyCode->value = KEY_ENTER;
			break;
		default :
			return IOM_ERROR;		
	}

	return IOM_SUCCESS;
}

IOM_Error iom_convert_keycode_to_keyuser(IOM_KeyCode *keyCode, IOM_KeyUser* keyUser)
{
	keyUser->isChanged = 1;
	int i;

	switch (keyCode->value)
	{
		case KEY_LEFTSHIFT :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_LEFTSHIFT, KEY_USER_MAX_CHAR);	
			}
			else
			{
				keyUser->key[0] = '>';
			}
			break;
		case KEY_RIGHTSHIFT :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_RIGHTSHIFT, KEY_USER_MAX_CHAR);
			}
			else if(keyCode->isPressed == 0)
			{
				keyUser->key[0] = '>';
			}
			break;
		case KEY_LEFTCTRL :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_LEFTCTRL, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->key[0] = '>';
			}
			break;
		case KEY_RIGHTCTRL :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_RIGHTCTRL, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->key[0] = '>';
			}
			break;
		case KEY_LEFTALT :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_LEFTALT, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->key[0] = '>';
			}
			break;
		case KEY_RIGHTALT :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_RIGHTALT, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->key[0] = '>';
			}
			break;
		case KEY_BACKSPACE :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_BACKSPACE, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_TAB :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_TAB, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_ESC :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_ESC, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_PAGEUP :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_PAGEUP, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_PAGEDOWN :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_PAGEDOWN, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_HOME :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_HOME, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_END :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_END, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_UP :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_UP, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_DOWN :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_DOWN, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_LEFT :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_LEFT, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_RIGHT :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_RIGHT, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_INSERT :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_INSERT, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_DELETE :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_DELETE, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_F1 :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_F1, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_F2 :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_F2, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_F3 :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_F3, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_F4 :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_F4, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_F5:
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_F5, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_F6 :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_F6, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_F7 :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_F7, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_F8 :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_F8, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_F9 :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_F9, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_F10 :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_F10, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_F11 :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_F11, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_F12 :
			if(keyCode->isPressed == 1)
			{
				memcpy(keyUser->key, IOM_CONTROL_KEY_STRING_F12, KEY_USER_MAX_CHAR);
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_A :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'a';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_B :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'b';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_C :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'c';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_D :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'd';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_E :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'e';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_F :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'f';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_G :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'g';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_H :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'h';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_I :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'i';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_J :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'j';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_K :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'k';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_L :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'l';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_M :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'm';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_N :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'n';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_O :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'o';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_P :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'p';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_Q :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'q';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_R :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'r';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_S :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 's';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_T :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 't';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_U :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'u';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_V :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'v';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_W :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'w';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_X :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'x';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_Y :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'y';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_Z :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = 'z';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_0 :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '0';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_1 :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '1';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_2 :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '2';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_3 :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '3';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_4 :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '4';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_5 :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '5';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_6 :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '6';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_7 :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '7';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_8 :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '8';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_9 :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '9';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_MINUS :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '-';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_EQUAL :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '=';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_ENTER :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '\n';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_SPACE :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = ' ';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_LEFTBRACE :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '[';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_RIGHTBRACE :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = ']';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_SEMICOLON :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = ';';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_APOSTROPHE :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '\'';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_BACKSLASH :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '\\';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_COMMA :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = ',';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_DOT :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '.';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		case KEY_SLASH :
			if(keyCode->isPressed == 1)
			{
				keyUser->key[0] = '/';
			}
			else
			{
				keyUser->isChanged = 0;
			}
			break;
		default :
			return IOM_ERROR;
	}
	return IOM_SUCCESS;
}
