#ifndef PEER_H
#define PEER_H

#include <boost/asio.hpp>
#include <string>

class Peer {
 public:
    Peer(boost::asio::io_context& io_context,
         const boost::asio::ip::address& address =
             boost::asio::ip::address::from_string("127.0.0.1"));


    void do_receive();
    void do_send();
    boost::asio::ip::udp::endpoint endpoint();

 private:
    boost::asio::ip::udp::socket _socket;
    boost::asio::ip::udp::endpoint _endpoint;
    std::string _buffer;
};

#endif  // PEER_H
