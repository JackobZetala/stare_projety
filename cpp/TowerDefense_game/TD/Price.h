#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
/// <summary>
/// menu ktore pokazuje cene danego zakupu
/// </summary>
class Price : public sf::Drawable
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	/// <param name="value"></param>
	/// <param name="position"></param>
	Price(int value, const sf::Vector2f& position);

	/// <summary>
	/// rysuje cene
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Text price;
	static sf::Color colorByValue(int value);
	static std::string contentsByValue(int value);
};
