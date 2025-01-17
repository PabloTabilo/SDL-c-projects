# Compiler and Flags
CC = gcc
CFLAGS = -Iinclude       # Include directory for headers
LDFLAGS = -Llib          # Library directory for linking
LIBS = -lmingw32 -lSDL2main -lSDL2

# Directories and Files
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)               # Replace .c with .o for object files
TARGET = main

# Build Rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	del $(TARGET).exe

