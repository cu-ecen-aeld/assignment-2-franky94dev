# Define the default compiler and flags
CROSS_COMPILE ?= 
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Werror -g

# Source files, object files, and the target executable
SRC := writer.c  # Add other source files if needed (e.g., SRC := writer.c anotherfile.c)
OBJ := $(SRC:.c=.o)  # Replace .c with .o to create object files
TARGET := writer

# Default target: build the writer program
all: $(TARGET)

# Rule to build the writer executable from object files
$(TARGET): $(OBJ)
	@echo "Linking $(TARGET)..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
	@echo "Build complete!"

# Rule to compile .c files into .o object files
%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: remove the binary and object files
clean:
	@echo "Cleaning up..."
	rm -f $(TARGET) $(OBJ)

# Cross-compilation rule using aarch64-none-linux-gnu- toolchain
cross-compile: CROSS_COMPILE=aarch64-none-linux-gnu-
cross-compile: clean all

