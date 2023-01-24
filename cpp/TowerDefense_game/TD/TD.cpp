#include "App.h"
#include <iostream>
#include "Client.h"
#include "Server.h"
int main()
{
	char ct = 's';
	std::cout << "s / c \n"; // s - server / c - client
	std::cin >> ct;
	if (ct == 's') {
		Server::Startup();
	}
	else if (ct == 'c') {
		Client::Startup();
	}
	
	App app;
	if (!app.load())
	{
		std::cerr << "Failed to load the game." << std::endl;
		return 0;
	}
	app.loop();
	return 0;
}
