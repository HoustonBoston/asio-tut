#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <string_view>

using namespace boost::asio;

class Server {
    char rcv_data[1024];
    io_context ctx;
    ip::udp::socket serverSocket;

   public:
    static boost::asio::ip::udp::endpoint SERVER_ENDPOINT;

    Server()
        : rcv_data(""), serverSocket(ctx, SERVER_ENDPOINT) {}

    void serve();
};