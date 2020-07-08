# MAKEFILE FOR MEDIAN FILTER EXAMPLE
# Author: Michael Wrona | GitHub: michaelwro

CC = g++
CFLAGS = -std=c++11 -Wall -Werror

# make command
all: medainFiltExample


# Compile and execute program
run: medainFiltExample
	./$<


# Compile main.cpp and other objects
medainFiltExample: main.cpp MedianFilter.o
	$(CC) $^ $(CFLAGS) -I /usr/include/python2.7 -lpython2.7 -o $@


# Compile .o files
%.o: %.cpp 
	$(CC) $(CFLAGS) -c $<


# Clean .o files and executable file
clean:
	rm -rf *.o medainFiltExample

