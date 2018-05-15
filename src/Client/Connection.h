#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <string>
#include <memory>
#include <boost\asio.hpp>
#include <boost\bind.hpp>
#include <boost\asio\buffer.hpp>
#include <boost\asio\io_service.hpp>
#include <boost\asio\ip\tcp.hpp>
#include <boost\archive\binary_oarchive.hpp>
#include <boost\archive\binary_iarchive.hpp>
#include <boost\serialization\string.hpp>
#include <boost\serialization\vector.hpp>
#include "User.h"


using namespace boost::archive;
using namespace boost::asio;
std::stringstream stringStream;
using namespace std;

class Connection
{
public:
	Connection();
	~Connection();

	template<typename T>
	void connectToServer(T s);
	void send();
	void recieve();


	

private:

};

Connection::Connection()
{
}

Connection::~Connection()
{
}

template<typename T>
void Connection::connectToServer(T s) {

	try
	{
		const char *host = "127.0.0.1", *port = "2300";
		typedef boost::asio::ip::tcp asiotcp;
		/*	if (argc != 2)
		{
		std::cerr << "Usage: client <host>" << std::endl;
		return 1;
		}*/

		boost::asio::io_service io_service;
		//boost::asio::ip::tcp::resolver resolver(io_service);


		asiotcp::endpoint server_endpoint = asiotcp::endpoint(
			boost::asio::ip::address_v4::from_string(host),
			13);

		asiotcp::socket socket(io_service);
		socket.open(asiotcp::v4());

		socket.connect(server_endpoint);

		binary_oarchive oArchive{ stringStream, boost::archive::no_header };

		oArchive << s;

		std::string const send_buf = stringStream.str();

		socket.send(boost::asio::buffer(send_buf));

		std::array<char, 128> recv_buf;
		size_t const len = socket.receive(
			boost::asio::buffer(recv_buf));

		std::string const received_message(recv_buf.data(), len);
		std::cout << "received from server: \"" << received_message << "\"" << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	
}

//void Connection::send() {
//
//	binary_oarchive oArchive{ stringStream, boost::archive::no_header };
//
//	User user{ "1","qq",44,"qq","ee","ee" };
//
//	oArchive << user;
//
//	std::string const send_buf = stringStream.str();
//
//	socket.send(boost::asio::buffer(send_buf));
//}
//
//void Connection::recieve() {
//	std::array<char, 128> recv_buf;
//	size_t const len = socket.receive(
//		boost::asio::buffer(recv_buf));
//
//	std::string const received_message(recv_buf.data(), len);
//	std::cout << "received from server: \"" << received_message << "\"" << std::endl;
//}


#endif