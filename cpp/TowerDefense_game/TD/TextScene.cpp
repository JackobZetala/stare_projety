#include "TextScene.h"
#include "Sector.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "Assets.h"

static const sf::Color TEXT_COLOR = sf::Color(10, 10, 10);

TextScene::TextScene(const char* primaryText, const char* secondaryText, SceneType nextScene) :
	firstly(),
	secondly(),
	nextScene(nextScene)
{
	firstly.setString(primaryText);
	firstly.setCharacterSize(Sector::SIZE * 2);
	firstly.setFillColor(TEXT_COLOR);
	firstly.setPosition(Sector{ 2, 2 }.upperLeftPoint());
	secondly.setString(secondaryText);
	secondly.setCharacterSize(Sector::SIZE);
	secondly.setFillColor(TEXT_COLOR);
	secondly.setPosition(Sector{ 2, 7 }.upperLeftPoint());
	auto& assets = Assets::get();
}

void TextScene::handleInput(const sf::Event& event)
{
	if (event.type == sf::Event::EventType::KeyPressed)
		requestSceneChange(SceneChangeRequest { nextScene });
}

void TextScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(firstly, states);
	target.draw(secondly, states);
}
