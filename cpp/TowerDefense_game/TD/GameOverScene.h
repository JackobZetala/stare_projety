#pragma once
#include "TextScene.h"
/// <summary>
/// Scena po przegranej pokazujaca do ktorrej fali dotrwal gracz
/// Po nacisnieciu dowolnego przycisku przekierowuje do GameScene
/// </summary>
class GameOverScene : public TextScene
{
public:
	GameOverScene(int waveNumber);
	virtual void update(sf::Time delta) override {};
};
