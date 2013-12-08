AS := i586-elf-as
CC := i586-elf-gcc
CXX := i586-elf-g++

CPPFLAGS := -g -ffreestanding -O2 -Wall -Wextra
LDFLAGS := -nostdlib -lgcc

RM := rm -f

TARGET := ditton.bin

OBJECTS := $(patsubst %.s, %.o, $(wildcard *.s)) $(patsubst %.cpp, %.o, $(wildcard *.cpp))

.PHONY: clean

all: $(TARGET)

$(TARGET): linker.ld $(OBJECTS)
	$(CXX) -T linker.ld -o $@ $(CPPFLAGS) $(LDFLAGS) $(OBJECTS)
clean:
	$(RM) $(TARGET) $(OBJECTS)