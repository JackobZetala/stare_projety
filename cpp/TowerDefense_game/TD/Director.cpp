#include "Director.h"
#include <memory>
#include "App.h"

Director::Director() :
	waveNumber(0),
	wave()
{
}

void Director::update(sf::Time delta, World& world)
{
	if (!wave || (wave->isEmpty() && world.getActors().empty()))
		wave = makeWave(++waveNumber, world.getGrid().getPath());
	if (app.handleKeyboard())
		makeWave(++waveNumber, world.getGrid().getPath());
	auto next = wave->maybeSendNext(delta);
	if (next)
		world.getActors().push_back(std::move(next));
	
}

WavePtr Director::makeWave(int number, const Path& path)
{
	switch (number)
	{
	case 1:
		return std::make_unique<Wave>(SoldierGrade::First, 5, path, Wave::SPACING_HUGE);
	case 2:
		return std::make_unique<Wave>(SoldierGrade::Second, 3, path, Wave::SPACING_WIDE);
	case 3:
		return std::make_unique<Wave>(SoldierGrade::Third, 3, path, Wave::SPACING_WIDE);
	case 4:
		return std::make_unique<Wave>(SoldierGrade::Fourth, 3, path, Wave::SPACING_MEDIUM);
	case 5:
		return std::make_unique<Wave>(SoldierGrade::Second, 7, path, Wave::SPACING_MEDIUM);
	default:
		if (number % 2 == 1)
			return std::make_unique<Wave>(SoldierGrade::Fourth, 1 + (number - 21) * 2, path, Wave::SPACING_NARROW);
		return 0;
	}
}
