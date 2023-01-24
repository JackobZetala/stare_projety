#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include "Button.h"
#include "PlaceTowerButton.h"
#include <SFML/Graphics/RectangleShape.hpp>

/// <summary>
/// Jest to menu ktore wyswietla sie po najechaniu mysza na dany sektor
/// Podswietla sie na niebiesko jezeli mozna wykonac akcje w tym miejscu i na czerono jezeli nie mozna
/// Wyswitla tez mozliwosci jakie sa do zbudowania gdy wcisniemy dozwolone miejsce
/// </summary>
class ContextMenu : public sf::Drawable
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	ContextMenu();

	/// <summary>
	/// wylapuje wcisniecie myszki
	/// </summary>
	/// <param name="event"></param>
	/// <param name="world"></param>
	void handleInput(const sf::Event& event, World& world);

	/// <summary>
	/// aktualizuje polozenie myszki
	/// </summary>
	/// <param name="world"></param>
	/// <param name="mousePosition"></param>
	void update(World& world, const sf::Vector2f& mousePosition);

	/// <summary>
	/// rysuje obramoawnie
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	Buttons buttons;
	sf::RectangleShape hoverIndicator;
	/// <summary>
	/// prawda gdy otwarte jest menu zakupu wiezy
	/// </summary>
	bool showActiveIndicator;
	sf::RectangleShape activeIndicator;

	/// <summary>
	/// przygotowuje menu zakupu wiezy
	/// </summary>
	/// <param name="sector"></param>
	void prepareShoppingList(const Sector& sector);
	/// <summary>
	/// aktywuje przycisk do budowy wiezy
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="position"></param>
	/// <param name="towerSector"></param>
	template<typename T>
	void insertPlaceTowerButton(const sf::Vector2f& position, const Sector& towerSector);
};

template<typename T>
void ContextMenu::insertPlaceTowerButton(const sf::Vector2f& position, const Sector& towerSector)
{
	buttons.push_back(std::make_unique<PlaceTowerButton<T>>(position, towerSector));
}
