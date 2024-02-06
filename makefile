CC = gcc
BINS = main clean

all: $(BINS)

toggleBit:
	$(CC) src/toggleBit.c -c -o build/toggleBit.o

main: toggleBit
	$(CC) src/main.c build/toggleBit.o -o build/toggleBit.exe

clean:
	rm -f build/*.o
