CC = gcc
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = formatter.o main.o
TARGET = me

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean: 
	rm -rf $(OBJFILES) $(TARGET) *~