#pragma once
#include "Projectile.h"
/// <summary>
/// Kula jest to konkretny pocisk
/// </summary>
class Bullet : public Projectile
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	/// <param name="origin"></param>
	/// <param name="target"></param>
	Bullet(const sf::Vector2f& origin, Actor* target);
};
