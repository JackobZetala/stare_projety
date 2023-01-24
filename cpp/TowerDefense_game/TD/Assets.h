#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

/// <summary>
/// Jest to singleton, ktory przechwuje wskazniki do RenderWindow i Texture 
/// Jest to przydatne rozwiazanie poniewaz wiekszosc obiektow potrzebuje tej zawartosci 
/// </summary>
struct Assets
{
public:
	static Assets& get()
	{
		static Assets assets;
		return assets;
	}

	sf::RenderWindow* window;
	sf::Texture texture;
private:
	Assets() : window(), texture() {};
};
