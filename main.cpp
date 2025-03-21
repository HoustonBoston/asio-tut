#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <string_view>

#include "Peer.hpp"
#include "Server.hpp"
#include "Client.hpp"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

const boost::asio::ip::udp::endpoint SERVER_ENDPOINT(
    boost::asio::ip::address::from_string("127.0.0.1"), 5000);

// void Server() {
//     using namespace boost::asio;

//     io_context ctx;

//     ip::udp::socket serverSocket(ctx, SERVER_ENDPOINT);

//     char data[1024];
//     serverSocket.async_receive(
//         boost::asio::buffer(data, 1024),
//         [&](std::error_code ec, size_t bytes_received) {
//             if (!ec && bytes_received > 0) {
//                 cout << "RCV: " << std::string_view(data, bytes_received)
//                      << endl;

//             } else {
//                 cout << "ERROR, BYTES: " << bytes_received << ec.message()
//                      << endl;
//             }
//         });

//     ctx.run();
// }

// void Client() {
//     using namespace boost::asio;

//     io_context ctx;

//     ip::udp::socket clientSocket(ctx, ip::udp::endpoint(ip::udp::v4(), 0));

//     string message("I love Daly\n");
//     clientSocket.async_send_to(
//         boost::asio::buffer(message.data(), message.size()), SERVER_ENDPOINT,
//         [](std::error_code ec, size_t sent_bytes) {
//             if (!ec && sent_bytes > 0) {
//                 cout << sent_bytes << " bytes sent successfully!\n";
//             } else {
//                 cout << "ERROR, BYTES: " << sent_bytes << ec.message() <<
//                 endl;
//             }
//         });

//     ctx.run();
// }

int main(int argc, char* argv[]) {
    if (argv[1] == "S"){
        Server s;
        while (true){
            s.serve();
        }
    }
    else if (argv[1] == "C"){
        // while window is open stuff happens
        Client c;
        c.send_msg();
    }

    return 0;

    // boost::asio::thread_pool thread_pool(2);
    // boost::asio::io_context io_context;
    // boost::asio::ip::address game(
    //     boost::asio::ip::make_address(argv[1] ? argv[1] : "127.0.0.1"));
    // Peer peer(io_context, game);

    // boost::asio::post(thread_pool, [&] {
    //     peer.do_receive();
    //     io_context.run();
    // });

    // boost::asio::post(thread_pool, [&] {
    //     peer.do_send();
    //     io_context.run();
    // });

    // thread_pool.join();

    // cout << "joined threads\n";
}
