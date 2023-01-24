#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "Scene.h"
#include "World.h"
#include "StatusBar.h"
#include "ContextMenu.h"
#include "Director.h"
/// <summary>
/// Scena z sama gra 
/// Zarzadza obiektami World, StatusBar, ContextMenu, Director
/// </summary>
class GameScene : public Scene
{
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	GameScene();
	/// <summary>
	/// Destruktor
	/// </summary>
	virtual ~GameScene() {}
	/// <summary>
	/// Nadpisana virtualna metoda sprawdzajaca nacisniecie przycisku
	/// </summary>
	/// <param name="event"></param>
	virtual void handleInput(const sf::Event& event) override;
	/// <summary>
	/// Nadpisana virtualna metoda aktualizujaca scene
	/// </summary>
	/// <param name="delta"></param>
	virtual void update(sf::Time delta) override;
	/// <summary>
	/// Nadpisana virtualna metoda rysujaca obiekt w danym miejscu
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	World world;
	StatusBar statusBar;
	ContextMenu contextMenu;
	Director director;
};

