#pragma once
#include <vector>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Sector.h"
#include "Entity.h"
#include <memory>

class Actor;
using ActorPtr = std::unique_ptr<Actor>;
using Actors = std::vector<ActorPtr>;

/// <summary>
/// Aktor dziedziczy po bytch i reprezentuje przeciwnikow  
/// Aktor chodzi po siezce, przy trafieniu pociskiem traci HP, zostaje usuniety gdy straci cale HP lub gdy przejdzie cala sciezke
/// </summary>
class Actor : public Entity
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	/// <param name="start"></param>
	/// <param name="finish"></param>
	/// <param name="textureId"></param>
	/// <param name="speed"></param>
	/// <param name="hitPoints"></param>
	/// <param name="worth"></param>
	Actor(PathIterator start, PathIterator finish, int textureId, float speed, int hitPoints, int worth);

	/// <summary>
	/// Sprawdza czy aktor przeszedl sciezke
	/// </summary>
	/// <returns></returns>
	bool reachedDestination() const { return start == finish; }

	/// <summary>
	/// Sprawdza czy aktor posiada HP
	/// </summary>
	/// <returns></returns>
	bool isAlive() const { return hitPoints > 0; }

	/// <summary>
	/// Sprawdza czy aktor jest do usuniecia (przeszedl sciezke lub umarl)
	/// </summary>
	/// <returns></returns>
	bool toRemove() const { return reachedDestination() || !isAlive(); }

	/// <summary>
	/// Aktualizuje aktorow
	/// </summary>
	/// <param name="delta"></param>
	/// <param name="world"></param>
	virtual void update(sf::Time delta, World& world) override;

	/// <summary>
	/// Zabiera HP aktorowi
	/// </summary>
	/// <param name="severity"></param>
	void damage(int severity) { hitPoints -= severity; }

	/// <summary>
	/// Zwraca wartosc jaka dostaje uzytkownik po pokonaniu aktora
	/// </summary>
	/// <returns></returns>
	virtual int getWorth() const { return worth; }

	/// <summary>
	/// Klonuje aktora
	/// </summary>
	/// <returns></returns>
	virtual ActorPtr clone() const;
private:
	/// <summary>
	/// nastepny sektor
	/// </summary>
	PathIterator start; 

	/// <summary>
	/// konczy iteracje
	/// </summary>
	PathIterator finish;
	float speed; 
	int hitPoints;

	/// <summary>
	/// Wartosc ile dostaje uzytkownik po pokonaniu aktora = HP ile traci przy przejsciu przez sciezke
	/// </summary>
	int worth;
};

