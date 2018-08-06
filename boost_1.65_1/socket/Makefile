BIN=cli_daytime ser_daytime

CPP_LIB=-lboost_system -lpthread

all:$(BIN)

ser:daytime3_t.cpp
	g++ -o $@ $^ $(CPP_LIB) -g

ser_daytime:daytime2_t.cpp
	g++ -o $@ $^ $(CPP_LIB) -g

cli_daytime:daytime1_t.cpp
	g++ -o $@ $^ $(CPP_LIB) -g

.PHONY:clean
clean:
	-rm -rf $(BIN)
