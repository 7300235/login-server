#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;

int main() {
    io_service ioService;

    // Create an endpoint to listen on all available interfaces and a specific port
    ip::tcp::endpoint endpoint(ip::tcp::v4(), 12345);

    // Create an acceptor
    ip::tcp::acceptor acceptor(ioService, endpoint);

    std::cout << "Waiting for incoming connections..." << std::endl;

    while (true) {
        ip::tcp::socket socket(ioService);

        try {
            // Wait for a connection
            acceptor.accept(socket);

            // If we reach here, a connection was successfully accepted
            std::cout << "Accepted connection from: " << socket.remote_endpoint() << std::endl;

            // Here you can handle the socket for communication
            // For example, you can read and write to the socket using async_read and async_write functions.
            // Remember to handle the data asynchronously to handle multiple connections.

        } catch (boost::system::system_error& e) {
            // Handle accept error
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
