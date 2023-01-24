#pragma once
#include "Grid.h"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
#include <algorithm>
#include "Actor.h"
#include "Tower.h"
#include "Projectile.h"
#include <memory>
#include <functional>
/// <summary>
/// Swiat to klasa ktora laczy siatke ze wszystkimi bytami
/// Zarzadza obiektami Grid, Actors, Towers i Projectiles
/// </summary>
class World : public sf::Drawable
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	World();

	/// <summary>
	/// aktualizacje wszystko co dzieje sie na swiecie
	/// </summary>
	/// <param name="delta"></param>
	void update(sf::Time delta);

	/// <summary>
	/// Rysuje wszystkie wskazane obiekty
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	/// <summary>
	/// Zwraca vektor wszytkich aktorow
	/// </summary>
	/// <returns></returns>
	Actors& getActors() { return actors; }

	/// <summary>
	/// Tworzy pocisk i dodaje go do vektoru projectiles
	/// </summary>
	/// <param name="projectile"></param>
	void fire(ProjectilePtr&& projectile);

	/// <summary>
	/// Stawia wieze i zmniejsza balans konta uzytkownika
	/// </summary>
	/// <param name="tower"></param>
	/// <param name="cost"></param>
	void placeTower(TowerPtr&& tower, int cost);

	/// <summary>
	/// Sprawdza gdzie sa juz wieze
	/// </summary>
	/// <param name="target"></param>
	/// <returns></returns>
	const Tower* getTowerAt(const Sector& target) const;

	/// <summary>
	/// Spradza czy mozna postawic wieze w danym sektorze
	/// </summary>
	/// <param name="target"></param>
	/// <returns></returns>
	bool canPlaceTowerAt(const Sector& target) const;

	/// <summary>
	/// Zwraca balans konta uzytkownika
	/// </summary>
	/// <returns></returns>
	int getBalance() const { return balance; }

	/// <summary>
	/// Zwraca HP uzytkownika
	/// </summary>
	/// <returns></returns>
	int getHitPoints() const { return hitPoints; }

	/// <summary>
	/// Zwraca sciezke
	/// </summary>
	/// <returns></returns>
	const Grid& getGrid() const { return grid; }
private:
	Grid grid;
	Actors actors;
	Towers towers;
	Projectiles projectiles;
	/// <summary>
	/// Balans uzytkownika
	/// </summary>
	int balance;

	/// <summary>
	/// HP uzytkownika
	/// </summary>
	int hitPoints;

	/// <summary>
	/// Usuwa byty ktore chca byc usuniete
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="vec"></param>
	template<typename T>
	void clean(std::vector<std::unique_ptr<T>>& vec); 

	/// <summary>
	/// Aktualizuje dane byty
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="vec"></param>
	/// <param name="delta"></param>
	template<typename T>
	void updateAll(const std::vector<std::unique_ptr<T>>& vec, sf::Time delta);

	/// <summary>
	/// Rysuje dane byty
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="vec"></param>
	/// <param name="target"></param>
	/// <param name="states"></param>
	template<typename T>
	void drawAll(const std::vector<std::unique_ptr<T>>& vec, sf::RenderTarget& target, const sf::RenderStates& states) const;
};

template<typename T>
inline void World::clean(std::vector<std::unique_ptr<T>>& vec)
{
	vec.erase(
		std::remove_if(
			vec.begin(),
			vec.end(),
			[](const std::unique_ptr<T>& entity) { return entity->toRemove(); }
		),
		vec.end()
	);
}

template<typename T>
inline void World::updateAll(const std::vector<std::unique_ptr<T>>& vec, sf::Time delta)
{
	for (auto&& entity : vec)
		entity->update(delta, *this);
}

template<typename T>
inline void World::drawAll(const std::vector<std::unique_ptr<T>>& vec, sf::RenderTarget& target, const sf::RenderStates& states) const
{
	for (auto&& entity : vec)
		target.draw(*entity, states);
}
