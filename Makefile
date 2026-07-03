CC = gcc
CFLAGS = -Wall -Wextra -O2 -I./lib

TARGET = build/main
SRC_TEST = test/main.c

all: $(TARGET)

$(TARGET): $(SRC_TEST)
	@mkdir -p build
	$(CC) $(CFLAGS) $(SRC_TEST) -o $(TARGET)

clean:
	rm -rf build

.PHONY: all clean