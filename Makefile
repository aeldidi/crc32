CFLAGS = -Isrc/ -O0 -std=c99

all: tests/crc32_test_main.o src/crc32.o
	cc tests/crc32_test_main.o src/crc32.o -o test

clean:
	rm -f tests/crc32_test_main.o
	rm -f src/crc32.o
	rm -f test