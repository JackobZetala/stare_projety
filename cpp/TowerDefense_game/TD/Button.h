#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include "Sector.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include <memory>
#include <SFML/Graphics/CircleShape.hpp>

class World;
/// <summary>
/// Przycisk reaguje na polozenie myszy i klikniecie 
/// Przycisk rozpoznaje kiedy przycisk zostal juz odklikniety
/// </summary>
class Button : public sf::Drawable
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	/// <param name="position"></param>
	/// <param name="iconTextureId"></param>
	Button(const sf::Vector2f& position, int iconTextureId);

	/// <summary>
	/// destruktor
	/// </summary>
	virtual ~Button() {};

	/// <summary>
	/// sprawdza nacisniecie myszy
	/// </summary>
	/// <param name="event"></param>
	/// <param name="world"></param>
	/// <returns></returns>
	bool handleInput(const sf::Event& event, World& world);

	/// <summary>
	/// aktualizuje pozycje myszy
	/// </summary>
	/// <param name="world"></param>
	/// <param name="mousePosition"></param>
	void update(World& world, const sf::Vector2f& mousePosition);

	/// <summary>
	/// rysuje sprite i icon
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	/// <summary>
	/// sprawdza czy bylo wcisniete 
	/// </summary>
	/// <returns></returns>
	bool hasBeenClicked() const { return clicked; };
protected:
	/// <summary>
	/// czy mysz jest nad przyciskiem
	/// </summary>
	/// <returns></returns>
	bool mouseHovers() const { return mouseIn; }

	/// <summary>
	/// funkcja wykonujaca zdarzenia po kliknieciu
	/// </summary>
	/// <param name="world"></param>
	virtual void onClick(World& world);
private:
	/// <summary>
	/// sluzy za tlo
	/// </summary>
	sf::CircleShape sprite;
	/// <summary>
	/// sluzy za icone
	/// </summary>
	sf::Sprite icon;
	bool mouseIn;
	bool clicked; 
};

using ButtonPtr = std::unique_ptr<Button>;
using Buttons = std::vector<ButtonPtr>;