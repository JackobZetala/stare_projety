#pragma once
#include "Tower.h"
/// <summary>
/// konkretny typ wiezy
/// </summary>
class TwinGun : public Tower
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	/// <param name="sector"></param>
	TwinGun(Sector sector);
	
	/// <summary>
	/// tworzy pocisk
	/// </summary>
	/// <param name="actor"></param>
	/// <returns></returns>
	virtual ProjectilePtr makeProjectile(Actor* actor) override;
	static int TEXTURE_ID;
	static float RANGE;
	static sf::Time COOLDOWN;
	static int PRICE;
	
private:
	bool leftFiredLast;
};
