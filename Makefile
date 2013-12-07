AS = i586-elf-as
RM = rm -f

OBJECTS = $(patsubst %.s, %.o, $(wildcard *.s))

.PHONY: clean

all: $(OBJECTS)

clean:
	$(RM) $(OBJECTS)