#include "Client.hpp"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

void Client::send_msg(string& message) {
    msg = message;

    clientSocket.async_send_to(
        boost::asio::buffer(message.data(), message.size()),
        Server::SERVER_ENDPOINT, [](std::error_code ec, size_t sent_bytes) {
            if (!ec && sent_bytes > 0) {
                cout << sent_bytes << " bytes sent successfully!\n";
            } else {
                cout << "ERROR, BYTES: " << sent_bytes << ec.message() << endl;
            }
        });

    ctx.run();
}