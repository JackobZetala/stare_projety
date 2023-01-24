#include "Actor.h"
#include "Sector.h"
#include <SFML/Graphics/RenderTarget.hpp>

Actor::Actor(PathIterator start, PathIterator finish, int textureId, float speed, int hitPoints, int worth):
	Entity(textureId),
	start(start),
	finish(finish),
	speed(speed),
	hitPoints(hitPoints),
	worth(worth)
{
	sprite.setOrigin(Sector::CENTER);
	if (start != finish)
	{
		sprite.setPosition(start->midpoint());
		++start;
	}
}

void Actor::update(sf::Time delta, World& world)
{
	if (!toRemove() && moveTowards(start->midpoint(), delta, speed) && ++start != finish);
}

ActorPtr Actor::clone() const
{
	return std::make_unique<Actor>(start, finish, getTextureId(), speed, hitPoints, worth);
}

