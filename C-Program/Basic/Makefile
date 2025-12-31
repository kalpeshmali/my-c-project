# Makefile: compile .c sources into obj/<path-to-source>.o and link executable 'main'
# Place this in: /home/kalpesh/Programming/C-Program/Basic/Makefile

CC := gcc
CFLAGS := -g -O0 -std=c11 -Wall -Wextra -I. -Isingle_list -Isupport_files
LDFLAGS :=

TARGET := main
OBJDIR := obj

# Source files (top-level, single_list, support_files)
SRCS := $(wildcard *.c) $(wildcard single_list/*.c) $(wildcard support_files/*.c)

# Map sources to object paths under $(OBJDIR), preserving directories
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

.PHONY: all clean run objects

all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Compile: create the obj subdirectory as needed and compile
# This rule works for top-level and nested source paths (e.g. single_list/SLL_Def.c)
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

# Build only object files (no linking)
objects: $(OBJS)
	@echo "Objects are up-to-date in $(OBJDIR)/"

# Convenience: build and run
run: all
	./$(TARGET)

clean:
	-rm -rf $(OBJDIR) $(TARGET)
	@echo "Cleaned $(OBJDIR) and $(TARGET)"