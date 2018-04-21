#include "chatserver.hpp"

#include <iostream>



chatserver::chatserver(boost::asio::io_service &io_service)
  : m_ioService(io_service)
  , m_socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), c_serverPort))
  , m_buffer()
  , m_senderEndpoint()
{
  doReceive();
}

chatserver::~chatserver() {
}

void chatserver::onReceive(boost::system::error_code ec, std::size_t bytes_received)
{
  if (!ec && bytes_received > 0)
  {
    std::string const message(m_buffer.data(), bytes_received);
    parseMessage(message, m_senderEndpoint);
  }
  doReceive();
}
void chatserver::doReceive() {
  m_socket.async_receive_from(
      boost::asio::buffer(m_buffer, c_maxLength),
      m_senderEndpoint,
      std::bind(&chatserver::onReceive, this, std::placeholders::_1, std::placeholders::_2));
}

void chatserver::parseMessage(std::string const &message, boost::asio::ip::udp::endpoint const &sender)
{
  std::string const &messageType = message.substr(0, 1);
  if (messageType == "R") {
    // register a new client
    std::string const &clientname = message.substr(1);
    registerClient(clientname, sender);
  } else if (messageType == "S") {
    // send a text to all other clients
    std::string const &text = message.substr(1);
    sendMessageToClients(text);
  }
}

void chatserver::registerClient(std::string const &clientName, boost::asio::ip::udp::endpoint const &sender)
{
  std::cout << "Register new client " << clientName << " with endpoint " << sender << std::endl;
  m_registeredClients[clientName] = sender;
}
void chatserver::sendMessageToClients(std::string const &text)
{
  std::cout << "Will send the message " << text << " to all clients." << std::endl;
  for (auto const &it : m_registeredClients)
  {
    m_socket.send_to(boost::asio::buffer(text), it.second);
  }
}
