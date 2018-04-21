#ifndef CHATSERVER_H
#define	CHATSERVER_H

#include <map>
#include <string>

#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/udp.hpp>

class chatserver {
public:
  chatserver(boost::asio::io_service &io_service);
  ~chatserver();

protected:
  void onReceive(boost::system::error_code ec, std::size_t bytes_received);
  void doReceive();
  void parseMessage(std::string const &message, boost::asio::ip::udp::endpoint const &sender);

  void registerClient(std::string const &clientName, boost::asio::ip::udp::endpoint const &sender);
  void sendMessageToClients(std::string const &text);

private:
  // a reference to a more global io service object
  boost::asio::io_service &m_ioService;

  //! this will contain the used udp socket
  boost::asio::ip::udp::socket m_socket;

  

  

  
  
  
  //! this will map the clients name to the registered endpoint for this client
  std::map<std::string, boost::asio::ip::udp::endpoint> m_registeredClients;

  static const int c_serverPort = 2000;
  

  static const int c_maxLength = 255;
  std::array<char, c_maxLength> m_buffer;

  boost::asio::ip::udp::endpoint m_senderEndpoint;
};

#endif	/* CHATSERVER_H */

