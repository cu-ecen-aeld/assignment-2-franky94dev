# Compiler and flags
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror -g

# Target binary
TARGET = writer

# Source files
SRCS = writer.c
OBJS = $(SRCS:.c=.o)

# Default target: build the writer application
all: $(TARGET)

# Build the target application
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: remove the binary and object files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean

