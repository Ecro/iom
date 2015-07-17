#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "iom.h"

int kbd_fd;

void iom_help(void)
{
	printf("[%s]sudo ./iom [event_num] [read_write]\n", APP_NAME);
	printf("[%s]eg) sudo ./iom 2 r\n", APP_NAME);
	printf("[%s]eg) sudo ./iom 2 w\n", APP_NAME);
}

int iom_deviceInit(char *input_dev)
{	
	kbd_fd = open(input_dev, O_RDWR);
	if(kbd_fd == -1)
	{
		printf("[%s][ERR] fail to open %s\n", APP_NAME, input_dev);
		return IOM_ERROR;
	}

	return IOM_SUCCESS;
}

int iom_deviceClose(void)
{
	close(kbd_fd);

	return IOM_SUCCESS;
}

int main(int argc, char *argv[])
{
	int ret = IOM_SUCCESS;
	char input_dev[64];

	if(argc != 3)
	{
		iom_help();
		exit(0);
	}

	if(getuid() != 0)
	{
		printf("[%s][ERR] should be a root user\n", APP_NAME);
		exit(0);
	}

	sprintf(input_dev, "/dev/input/event%s", argv[1]);

	if(iom_deviceInit(input_dev) !=  0)
		exit(0);

	sleep(1);

	//printf("[%s]Start Job!\n", APP_NAME);

	if(strcmp(argv[2], "r") == 0)
	{
		ret = iom_read(kbd_fd);
		if(ret != IOM_SUCCESS)
		{
			printf("[%s][ERR] iom_read() %d!\n", APP_NAME, ret);
		}
	}
	else if(strcmp(argv[2], "w") == 0)
	{
		ret = iom_write(kbd_fd);
		if(ret != IOM_SUCCESS)
		{
			printf("[%s][ERR] iom_write() %d!\n", APP_NAME, ret);
		}
	}

	if(iom_deviceClose() != IOM_SUCCESS)
		exit(0);
	
	//printf("[%s]End Job!\n", APP_NAME);
	
	return IOM_SUCCESS;
} 

                                   