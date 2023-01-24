#pragma once
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include "Scene.h"
#include <iostream>


/// <summary>
/// Najwazniejsza klasa posiadajaca glowna petle gry, oraz ladujaca textury
/// Wspolpracuje ze scenami
/// Zarzadza obiektami ScenePtr, RenderWindow, Clock, Time, RenderStates
/// </summary>
class App
{
public:
	unsigned short port = 0;
	char connectionType;
	char mode;
	App();
	/// <summary>
	/// Metoda uzywana raz w punkcie odpalania programu, laduje textury
	/// </summary>
	/// <returns>Zwraca wartosc boolowska aby pozniej sprawdzic czy udalo zaladowanie </returns>
	bool load();
	/// <summary>
	/// Metoda glownej petli gry ktora utrzymuje sie dopoki otwarte jest okno
	/// Podczas tej petli sprawdzane sa:
	/// - zmiana sceny
	/// - przetwarzanie zdarzen/wejsc
	/// - zliczanie czasu po jakim maja aktualizowac sie wszystkie rzeczy w grze(ustawione 30 klatek na sekunde)
	/// - rysowanie scen, wszytkie obiekty Drawable dziedzicza po sf::Dawable i implementuja wirtualna metode rysowania 
	/// </summary>
	void loop();

	

private:
	ScenePtr scene;
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time updateTimeAccumulator;
	sf::RenderStates renderStates;

	/// <summary>
	/// Metoda trzymajaca prosbe o zmiane sceny
	/// </summary>
	void handleSceneChange();
	/// <summary>
	/// Metoda trzymajaca informacje o jakims wejsciu
	/// </summary>
	void handleInput();
	/// <summary>
	/// Metoda odpowiedzialna za pilnowanie czasu odswiezania 
	/// </summary>
	void fixedTimestepUpdate();
	bool handleKeyboard();

};
