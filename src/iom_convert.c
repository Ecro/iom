#include <stdio.h>
#include <linux/input.h>
#include "iom.h"
#include "iom_convert.h"

IOM_Error iom_convert_keyuserchar_to_keycode(char keyuser_char, IOM_KeyCode* keyCode)
{
	switch (keyuser_char)
	{
		case 'A' :
			keyCode->value = KEY_A;
			keyCode->isShiftPressed = 1;
			break;
		case 'a' :
			keyCode->value = KEY_A;
			keyCode->isShiftPressed = 0;
			break;
		default :
			return IOM_ERROR;		
	}

	return IOM_SUCCESS;
}

IOM_Error iom_convert_keycode_to_keyuser(IOM_KeyCode *keyCode, IOM_KeyUser* keyUser)
{
	static unsigned int isShiftPressed = 0;

	if((keyCode->isPressed == 0) && (keyCode->value!=KEY_LEFTSHIFT && keyCode->value!=KEY_RIGHTSHIFT))
		keyUser->isChanged = 1;
	else
		keyUser->isChanged = 0;
	
	switch (keyCode->value)
	{
		case KEY_LEFTSHIFT :
		case KEY_RIGHTSHIFT :
			if(keyCode->isPressed == 0)
				isShiftPressed = 0;
			else
				isShiftPressed = 1;
			break;
		case KEY_A :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'A';
				else
					keyUser->key = 'a';
			}
			break;
		case KEY_B :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'B';
				else
					keyUser->key = 'b';
			}
			break;
		case KEY_C :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'C';
				else
					keyUser->key = 'c';
			}
			break;
		case KEY_D :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'D';
				else
					keyUser->key = 'd';
			}
			break;
		case KEY_E :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'E';
				else
					keyUser->key = 'e';
			}
			break;
		case KEY_F :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'F';
				else
					keyUser->key = 'f';
			}
			break;
		case KEY_G :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'G';
				else
					keyUser->key = 'g';
			}
			break;
		case KEY_H :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'H';
				else
					keyUser->key = 'h';
			}
			break;
		case KEY_I :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'I';
				else
					keyUser->key = 'i';
			}
			break;
		case KEY_J :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'J';
				else
					keyUser->key = 'j';
			}
			break;
		case KEY_K :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'K';
				else
					keyUser->key = 'k';
			}
			break;
		case KEY_L :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'L';
				else
					keyUser->key = 'l';
			}
			break;
		case KEY_M :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'M';
				else
					keyUser->key = 'm';
			}
			break;
		case KEY_N :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'N';
				else
					keyUser->key = 'n';
			}
			break;
		case KEY_O :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'O';
				else
					keyUser->key = 'o';
			}
			break;
		case KEY_P :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'P';
				else
					keyUser->key = 'p';
			}
			break;
		case KEY_Q :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'Q';
				else
					keyUser->key = 'q';
			}
			break;
		case KEY_R :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'R';
				else
					keyUser->key = 'r';
			}
			break;
		case KEY_S :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'S';
				else
					keyUser->key = 's';
			}
			break;
		case KEY_T :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'T';
				else
					keyUser->key = 't';
			}
			break;
		case KEY_U :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'U';
				else
					keyUser->key = 'u';
			}
			break;
		case KEY_V :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'V';
				else
					keyUser->key = 'v';
			}
			break;
		case KEY_W :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'W';
				else
					keyUser->key = 'w';
			}
			break;
		case KEY_X :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'X';
				else
					keyUser->key = 'x';
			}
			break;
		case KEY_Y :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'Y';
				else
					keyUser->key = 'y';
			}
			break;
		case KEY_Z :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = 'Z';
				else
					keyUser->key = 'z';
			}
			break;
		case KEY_0 :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = ')';
				else
					keyUser->key = '0';
			}
			break;
		case KEY_1 :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '!';
				else
					keyUser->key = '1';
			}
			break;
		case KEY_2 :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '@';
				else
					keyUser->key = '2';
			}
			break;
		case KEY_3 :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '#';
				else
					keyUser->key = '3';
			}
			break;
		case KEY_4 :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '$';
				else
					keyUser->key = '4';
			}
			break;
		case KEY_5 :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '%';
				else
					keyUser->key = '5';
			}
			break;
		case KEY_6 :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '^';
				else
					keyUser->key = '6';
			}
			break;
		case KEY_7 :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '&';
				else
					keyUser->key = '7';
			}
			break;
		case KEY_8 :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '*';
				else
					keyUser->key = '8';
			}
			break;
		case KEY_9 :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '(';
				else
					keyUser->key = '9';
			}
			break;
		case KEY_MINUS :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '_';
				else
					keyUser->key = '-';
			}
			break;
		case KEY_EQUAL :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '+';
				else
					keyUser->key = '=';
			}
			break;
		case KEY_BACKSPACE :
			if(keyCode->isPressed == 0)
			{
				keyUser->key = '^';
			}
			break;
		case KEY_ENTER :
			if(keyCode->isPressed == 0)
			{
				keyUser->key = '\n';
			}
			break;
		case KEY_SPACE :
			if(keyCode->isPressed == 0)
			{
				keyUser->key = ' ';
			}
			break;
		case KEY_LEFTBRACE :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '{';
				else
					keyUser->key = '[';
			}
			break;
		case KEY_RIGHTBRACE :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '}';
				else
					keyUser->key = ']';
			}
			break;
		case KEY_SEMICOLON :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = ':';
				else
					keyUser->key = ';';
			}
			break;
		case KEY_APOSTROPHE :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '"';
				else
					keyUser->key = '\'';
			}
			break;
		case KEY_BACKSLASH :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '|';
				else
					keyUser->key = '\\';
			}
			break;
		case KEY_COMMA :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '<';
				else
					keyUser->key = ',';
			}
			break;
		case KEY_DOT :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '>';
				else
					keyUser->key = '.';
			}
			break;
		case KEY_SLASH :
			if(keyCode->isPressed == 0)
			{
				if(isShiftPressed == 1)
					keyUser->key = '?';
				else
					keyUser->key = '/';
			}
			break;
		default :
			return IOM_ERROR;
	}
	return IOM_SUCCESS;
}
