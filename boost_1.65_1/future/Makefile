BIN=daytime udp_serv

CPP_LIB=-lboost_system -lpthread

all:$(BIN)

daytime:my_daytime.cpp
	g++ -o $@ $^ $(CPP_LIB) -g

udp_serv:udp_server.cpp
	g++ -o $@ $^ $(CPP_LIB) -g
