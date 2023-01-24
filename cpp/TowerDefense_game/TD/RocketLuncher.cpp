#include "RocketLuncher.h"
#include "Rocket.h"

int RocketLuncher::TEXTURE_ID = 226;
float RocketLuncher::RANGE = 500.f;
sf::Time RocketLuncher::COOLDOWN = sf::milliseconds(900);
int RocketLuncher::PRICE = 800;

RocketLuncher::RocketLuncher(Sector sector) :
	Tower(sector, TEXTURE_ID, RANGE, COOLDOWN, PRICE)
{
}

ProjectilePtr RocketLuncher::makeProjectile(Actor* actor)
{
	return std::make_unique<Rocket>(sprite.getPosition(), actor);
}
