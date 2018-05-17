#include "ClientConnection.h"

ClientConnection::ClientConnection(boost::asio::io_service& io_service,
	const std::string& host, const std::string& service)
	: connection_(io_service)
{

	// Resolve the host name into an IP address.
	boost::asio::ip::tcp::resolver resolver(io_service);
	boost::asio::ip::tcp::resolver::query query(host, service);
	boost::asio::ip::tcp::resolver::iterator endpoint_iterator =
		resolver.resolve(query);

	// Start an asynchronous connect operation.
	boost::asio::async_connect(connection_.socket(), endpoint_iterator,
		boost::bind(&ClientConnection::handle_connect, this,
			boost::asio::placeholders::error));
}

void ClientConnection::handle_connect(const boost::system::error_code& e)
{
	if (!e)
	{

		User user{ "aa","dd",22,"dd","dds","gg" };
		user_ = user;
		connection_.async_write(user_,
			boost::bind(&ClientConnection::handle_write, this,
				boost::asio::placeholders::error));
	}
	else
	{
		std::cerr << e.message() << std::endl;
	}

}

/// Handle completion of a read operation.
void ClientConnection::handle_read(const boost::system::error_code& e)
{
	if (!e)
	{

	}
	else
	{
		// An error occurred.
		std::cerr << e.message() << std::endl;
	}
}

void ClientConnection::handle_write(const boost::system::error_code& e)
{
	
}