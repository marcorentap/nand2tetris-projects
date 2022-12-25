CC = g++
CFLAGS = -Wall

all: main.o Parser.o CodeWriter.o
	$(CC) $(CFLAGS) -o main $^

clean:
	rm -f *.o main
