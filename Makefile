CC=gcc
CFLAGS=-W -Wall
LDFLAGS=
OBJECTS=proj3B.o proj3B_deque.o
TARGET = proj3B

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET) *~

