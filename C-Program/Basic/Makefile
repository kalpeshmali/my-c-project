# Makefile: compile .c sources into obj/<path-to-source>.o and link executable 'main'
# Place this in: E:\Project\my-c-project\C-Program\Basic\Makefile

CC := gcc
CFLAGS := -g -O0 -std=c11 -Wall -Wextra -I. -Isingle_list -Isupport_files -Icircular_s_list -Idouble_list -Icircular_d_list
LDFLAGS :=

TARGET := cApp
OBJDIR := obj

# Source files (top-level, single_list, support_files)
SRCS := $(wildcard *.c) $(wildcard single_list/*.c) $(wildcard support_files/*.c) $(wildcard circular_s_list/*.c) $(wildcard double_list/*.c) $(wildcard circular_d_list/*.c)

# Map sources to object paths under $(OBJDIR), preserving directories
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

.PHONY: all clean run objects

all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Compile: create the obj subdirectory as needed and compile
$(OBJDIR)/%.o: %.c
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) $(CFLAGS) -c -o $@ $<

# Build only object files (no linking)
objects: $(OBJS)
	@echo "Objects are up-to-date in $(OBJDIR)/"

# Convenience: build and run
run: all
	./$(TARGET)

clean:
	-rd /s /q "$(OBJDIR)" 2> nul
	-del /q "$(TARGET).exe" "$(TARGET)" 2> nul
	@echo Cleaned $(OBJDIR) and $(TARGET)