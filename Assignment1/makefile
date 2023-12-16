CC = gcc
CFLAGS = -g -ansi -pedantic -Wall -W

# List of source files
SRCS = main.c student.c course.c registration.c

# List of object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = registration_system

# Default target
all: $(EXEC)

# Compile C files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Clean object files and executable
clean:
	rm -f $(OBJS) $(EXEC)
