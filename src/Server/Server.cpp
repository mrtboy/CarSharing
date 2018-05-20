#include "Server.h"
#include <boost/foreach.hpp>

Server::Server(boost::asio::io_service& io_service, unsigned short port)
	: acceptor_(io_service,
		boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{

	// Start an accept operation for a new connection.
	connection_ptr new_conn(new Connection(acceptor_.get_io_service()));
	acceptor_.async_accept(new_conn->socket(),
		boost::bind(&Server::handle_accept, this,
			boost::asio::placeholders::error, new_conn));
}

/// Handle completion of a accept operation.
void Server::handle_accept(const boost::system::error_code& e, connection_ptr conn)
{

	if (!e)
	{
		
		conn->async_read(userWrapper,
			boost::bind(&Server::handle_read, this,
				boost::asio::placeholders::error, conn));

		conn->async_write(user_,
			boost::bind(&Server::handle_write, this,
				boost::asio::placeholders::error, conn));

	}

	// Start an accept operation for a new connection.
	connection_ptr new_conn(new Connection(acceptor_.get_io_service()));
	acceptor_.async_accept(new_conn->socket(),
		boost::bind(&Server::handle_accept, this,
			boost::asio::placeholders::error, new_conn));
}

void Server::handle_read(const boost::system::error_code& e, connection_ptr conn)
{
	cout << "read" << endl;

	if (!e)
	{
		cout << "read in" << endl;
		users_.push_back(userWrapper[AddNewUser]);
		for (std::size_t i = 0; i < users_.size(); ++i) {
			cout << users_[i].getUserString() << endl;
		}
		conn->async_read(userWrapper,
			boost::bind(&Server::handle_read, this,
				boost::asio::placeholders::error, conn));
		
	}
	else
	{
		// An error occurred.
		std::cerr << e.message() << std::endl;
	}
}

/// Handle completion of a write operation.
void Server::handle_write(const boost::system::error_code& e, connection_ptr conn)
{
	
}

int main(int argc, char* argv[])
{
	try
	{
		// Check command line arguments.
		if (argc != 2)
		{
			std::cerr << "Usage: server <port>" << std::endl;
			return 1;
		}
		unsigned short port = boost::lexical_cast<unsigned short>(argv[1]);

		boost::asio::io_service io_service;
		Server server(io_service, port);
		io_service.run();

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}