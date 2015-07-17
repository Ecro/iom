#define APP_NAME "IOM"

#define KEY_CHAR_VALUE_SIZE 4
#define KEY_CHAR_ISPRESSED_SIZE 4
#define KEY_CHAR_TIME_SIZE 8
#define KEY_CHAR_TOTAL_SIZE 18

#define KEY_CODE_FILE_NAME "log/key_code.log"
#define KEY_USER_FILE_NAME "log/key_user.log"

typedef struct IOM_KeyCode
{
	unsigned int value;
	unsigned int isPressed;
	unsigned long time;
} IOM_KeyCode;

typedef struct IOM_KeyUser
{
	char keyuser[1];
	unsigned int isChanged;
} IOM_KeyUser;

typedef enum IOM_Error
{
	IOM_ERROR = -1,
	IOM_SUCCESS = 0
} IOM_Error;
