#define APP_NAME "IOM"

#define KEY_CHAR_VALUE_SIZE 4
#define KEY_CHAR_ISPRESSED_SIZE 4
#define KEY_CHAR_TIME_SIZE 12
#define KEY_CHAR_TOTAL_SIZE 20

#define KEY_CODE_FILE_NAME "key_code.log"
#define KEY_USER_FILE_NAME "key_user.log"
#define KEY_USER_MAX_CHAR 6

typedef enum IOM_Error
{
	IOM_ERROR = -1,
	IOM_SUCCESS = 0
} IOM_Error;

typedef enum IOM_Key_Type
{
	IOM_KEY_NORMAL = 0,
	IOM_KEY_CONTROL
} IOM_Key_Type;

typedef struct IOM_KeyCode
{
	unsigned int value;
	unsigned int isPressed;
	unsigned long time;
} IOM_KeyCode;

typedef struct IOM_KeyUser
{
	char key[KEY_USER_MAX_CHAR];
	int isChanged;
} IOM_KeyUser;

