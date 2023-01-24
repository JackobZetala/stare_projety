#include "GameOverScene.h"
#include "Sector.h"

GameOverScene::GameOverScene(int waveNumber) :
	TextScene(
		(std::string("Doszedles do fali numer: ") + std::to_string(waveNumber)).c_str(),
		"Wcisnij jakis przycisk aby zaczac jescze raz",
		SceneType::Game
	)
{
}
