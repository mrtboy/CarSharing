#include "Server.h"

Server::Server(boost::asio::io_service& io_service, unsigned short port)
	: acceptor_(io_service,
		boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
	// Create the data to be sent to each client.
	/*MainMenu mainMenu;
	menu_= mainMenu.createMainMenu();*/

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
		conn->async_write(users_,
			boost::bind(&Server::handle_read, this,
				boost::asio::placeholders::error, conn));

		conn->async_read(user_,
			boost::bind(&Server::handle_read, this,
				boost::asio::placeholders::error, conn));
		

	}

	// Start an accept operation for a new connection.
	connection_ptr new_conn(new Connection(acceptor_.get_io_service()));
	acceptor_.async_accept(new_conn->socket(),
		boost::bind(&Server::handle_accept, this,
			boost::asio::placeholders::error, new_conn));
}

void Server::handle_rec(const boost::system::error_code& e, connection_ptr conn) {

}


void Server::handle_read(const boost::system::error_code& e, connection_ptr conn)
{
	cout << "read" << endl;
	if (!e)
	{
		manageUser.insert(user_);
		//cout << user_.getUserString() << endl;

		conn->async_read(option_,
			boost::bind(&Server::handle_read, this,
				boost::asio::placeholders::error, conn));

		if (option_ == '1')
		{
			conn->async_write(user_,
				boost::bind(&Server::handle_read, this,
					boost::asio::placeholders::error, conn));
		}
		
	}
	else
	{
		// An error occurred.
		std::cerr << e.message() << std::endl;
	}

	// Since we are not starting a new operation the io_service will run out of
	// work to do and the client will exit.
}

/// Handle completion of a write operation.
void Server::handle_write(const boost::system::error_code& e, connection_ptr conn)
{
	cout << "Write" << endl;
	// Nothing to do. The socket will be closed automatically when the last
	// reference to the connection object goes away.
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