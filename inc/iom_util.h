
#define IOM_CONTROL_KEY_STRING_LEFTSHIFT 	"<LSHT "
#define IOM_CONTROL_KEY_STRING_RIGHTSHIFT 	"<RSHT "
#define IOM_CONTROL_KEY_STRING_LEFTCTRL 	"<LCTL "
#define IOM_CONTROL_KEY_STRING_RIGHTCTRL 	"<RCTL "
#define IOM_CONTROL_KEY_STRING_LEFTALT 		"<LALT "
#define IOM_CONTROL_KEY_STRING_RIGHTALT 	"<RALT "
#define IOM_CONTROL_KEY_STRING_BACKSPACE 	"<BSPA>"
#define IOM_CONTROL_KEY_STRING_TAB			"<TAB@>"
#define IOM_CONTROL_KEY_STRING_ESC		 	"<ESC@>"
#define IOM_CONTROL_KEY_STRING_PAGEUP	 	"<PGUP>"
#define IOM_CONTROL_KEY_STRING_PAGEDOWN 	"<PGDN>"
#define IOM_CONTROL_KEY_STRING_HOME 		"<HOME>"
#define IOM_CONTROL_KEY_STRING_END 			"<END@>"
#define IOM_CONTROL_KEY_STRING_UP 			"<UP@@>"
#define IOM_CONTROL_KEY_STRING_DOWN		 	"<DOWN>"
#define IOM_CONTROL_KEY_STRING_LEFT		 	"<LEFT>"
#define IOM_CONTROL_KEY_STRING_RIGHT		"<RGHT>"
#define IOM_CONTROL_KEY_STRING_INSERT		"<INS@>"
#define IOM_CONTROL_KEY_STRING_DELETE		"<DEL@>"
#define IOM_CONTROL_KEY_STRING_F1			"<F1@@>"
#define IOM_CONTROL_KEY_STRING_F2			"<F2@@>"
#define IOM_CONTROL_KEY_STRING_F3			"<F3@@>"
#define IOM_CONTROL_KEY_STRING_F4			"<F4@@>"
#define IOM_CONTROL_KEY_STRING_F5			"<F5@@>"
#define IOM_CONTROL_KEY_STRING_F6			"<F6@@>"
#define IOM_CONTROL_KEY_STRING_F7			"<F7@@>"
#define IOM_CONTROL_KEY_STRING_F8			"<F8@@>"
#define IOM_CONTROL_KEY_STRING_F9			"<F9@@>"
#define IOM_CONTROL_KEY_STRING_F10			"<F10@>"
#define IOM_CONTROL_KEY_STRING_F11			"<F11@>"
#define IOM_CONTROL_KEY_STRING_F12			"<F12@>"

typedef struct IOM_ControlWord
{
	unsigned int delay_seconds;
} IOM_ControlWord;

IOM_Error iom_check_control_word(IOM_KeyUser* keyUser, IOM_ControlWord* cw);
IOM_Error iom_convert_keyuser_to_keycode(IOM_KeyUser* keyUser, IOM_KeyCode* keyCode);
IOM_Error iom_convert_keycode_to_keyuser(IOM_KeyCode *keyCode, IOM_KeyUser* keyUser);
