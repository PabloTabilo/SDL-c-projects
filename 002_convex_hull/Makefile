###############################################################################
# Compiler & Flags
###############################################################################
CC      := gcc
CFLAGS  := -Iinclude
LDFLAGS := -Llib
LIBS    := -lmingw32 -lSDL2main -lSDL2

###############################################################################
# Directories
###############################################################################
SRC_DIR  := src
TEST_DIR := src/tests
OBJ_DIR  := build/obj
BIN_DIR  := build/bin

###############################################################################
# 1) List out only "library" (non-test, non-main) sources here
#    Do NOT include src/main.c
###############################################################################
SRC := \
  $(wildcard $(SRC_DIR)/algorithms/*.c) \
  $(wildcard $(SRC_DIR)/data-structure/*.c) \
  $(wildcard $(SRC_DIR)/geometry/*.c) \
  $(wildcard $(SRC_DIR)/init/*.c)

# Convert each .c -> .o (e.g. src/algorithms/foo.c -> build/obj/algorithms/foo.o)
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

###############################################################################
# 2) Keep main.c separate so it doesn't get pulled into test builds
###############################################################################
MAIN_SRC := $(SRC_DIR)/main.c
MAIN_OBJ := $(OBJ_DIR)/main.o

###############################################################################
# Main executable name
###############################################################################
TARGET := main

###############################################################################
# Test sources & outputs (each test_*.c has its own main)
###############################################################################
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_BIN := $(patsubst $(TEST_DIR)/%.c,$(BIN_DIR)/test_%,$(TEST_SRC))

###############################################################################
# Phony targets
###############################################################################
.PHONY: all tests clean

###############################################################################
# Default build: main app (no tests)
###############################################################################
all: $(BIN_DIR)/$(TARGET)

# Link library objects + main.o into one .exe
$(BIN_DIR)/$(TARGET): $(OBJ) $(MAIN_OBJ)
	if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

###############################################################################
# Compile library code .c -> .o
###############################################################################
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) $(CFLAGS) -c $< -o $@

###############################################################################
# Compile main.c -> main.o (kept separate)
###############################################################################
$(MAIN_OBJ): $(MAIN_SRC)
	if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) $(CFLAGS) -c $< -o $@

###############################################################################
# Build separate test executables (each test_* has its own main)
# We link them with OBJ but *not* main.o
###############################################################################
tests: $(TEST_BIN)

$(BIN_DIR)/test_%: $(TEST_DIR)/%.c $(OBJ)
	if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

###############################################################################
# Clean up (Windows)
###############################################################################
clean:
	-del /S /Q $(OBJ_DIR)\*.o 2>NUL
	-del /Q $(BIN_DIR)\$(TARGET).exe 2>NUL
	-del /Q $(BIN_DIR)\test_*.exe 2>NUL

