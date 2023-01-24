#pragma once

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include "World.h"
/// <summary>
/// Pasek w lewym gornym rogu ktory pokazuje stan konta i hp uzytkownika
/// </summary>
class StatusBar : public sf::Drawable
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	StatusBar();
	/// <summary>
	/// aktualizuje pasek statusu
	/// </summary>
	/// <param name="world"></param>
	void update(const World& world);
	/// <summary>
	/// wyrysowuje pasek statusu
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Text balanceText;
	sf::Text hitPointsText;
};

