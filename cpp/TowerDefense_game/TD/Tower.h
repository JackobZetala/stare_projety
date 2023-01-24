#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Sector.h"
#include "Actor.h"
#include "Entity.h"
#include "Projectile.h"
#include <vector>
#include <memory>

class World;
/// <summary>
/// Wieze buduje uytkownik i dzieki nim walczymy z przeciwnikiem
/// Uzytkownik ma wiele miejsc zeby postawic wieze, o ile nie jest to sciezka i na tym miejscu nie ma juz innej wiezy
/// Gdy przeciwnik wejdzie w zasieg wiezy i minie cooldown wiezy to oddawny jest strzal
/// </summary>
class Tower : public Entity
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	/// <param name="sector"></param>
	/// <param name="textureId"></param>
	/// <param name="range"></param>
	/// <param name="cooldown"></param>
	/// <param name="price"></param>
	Tower(Sector sector, int textureId, float range, sf::Time cooldown, int price);
	
	/// <summary>
	/// aktualizuje wieze
	/// </summary>
	/// <param name="delta"></param>
	/// <param name="world"></param>
	void update(sf::Time delta, World& world) override;

	/// <summary>
	/// rysuje wieze
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	/// <summary>
	/// zwraca zasieg wiezy
	/// </summary>
	/// <returns></returns>
	float getRange() const { return range; };

	/// <summary>
	/// zwraca koszt danej wiezy
	/// </summary>
	/// <returns></returns>
	int getPrice() const { return price; }

	/// <summary>
	/// zwraca sektor
	/// </summary>
	/// <returns></returns>
	const Sector& getSector() const { return sector; }
	static int PLATFORM_TEXTURE_ID;

protected:

	/// <summary>
	/// tworzy pocisk
	/// </summary>
	/// <param name="actor"></param>
	/// <returns></returns>
	virtual ProjectilePtr makeProjectile(Actor* actor) = 0;
private:
	Sector sector;
	float range;
	sf::Time cooldown;

	/// <summary>
	/// gromadzi kazdy krok i na jego podstawie liczony jest cooldown
	/// </summary>
	sf::Time timeAccumulated;
	sf::Sprite platform;
	int price;
	/// <summary>
	/// Bedzie nullptr gdy nie ma aktora w zasiegu
	/// </summary>
	/// <param name="actors"></param>
	/// <returns></returns>
	Actor* closestActor(Actors& actors);
};

using TowerPtr = std::unique_ptr<Tower>;
using Towers = std::vector<TowerPtr>;
