#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
/// <summary>
/// Sektor jest to pozycja jednego kafelka/kwadrtatu na mapie o rozmiarze 64x64 (ale zostaje pozniej przeskalowane)
/// Sektory maja swoj wlasny uklad wspolrzednych 
/// Czasami potrzebne jest przejscie ze wspolrzednych sektorow na wspolrzedne gry lub na odwrot, sa do tego zrobione metody
/// 
/// </summary>
struct Sector
{
	int x;
	int y;

	/// <summary>
	/// Przejscie ze wspolrzednych sectora na wspolrzedne gry
	/// </summary>
	/// <returns>Zwraca zamieniony vektor</returns>
	sf::Vector2f upperLeftPoint() const;
	sf::Vector2f upperRightPoint() const;
	sf::Vector2f bottomLeftPoint() const;
	sf::Vector2f midpoint() const;
	bool operator==(const Sector& rhs) const;

	/// <summary>
	/// Przejscie ze wsplrzednych gry na wspolrzedne sectora razem z fromCoords(const coords)
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="xCoord"></param>
	/// <param name="yCoord"></param>
	/// <returns></returns>
	template<typename T>
	static Sector fromCoords(T xCoord, T yCoord);
	template<typename T>
	static Sector fromCoords(const sf::Vector2<T>& coords);

	/// <summary>
	/// d³ugosc jednego kafelka/kwadrata
	/// </summary>
	static const int SIZE;

	/// <summary>
	/// przekatna kafelka/kwadrata
	/// </summary>
	static const sf::Vector2f DIAGONAL;

	/// <summary>
	/// srodek kafelka/kwadrata
	/// </summary>
	static const sf::Vector2f CENTER;

	/// <summary>
	/// ilosc kafelkow mieszczacych sie na Tilesheet
	/// </summary>
	static const int TILESHEET_WIDTH;

	/// <summary>
	/// skala
	/// </summary>
	static const float SCALE_FACTOR;

	/// <summary>
	/// odwrocona skala
	/// </summary>
	static const float INVERSE_SCALE_FACTOR;
};

Sector operator+(const Sector& lhs, const Sector& rhs);

using Path = std::vector<Sector>;
using PathIterator = Path::const_iterator;

/// <summary>
/// Wartosc vektora do kwadratu
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="vec"></param>
/// <returns></returns>
template<typename T>
T lengthSquared(const sf::Vector2<T>& vec) 
{
	return vec.x * vec.x + vec.y * vec.y;
}

/// <summary>
/// normalizuje vector 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="vec"></param>
/// <returns>zwraca znormalizowany vektor o tym samym kacie</returns>
template<typename T>
sf::Vector2<T> normalize(const sf::Vector2<T>& vec) // returns vector with the same angle, length 1
{
	if (vec.x == 0 && vec.y == 0)
		return vec;
	return vec / static_cast<T>(sqrt(lengthSquared(vec)));
}

template<typename T>
inline Sector Sector::fromCoords(T xCoord, T yCoord)
{
	return Sector{ static_cast<int>(xCoord) / SIZE, static_cast<int>(yCoord) / SIZE };
}

template<typename T>
inline Sector Sector::fromCoords(const sf::Vector2<T>& coords)
{
	return fromCoords(coords.x, coords.y);
}

/// <summary>
/// wyluskanie kata w radianach z vektora funkcja atan2
/// </summary>
/// <param name="vec"></param>
/// <returns></returns>
inline float angleRadians(const sf::Vector2f& vec)
{
	return static_cast<float>(atan2(vec.y, vec.x));
}

/// <summary>
/// zamiana stopni na radiany
/// </summary>
/// <param name="alpha"></param>
/// <returns></returns>
inline float toRadians(float alpha) // degrees to radians
{
	return alpha * 180.f / 3.14159265f;
}

/// <summary>
/// prostokat z tilesheet brany z textureId, bazuje na kafelkach/kwadratach 
/// </summary>
/// <param name="textureId"></param>
/// <returns></returns>
sf::IntRect textureRectById(int textureId);

/// <summary>
/// z trzech podanych wartosci wylicza predkosc
/// </summary>
/// <param name="direction"></param>
/// <param name="moveSpeed"></param>
/// <param name="delta"></param>
/// <returns></returns>
sf::Vector2f velocity(const sf::Vector2f& direction, float moveSpeed, sf::Time delta);

/// <summary>
/// zwraca kat vektora
/// </summary>
/// <param name="vec"></param>
/// <returns></returns>
float angle(const sf::Vector2f& vec);

/// <summary>
/// tworzenie vektora z radianow
/// </summary>
/// <param name="radians"></param>
/// <returns></returns>
sf::Vector2f vectorFromRadians(float radians);

/// <summary>
/// dodaje skale do poruszania sie myszki razem z transformMouseCoordinates(int,int)
/// </summary>
/// <param name="vec"></param>
/// <returns></returns>
sf::Vector2f transformMouseCoordinates(const sf::Vector2i& vec); // adjust for scale
sf::Vector2f transformMouseCoordinates(int x, int y);
