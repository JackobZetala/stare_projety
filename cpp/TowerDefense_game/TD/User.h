#pragma once
#include <SFML/Network.hpp>
/// <summary>
/// Przechowywanie danych klienta
/// </summary>
struct User
{
	sf::IpAddress ip;
	unsigned short port;
	bool isActive = 0;
};