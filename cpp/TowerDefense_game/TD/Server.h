#pragma once
#include <SFML/Network.hpp>
#include "User.h"
namespace Server {

	/// <summary>
	/// Wyluskanie Adresi IP 
	/// </summary>
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::UdpSocket sock;
	unsigned short port;

	/// <summary>
	/// Wektro uzytkownikow
	/// </summary>
	std::vector <User> Users;

	/// <summary>
	/// Serwer odbiera wiadomosc od jakiegos klienta i odsyla ja do kazdego klienta oraz wyswitla ta widomosc u siebie
	/// </summary>
	void NewMessage() {
		while (true) {
			sf::IpAddress rIp;
			unsigned short port;
			sf::Packet message;
			if (sock.receive(message, rIp, port) == sf::Socket::Done) {
				std::string type;
				message >> type;
				if (type == "Connect") {
					User nuser;
					nuser.ip = rIp;
					nuser.port = port;
					nuser.isActive = true;
					Users.push_back(nuser);
				}
				else if (type == "Message") {
					std::string text;
					message >> text;
					std::cout << text << std::endl;
					for (int i = 0; i < Users.size(); i++) {
						if (Users[i].isActive)
							sock.send(message, Users[i].ip, Users[i].port);
					}
				}
			}
		}
	}
	/// <summary>
	/// Funkcja do wysylania wiadomosci przez serwer do klientow
	/// </summary>
	void CheckMessage() {
		while (true) {
			sf::Packet message;
			std::string text;
			getline(std::cin, text);
			message << text;
			for (int i = 0; i < Users.size(); i++) {
				if (Users[i].isActive)
					sock.send(message, Users[i].ip, Users[i].port);
			}
		}
	}
	/// <summary>
	/// Ustawianie portu
	/// </summary>

	void Settings() { 
		port = sock.getLocalPort();
		sock.bind(port); 
		port = sock.getLocalPort();
		sock.bind(port); 

		std::cout << ip.toString() << std::endl << port << std::endl;
	}

	/// <summary>
	/// Funkcja wywolywana w mainie aby sprawdzac thready 
	/// </summary>
	void Startup() {
		Settings();
		
		std::thread newmess(NewMessage); 
		newmess.detach();
		std::thread sender(CheckMessage);
		sender.detach();
	}
};