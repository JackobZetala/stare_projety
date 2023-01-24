#pragma once
#include "Button.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include "World.h"
#include "TowerPreview.h"


/// <summary>
/// Przycisk ktory po wcisnieciu buduje wieze i zmniejsza balans konta uzytkownika
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class PlaceTowerButton : public Button
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	/// <param name="position"></param>
	/// <param name="towerSector"></param>
	PlaceTowerButton(const sf::Vector2f& position, const Sector& towerSector);
	/// <summary>
	/// postawienie wiezy i usuniecie podgladu wiezy
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	/// <summary>
	/// wykonanie zadan po nacisnieciu przycisku
	/// </summary>
	/// <param name="world"></param>
	virtual void onClick(World& world) override;
	Sector towerSector;
private:
	TowerPreview<T> preview;
};

template<typename T>
PlaceTowerButton<T>::PlaceTowerButton(const sf::Vector2f& position, const Sector& towerSector):
	Button(position, T::TEXTURE_ID),
	towerSector(towerSector),
	preview(towerSector)
{
}

template<typename T>
void PlaceTowerButton<T>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (mouseHovers())
		target.draw(preview, states);
	Button::draw(target, states);
}

template<typename T>
void PlaceTowerButton<T>::onClick(World& world)
{
	Button::onClick(world);
	world.placeTower(std::make_unique<T>(towerSector), T::PRICE);
}
