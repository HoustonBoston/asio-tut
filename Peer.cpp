#include "Peer.hpp"

#include <SFML/Graphics.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <string_view>

constexpr uint16_t port = 5000;

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

Peer::Peer(boost::asio::io_context& io_context,
           const boost::asio::ip::address& address)
    : _socket(io_context), _endpoint(address, port) {
    boost::asio::ip::udp::endpoint endpoint(address, port);
    _socket.open(endpoint.protocol());
    _socket.set_option(boost::asio::ip::udp::socket::reuse_address(true));
    _socket.bind(endpoint);

    _socket.set_option(boost::asio::ip::multicast::join_group(address));
    
}

void Peer::do_receive() {
    
    cout << "trying to receive\n";
    _socket.async_receive_from(
        boost::asio::buffer(_buffer), _endpoint,
        [this](boost::system::error_code ec, size_t bytes_received) {
            if (!ec && bytes_received > 0) {
                cout << "RCV: " << _buffer
                     << " bytes received: " << bytes_received << endl;
                     do_receive();
            } else {
                cout << "RCV ERROR, BYTES: " << bytes_received << " "
                     << ec.message() << endl;
            }
        });
}

void Peer::do_send() {
    while (true) {
        cout << "enter msg\n";
        std::string msg;
        cin >> msg;
        _buffer = msg;

        _socket.async_send_to(
            boost::asio::buffer(_buffer), _endpoint,
            [this, msg](boost::system::error_code ec, size_t sent_bytes) {
                cout << "trying to send\n";

                if (!ec && sent_bytes > 0) {
                    cout << sent_bytes << " bytes sent successfully!\n";
                } else {
                    cout << "SEND ERROR, BYTES: " << sent_bytes << " "
                         << ec.message() << endl;
                }
            });
    }
}

boost::asio::ip::udp::endpoint Peer::endpoint() { return _endpoint; }
