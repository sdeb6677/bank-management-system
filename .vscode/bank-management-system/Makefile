CC = g++
CFLAGS = -Iinclude -Wall
SRC = src/account.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = bank_management_system

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)