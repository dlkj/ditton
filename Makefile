AS = i586-elf-as
RM = rm -f

OBJECTS = $(patsubst %.s, %.o, $(wildcard *.s))

.PHONY: clean

all: $(OBJECTS)

%.o: %.s
	$(AS) $< -o $@

clean:
	$(RM) $(OBJECTS)