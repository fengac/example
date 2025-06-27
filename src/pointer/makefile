# 编译器
CC = gcc
# 编译选项
CFLAGS = -Wall -g
# 源文件
SRCS = exercise1.c
# 目标文件
OBJS = $(SRCS:.c=.o)
# 可执行文件
TARGET = a.out

# 默认目标，编译项目
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 编译源文件生成目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理编译生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

# 伪目标，防止与同名文件冲突
.PHONY: all clean