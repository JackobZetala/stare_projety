#include "Rocket.h"
#include "Actor.h"

const int TEXTURE_ID = 251;
const float SPEED = 20.f;
float ACCELARATION = 500.f;
const int DAMAGE = 250;
float ANGLE_CORRECTION = 90;

Rocket::Rocket(const sf::Vector2f& origin, Actor* target):
	Projectile(TEXTURE_ID, SPEED, DAMAGE, origin, target)
{
}

void Rocket::update(sf::Time delta, World& world)
{
	if (target == nullptr)
		return;
	speed += ACCELARATION * delta / sf::seconds(1);
	Projectile::update(delta, world);
}
