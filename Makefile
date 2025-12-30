# O'zgaruvchilar
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = build/main
SRC = include/main.c

# Default qoida
all: $(TARGET)

# Build papkasini yaratish va dasturni kompilyatsiya qilish
$(TARGET): $(SRC)
	@mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -rf build

# Dasturni ishga tushirish
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
