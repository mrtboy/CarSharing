#include <iostream>
#include <string>
#include <memory>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>


int main(int argc, char *argv[])
{
	try
	{
		typedef boost::asio::ip::tcp asiotcp;
		if (argc != 2)
		{
			std::cerr << "Usage: client <host>" << std::endl;
			return 1;
		}

		boost::asio::io_service io_service;

		asiotcp::endpoint server_endpoint = asiotcp::endpoint(
			boost::asio::ip::address_v4::from_string(argv[1]),
			13);
		for (;;) {
			asiotcp::socket socket(io_service);
			socket.open(asiotcp::v4());

			std::string item = "";
			std::cin >> item;

			socket.connect(server_endpoint);
			std::string const send_buf = item;
			socket.send(boost::asio::buffer(send_buf));

			std::array<char, 128> recv_buf;
			size_t const len = socket.receive(
				boost::asio::buffer(recv_buf));

			std::string const received_message(recv_buf.data(), len);
			std::cout << "received from server: \"" << received_message << "\"" << std::endl;
		}
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

