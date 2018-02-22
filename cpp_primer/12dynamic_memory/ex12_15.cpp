#include <iostream>
#include <string>
#include <memory>

struct Connection {
    std::string ip;
    int port;
    Connection(std::string ip, int port) : ip(ip), port(port) { }
};

struct Destination {
    std::string ip;
    int port;
    Destination(std::string ip, int port) : ip(ip), port(port) { }
};

Connection Connect(Destination *dest) {
    std::shared_ptr<Connection> conn(new Connection(dest->ip, dest->port));
    std::cout << "creating connection(" << conn.use_count() << ")" << '\n';

    return *conn;
}

void Disconnect(Connection conn) {
    std::cout << "connection close("
              << conn.ip << ":" << conn.port << ")" << '\n';
}

void F(Destination &dest) {
    Connection conn = Connect(&dest);
    std::shared_ptr<Connection> ptr(&conn, [](Connection *conn) {
        Disconnect(*conn);
    });

    std::cout << "Connecting now(" << ptr.use_count() << ")" << '\n';
}

int main() {

    Destination dest("192.169.1.2", 6666);
    F(dest);

    return 0;
}
