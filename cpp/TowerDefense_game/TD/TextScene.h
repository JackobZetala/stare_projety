#pragma once
#include "Scene.h"
#include <SFML/Graphics/Text.hpp>
/// <summary>
/// Abstrakcyjna scena ktora wyswietla dwa teksty i po nacisniecia klawisza przenosi na kolejna scene 
/// Zarzadza obiektami Text i SceneType
/// </summary>
class TextScene : public Scene
{
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="firstly"></param>
	/// <param name="secondly"></param>
	/// <param name="nextScene"></param>
	TextScene(const char* firstly, const char* secondly, SceneType nextScene);
	/// <summary>
	/// Sprawdza nacisniecie klawisza
	/// </summary>
	/// <param name="event"></param>
	virtual void handleInput(const sf::Event& event) override;
	/// <summary>
	/// Rysuje teksty
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Text firstly;
	sf::Text secondly;
	SceneType nextScene;
};
