#include "Server.hpp"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

ip::udp::endpoint Server::SERVER_ENDPOINT(
    boost::asio::ip::address::from_string("127.0.0.1"), 5000);

void Server::serve() {
    serverSocket.async_receive(
        boost::asio::buffer(rcv_data, 1024),
        [&](std::error_code ec, size_t bytes_received) {
            if (!ec && bytes_received > 0) {
                cout << "RCV: " << std::string_view(rcv_data, bytes_received)
                     << endl;

            } else {
                cout << "ERROR, BYTES: " << bytes_received << ec.message()
                     << endl;
            }
        });

    ctx.run();
}