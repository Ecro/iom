CC = gcc
OBJS = iom_main.o iom_write.o iom_read.o iom_util.o
TARGET = eiom

BUILD_DIR := $(shell pwd)
SRC_DIR := $(BUILD_DIR)/src
INC_DIR := $(BUILD_DIR)/inc
BIN_DIR := /usr/local/iom/bin

CFLAGS = -I$(INC_DIR) -I$(SRC_DIR)

vpath %.c $(SRC_DIR)

all : $(TARGET)

$(TARGET) : $(BIN_DIR) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $(addprefix $(BIN_DIR)/, $(OBJS))

$(OBJS) : %.o:%.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ -c $<

$(BIN_DIR) :
	@mkdir -p $(BIN_DIR)

clean :
	@rm -rf $(BIN_DIR)
