#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <memory>
#include "Entity.h"


class Actor;
/// <summary>
/// Pocisk posiada swoj cel i dazy do niego, gdy dosiegniegnie swojego celu to zabiera mu HP a sam znika
/// Jezeli cel pocisku zniknie zanim on dotrze do celu to pocisk tez znika
/// </summary>
class Projectile : public Entity
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	/// <param name="textureId"></param>
	/// <param name="speed"></param>
	/// <param name="damage"></param>
	/// <param name="origin"></param>
	/// <param name="target"></param>
	Projectile(int textureId, float speed, int damage, const sf::Vector2f& origin, Actor* target);

	/// <summary>
	/// sprawdza czy pocisk jest do usuniecia
	/// </summary>
	/// <returns></returns>
	bool toRemove() const;

	/// <summary>
	/// aktualizuje pociski
	/// </summary>
	/// <param name="delta"></param>
	/// <param name="world"></param>
	virtual void update(sf::Time delta, World& world) override;
protected:
	/// <summary>
	/// Wartosc ktora stwierdza jak blisko to jest wystarczajaco
	/// </summary>
	static float EPSILON;
	float speed;
	int damage;

	/// <summary>
	/// Cel naszego pocisku
	/// </summary>
	Actor* target;

	/// <summary>
	/// Sprawdza czy pocisk dotarl do celu
	/// </summary>
	/// <returns></returns>
	bool reachedDestination() const;
private:
};

using ProjectilePtr = std::unique_ptr<Projectile>;
using Projectiles = std::vector<ProjectilePtr>;
