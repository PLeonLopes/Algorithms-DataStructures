# .exe name
TARGET = array

# Compiler (gcc) and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

# Source code & objects (.o)
SRCS = main.c list.c search.c sort.c
OBJS = $(SRCS:.c=.o)

# Rules
all: $(TARGET)

# Compile the .exe
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile .o files from .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Force recompilation
rebuild: clean all
