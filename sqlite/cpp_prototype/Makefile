CXX=g++
cc=gcc

LIB=-lpthread -ldl
BIN=sqlite apiTest
all : $(BIN)
sqlite : sqlite3.c shell.c
	$(cc) -o $@ $^ $(LIB) 
apiTest : database.cpp main.cpp sqlite3.o
	$(CXX) -o $@ $^ $(LIB) 
sqlite3.o : sqlite3.c
	$(cc) -o $@ -c $^
clean :
	rm -f $(BIN)
	rm *.o
.PHONY: all, clean
