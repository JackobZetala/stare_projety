#pragma once
#include <SFML/Network.hpp>
#include <thread>

namespace Client {
	sf::IpAddress sendIP;
	sf::UdpSocket sock;
	unsigned short port;
	unsigned short SPort;
	
	/// <summary>
	/// Funkcja do wysylania wiadomosci
	/// </summary>
	void CheckMessage() {
		while (true) {
			sf::Packet message;

			std::string text;
			getline(std::cin, text);

			message << "Message" << text;

			sock.send(message, sendIP, SPort);
		}
	}

	/// <summary>
	/// Funkcja do laczenia sie z serwerem
	/// </summary>
	void Connect() {
		port = sock.getLocalPort();
		sock.bind(port);
		port = sock.getLocalPort();
		sock.bind(port);

		std::cout << "Enter server IP: ";
		std::cin >> sendIP;

		std::cout << "Enter server port: ";
		std::cin >> SPort;

		sf::Packet message;
		message << "Connect";
		sock.send(message, sendIP, SPort);
	}

	/// <summary>
	/// Odbieranie wiadomosci i wyswietlanie
	/// </summary>
	void Receive() {
		while (true) {
			sf::Packet message;
			sf::IpAddress tIP;
			unsigned short tPr;

			if (sock.receive(message, tIP, tPr) == sf::Socket::Done) {
				std::string text;

				message >> text;
				std::cout << text << std::endl;
			}
		}
	};

	/// <summary>
	/// Funkcja wywolywana w mainie aby sprawdzac thready
	/// </summary>
	void Startup() {
		Connect();

		std::thread sender(CheckMessage);
		sender.detach();
		std::thread receiver(Receive);
		receiver.detach();

	}

	
};