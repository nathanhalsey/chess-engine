CC=gcc
CFLAGS =-Wall -w
OBJFILES = board.o attacks.o debug_board.o main.o
TARGET = denise

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES)
