#pragma once
#include "Sector.h"
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
/// <summary>
/// Siatka jest to prostokat zlozony z sektorow, ktore maja powiazana teksture
/// Tekstura przypisana do sektora reprezentowana przez liczbe na tilesheet
/// Numeracja kafelkow w tilesheet jest od lewego gornego rogu i liczby zwiekszaja sie od lewej do prawej i potem kolejny wiersz
/// Siataka zachowuje takze sciezke po ktorej podazaja aktorzy
/// </summary>
class Grid : public sf::Drawable
{
public:
	/// <summary>
	/// konstruktor
	/// </summary>
	Grid();
	/// <summary>
	/// zwraca kordy sektora razem z blockAt(int,int)
	/// </summary>
	/// <param name="sector"></param>
	/// <returns></returns>
	int blockAt(const Sector& sector) const { return blocks[sector.y][sector.x]; };
	int blockAt(int x, int y) const { return blocks[y][x]; }

	/// <summary>
	/// sprawdza czy w danycm sektorze nie ma juz czegos zbudowanego
	/// </summary>
	/// <param name="sector"></param>
	/// <returns></returns>
	bool isBuildingAllowedAt(const Sector& sector) const;

	/// <summary>
	/// nadpisana virtualna metoda do rysowania obiektu w danym miejscu
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	/// <summary>
	/// zwraca sciezke po ktorej poruszaja sie aktorzy
	/// </summary>
	/// <returns></returns>
	const Path& getPath() const { return path; } 
private:
	int width;
	int height;
	std::vector<std::vector<int>> blocks;
	Path path;

	/// <summary>
	/// sprawdza czy na tym sektorze jest dozwolone budowanie 
	/// </summary>
	/// <param name="block"></param>
	/// <returns></returns>
	bool isBuildingAllowedOn(int block) const;
};

