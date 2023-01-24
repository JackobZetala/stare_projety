#pragma once
#include "Actor.h"
#include "Soldier.h"
/// <summary>
/// Fala reprezentuje kilku aktorow tego samego typu w odpowiednich przedzialach czasu
/// Zarzadza obiektami ActorPtr i Time
/// </summary>
class Wave
{
public:
	/// <summary>
	/// przedzialy czasu
	/// </summary>
	static const sf::Time SPACING_HUGE;
	static const sf::Time SPACING_WIDE;
	static const sf::Time SPACING_MEDIUM;
	static const sf::Time SPACING_NARROW;

	/// <summary>
	/// konstruktor
	/// </summary>
	/// <param name="grade"></param>
	/// <param name="count"></param>
	/// <param name="path"></param>
	/// <param name="spacing"></param>
	Wave(SoldierGrade grade, int count, const Path& path, sf::Time spacing);

	/// <summary>
	/// wysyla kolejna fale na zadanie
	/// </summary>
	/// <param name="delta"></param>
	/// <returns></returns>
	ActorPtr maybeSendNext(sf::Time delta);

	/// <summary>
	/// sprawdza status aktualnej fali
	/// </summary>
	/// <returns></returns>
	bool isEmpty() const { return actorsLeft <= 0; }
private:
	ActorPtr actorTemplate;
	int actorsLeft;
	sf::Time spacing;
	sf::Time elapsed;
};

using WavePtr = std::unique_ptr<Wave>;