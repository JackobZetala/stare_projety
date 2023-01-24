#include "World.h"
#include <memory>
#include "TwinGun.h"
#include "RocketLuncher.h"
#include "Sector.h"
#include "Soldier.h"


int BASE_BALANCE = 100000;
int BASE_HIT_POINTS = 500;

World::World():
	grid(),
	actors(),
	towers(),
	balance(BASE_BALANCE),
	hitPoints(BASE_HIT_POINTS)
{
}

void World::update(sf::Time delta)
{
	updateAll(actors, delta);
	updateAll(projectiles, delta);

	clean(projectiles);

	std::for_each(
		actors.begin(), actors.end(),
		[this](const ActorPtr& entity) {
			if (entity->reachedDestination())
			{
				this->hitPoints -= entity->getWorth();
			}
			else if (!entity->isAlive())
				this->balance += entity->getWorth();
		}
	);

	clean(actors);

	updateAll(towers, delta);
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(grid, states);
	drawAll(projectiles, target, states);
	drawAll(actors, target, states);
	drawAll(towers, target, states);
}

void World::fire(ProjectilePtr&& projectile)
{
	projectiles.push_back(std::move(projectile));
}

void World::placeTower(TowerPtr&& tower, int cost)
{
	if (balance >= cost)
	{
		towers.push_back(std::move(tower));
		balance -= cost;
	}
}

const Tower* World::getTowerAt(const Sector& target) const
{
	auto found = std::find_if(
		towers.cbegin(),
		towers.cend(),
		[&target](const TowerPtr& tower) { return tower->getSector() == target; }
	);
	return found == towers.cend() ? nullptr : &**found;
}

bool World::canPlaceTowerAt(const Sector& target) const
{
	return grid.isBuildingAllowedAt(target) && getTowerAt(target) == nullptr;
}
