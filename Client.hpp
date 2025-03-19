#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <string_view>

#include "Server.hpp"

using std::string;
using namespace boost::asio;

class Client {
    string msg;
    io_context ctx;
    ip::udp::socket clientSocket;

   public:
    Client() : msg(""), clientSocket(ctx, Server::SERVER_ENDPOINT) {}

    void send_msg(string& message);
};