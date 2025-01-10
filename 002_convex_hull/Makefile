# Compiler and Flags
CC = gcc
CFLAGS = -Iinclude       # Include directory for headers
LDFLAGS = -Llib          # Library directory for linking
LIBS = -lmingw32 -lSDL2main -lSDL2

# Directories and Files
SRC_DIR = src
SRC = $(SRC_DIR)/main.c
TARGET = main

# Build Rules
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< $(LIBS)

clean:
	del $(TARGET).exe

