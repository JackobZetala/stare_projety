#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include <vector>

class World;

/// <summary>
/// Klasa nadrzedna wszystkich bytow
/// Posiada wlasny Sprite do ktorego przypisuje teksture zgodnie z identyfikatorem w konstruktorze
/// </summary>
class Entity : public sf::Drawable
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	/// <param name="textureId"></param>
	Entity(int textureId);

	/// <summary>
	/// destruktor
	/// </summary>
	virtual ~Entity() {};

	/// <summary>
	/// Zwraca dana pozycje
	/// </summary>
	/// <returns></returns>
	const sf::Vector2f& getPosition() const { return sprite.getPosition(); }

	/// <summary>
	/// aktualizuje byty
	/// </summary>
	/// <param name="delta"></param>
	/// <param name="world"></param>
	virtual void update(sf::Time delta, World& world) = 0;

	/// <summary>
	/// Rysuje byty
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	sf::Sprite sprite;

	/// <summary>
	/// Zwraca Id tekstury
	/// </summary>
	/// <returns></returns>
	int getTextureId() const { return textureId; }
	
	/// <summary>
	/// Zwraca odleglosc miedzy bytami do kwadratu
	/// </summary>
	/// <param name="target"></param>
	/// <returns></returns>
	float distanceSquaredFrom(const sf::Vector2f& target) const;
	
	/// <summary>
	/// Sprawdza czy cel jest w zasiegu
	/// </summary>
	/// <param name="target"></param>
	/// <param name="range"></param>
	/// <returns></returns>
	bool isInRange(const sf::Vector2f& target, float range) const;
	// speed is in points per second, delta is the elapsed time
	
	/// <summary>
	/// Sprawdza czy porusza sie w kierunku celu
	/// </summary>
	/// <param name="target"></param>
	/// <param name="delta"></param>
	/// <param name="speed"></param>
	/// <returns></returns>
	bool moveTowards(const sf::Vector2f& target, sf::Time delta, float speed);
private:
	int textureId;
};

using EntityPtr = std::unique_ptr<Entity>;
using Entities = std::vector<EntityPtr>;
