CC = gcc
BINS = toggleByte

all: $(BINS)

toggleByte:
	$(CC) src/toggleByte.c -o build/toggleByte.exe
