#include "Bullet.h"


int TEXTURE_ID = 272;
float SPEED = 1200.f;
int DAMAGE = 60;

Bullet::Bullet(const sf::Vector2f& origin, Actor* target) :
	Projectile(TEXTURE_ID, SPEED, DAMAGE, origin, target)
{
}
