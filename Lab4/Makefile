CC = gcc
CFLAGS = -g -ansi -pedantic -Wall

# List header files associated with each source file
TEMP_HEADERS = temp.h
WINDSPEED_HEADERS = windspeed.h
WINDGUSTS_HEADERS = windgusts.h

# Targets
all: main

main: main.o temp.o windspeed.o windgusts.o
	$(CC) $(CFLAGS) -o main main.o temp.o windspeed.o windgusts.o 

main.o: main.c $(TEMP_HEADERS) $(WINDSPEED_HEADERS) $(WINDGUSTS_HEADERS)
	$(CC) $(CFLAGS) -c main.c

temp.o: temp.c $(TEMP_HEADERS)
	$(CC) $(CFLAGS) -c temp.c

windspeed.o: windspeed.c $(WINDSPEED_HEADERS)
	$(CC) $(CFLAGS) -c windspeed.c

windgusts.o: windgusts.c $(WINDGUSTS_HEADERS)
	$(CC) $(CFLAGS) -c windgusts.c

clean:
	rm -f main *.o
