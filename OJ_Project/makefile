LDFLAGS= -L /home/heqing/code/Linux_base/OJ_Project/ThirdPartLibForCpp/el7.x86_64/third_part/lib
DEBUGFLAGS=-g
BIN=oj_server
CC=g++

.PHONY:$(BIN)
$(BIN):oj_server.cpp
	$(CC) $^ -o $@ $(DEBUGFLAGS) $(LDFLAGS) -lctemplate -ljsoncpp -lpthread

.PHONY:clean
clean:
	rm -f $(BIN)


