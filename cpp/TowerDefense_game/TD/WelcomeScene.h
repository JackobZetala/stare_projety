#pragma once
#include "TextScene.h"
/// <summary>
/// Scena powitalna z info co za gra i kto wykonal
/// </summary>
class WelcomeScene : public TextScene
{
public:
	WelcomeScene();
	virtual void update(sf::Time delta) override {};
};
