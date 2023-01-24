#pragma once
#include "World.h"
#include "Wave.h"
/// <summary>
/// Rezyser tworzy i zarzdza falami, moze byc maksymalnie jedna fala
/// Gdy swiat sie oczysci to automatycznie generuje sie kolejna fala
/// Pierwsze 5 fal jest takie same potem sa generowane liniowo kolejne fale
/// Zarzadza obiektami WavePtr
/// </summary>
class Director
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	Director();

	/// <summary>
	/// metoda aktualizujaca stan fali
	/// </summary>
	/// <param name="delta"></param>
	/// <param name="world"></param>
	void update(sf::Time delta, World& world);

	/// <summary>
	/// pobiera numer fali
	/// </summary>
	/// <returns></returns>
	int getWaveNumber() const { return waveNumber; }
private:
	int waveNumber;
	WavePtr wave;
	App app;
	/// <summary>
	/// tworzy fale
	/// </summary>
	/// <param name="number"></param>
	/// <param name="path"></param>
	/// <returns></returns>
	static WavePtr makeWave(int number, const Path& path);
};

