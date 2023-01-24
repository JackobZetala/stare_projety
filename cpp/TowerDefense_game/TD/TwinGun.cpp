#include "TwinGun.h"
#include "Bullet.h"
#include "World.h"

float TWIN_OFFSET = 50.f;
int TwinGun::TEXTURE_ID = 250;
float TwinGun::RANGE = 300.f;
sf::Time TwinGun::COOLDOWN = sf::milliseconds(600);
int TwinGun::PRICE = 2500;

TwinGun::TwinGun(Sector sector):
	Tower(sector, TEXTURE_ID, RANGE, COOLDOWN, PRICE),
	leftFiredLast(false)
{
}

ProjectilePtr TwinGun::makeProjectile(Actor* actor)
{
	sf::Vector2f origin = sprite.getPosition();
	float Rotation = toRadians(sprite.getRotation());
	auto offset = vectorFromRadians(Rotation) * TWIN_OFFSET;
	if (leftFiredLast)
		origin += offset;
	else
		origin -= offset;
	leftFiredLast = !leftFiredLast;
	return std::make_unique<Bullet>(origin, actor);


}
