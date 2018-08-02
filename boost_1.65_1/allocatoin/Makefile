BIN=allocation

CPP_LIB=-lboost_system -lpthread

all:$(BIN)

allocation:allocation.cpp
	g++ -o $@ $^ $(CPP_LIB) -g

.PHONY:clean
clean:
	-rm -rf $(BIN)
