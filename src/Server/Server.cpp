#include <iostream>
#include <string>
#include <memory>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost\archive\binary_oarchive.hpp>
#include <boost\archive\binary_iarchive.hpp>
#include "User.h"
#include "ManageUser.h"

using namespace boost::archive;
using namespace boost::asio;
std::stringstream stringStream;

template<class Archive, class Object>
void deserialise_to_obj(std::string const &s1, Object &outObj)
{
	std::stringstream is(s1, std::ios_base::binary | std::ios_base::out | std::ios_base::in);
	Archive arch{ is, boost::archive::no_header };
	arch >> BOOST_SERIALIZATION_NVP(outObj);
};

int main()
{

	try
	{
		typedef boost::asio::ip::tcp asiotcp;
		boost::asio::io_service io_service;

		while (true)
		{
			asiotcp::socket socket(io_service);

			asiotcp::acceptor a(io_service, asiotcp::endpoint(asiotcp::v4(), 13));
			a.accept(socket);

			std::array<char, 256> recv_buf;

			std::size_t const received_bytes = socket.receive(
				boost::asio::buffer(recv_buf));

			std::string const inputmessage(recv_buf.data(), received_bytes);
			//std::cout << "Client sent message: \"" << inputmessage << "\"" << std::endl;
			
			//ManageUser mu;
			User user;

			//mu.insert(user);
			deserialise_to_obj<binary_iarchive>(inputmessage, user);
			ManageUser mu;
			mu.insert(user);

			int vectorSize = ManageUser::users.size();
			
			//cout << ManageUser::users[0].getName() << endl;

			binary_oarchive oArchive{ stringStream, boost::archive::no_header };

			oArchive << ManageUser::users[0];

			std::string const send_buf = stringStream.str();
			socket.send(boost::asio::buffer(send_buf));
			
		}
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

