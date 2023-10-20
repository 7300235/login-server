#include <iostream>
#include <boost/asio.hpp>
#include <string>

using namespace boost::asio;
using std::string;

//xml to config
const string server_ip = "127.0.0.1"; // temporary ip, to change
const int server_port = 12345; // temporary port, to change, better in config path

int main() {
    io_service ioService;

    ip::tcp::endpoint endpoint(ip::address::from_string(server_ip), server_port);
    ip::tcp::socket socket(ioService);

    try {
        // Attempt to connect
        socket.connect(endpoint);

        // If we reach here, the connection was successful
        std::cout << "Connected to: " << endpoint << std::endl;
    } catch (boost::system::system_error& e) {
        // Handle connection error
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
