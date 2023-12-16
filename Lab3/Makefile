CC = gcc
CFLAGS = -Wall -ansi -pedantic
LDFLAGS =

SOURCES = Lab3.c printArray.c reverseArray.c randomizeArray.c sortArray.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = Lab3

files: $(EXECUTABLE)

DEPS := $(OBJECTS:.o=.d)
-include $(DEPS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

.PHONY: files clean
