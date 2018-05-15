#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <vector>
#include "Connection.h" // Must come before boost/serialization headers.
#include <boost/serialization/vector.hpp>
#include "User.h"
#include "Car.h"

/// Serves stock quote information to any client that connects to it.
class ServerConnection
{
public:
	/// Constructor opens the acceptor and starts waiting for the first incoming
	/// connection.
	ServerConnection(boost::asio::io_service& io_service, unsigned short port)
		: acceptor_(io_service,
			boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
	{
		// Create the data to be sent to each client.
		User u{ "1","Reza",33,"Kiel", "Email", "Address" };
		user_.push_back(u);
		User u1{ "2","Mohammadreza",33,"Kiel", "Email", "Address" };
		user_.push_back(u1);


		// Start an accept operation for a new connection.
		connection_ptr new_conn(new Connection(acceptor_.get_io_service()));
		acceptor_.async_accept(new_conn->socket(),
			boost::bind(&ServerConnection::handle_accept, this,
				boost::asio::placeholders::error, new_conn));
	}

	/// Handle completion of a accept operation.
	void handle_accept(const boost::system::error_code& e, connection_ptr conn)
	{
		if (!e)
		{
			// Successfully accepted a new connection. Send the list of stocks to the
			// client. The connection::async_write() function will automatically
			// serialize the data structure for us.

			conn->async_write(user_,
				boost::bind(&ServerConnection::handle_write, this,
					boost::asio::placeholders::error, conn));

			conn->async_read(car_,
				boost::bind(&ServerConnection::handle_read, this,
					boost::asio::placeholders::error, conn));
		}

		// Start an accept operation for a new connection.
		connection_ptr new_conn(new Connection(acceptor_.get_io_service()));
		acceptor_.async_accept(new_conn->socket(),
			boost::bind(&ServerConnection::handle_accept, this,
				boost::asio::placeholders::error, new_conn));
	}

	void handle_read(const boost::system::error_code& e, connection_ptr conn)
	{
		if (!e)
		{
			// Print out the data that was received.
			for (std::size_t i = 0; i < car_.size(); ++i) {
				cout << "Id: " + car_[i].getID() << endl;
				cout << "Model: " + car_[i].getModel() << endl;
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
	void handle_write(const boost::system::error_code& e, connection_ptr conn)
	{
		// Nothing to do. The socket will be closed automatically when the last
		// reference to the connection object goes away.
	}

private:
	/// The acceptor object used to accept incoming socket connections.
	boost::asio::ip::tcp::acceptor acceptor_;

	/// The data to be sent to each client.
	std::vector<User> user_;
	std::vector<Car> car_;
};

