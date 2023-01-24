#pragma once

#include <memory>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "SceneChangeRequest.h"
/// <summary>
/// Klasa nadrzeda wsrod scen
/// Tworzy wirtualne metody oraz metode ktora moze zazadac zmiany sceny
/// </summary>
class Scene : public sf::Drawable
{
public:
	/// <summary>
	/// Destruktor
	/// </summary>
	virtual ~Scene() { }
	/// <summary>
	/// Metoda trzymajaca informacje o jakims wejsciu
	/// </summary>
	/// <param name="event"></param>
	virtual void handleInput(const sf::Event& event) = 0;
	/// <summary>
	/// Metoda do aktualizowania sceny
	/// </summary>
	/// <param name="delta"></param>
	virtual void update(sf::Time delta) = 0;
	/// <summary>
	/// Metoda sprawdzajaca zadanie zmiany sceny
	/// </summary>
	bool isSceneChangeRequested() const { return sceneChangeRequest != nullptr; }
	/// <summary>
	/// Przetrzymuje na jaka scene bedzie zamiana
	/// </summary>
	/// <returns></returns>
	SceneChangeRequestPtr takeSceneChangeRequest() { return std::move(sceneChangeRequest); }
protected:
	/// <summary>
	/// Zadanie zmiany sceny
	/// </summary>
	/// <param name="request"></param>
	void requestSceneChange(SceneChangeRequest request);
private:
	SceneChangeRequestPtr sceneChangeRequest;
};

using ScenePtr = std::unique_ptr<Scene>;
