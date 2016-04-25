TARGET = play

CC = g++
SRCS = play.cc
INC = -I$(HOME)/leveldb/include
LIB = -L$(HOME)/leveldb/out-static
CFLAGS = -std=c++11 -Wall $(INC) 

OBJS_DIR = build/
OBJS = $(SRCS:.cc=.o)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIB) -lleveldb -pthread

%.o: %.cc
	$(CC) $(CFLAGS) -o $@ -c $< 

.PHONY: clean

clean:
	-rm -rf $(TARGET) $(OBJS)