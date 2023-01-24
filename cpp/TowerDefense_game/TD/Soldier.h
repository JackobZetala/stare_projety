#pragma once
#include "Actor.h"
/// <summary>
/// Poukladane stopnie zolnierzy
/// </summary>
enum class SoldierGrade : int
{
	First = 0, // leftmost soldier in tilesheet
	Second,
	Third,
	Fourth // rightmost soldier
};

/// <summary>
/// Zolnierz jest to juz konkretny przeciwnik, dziedziczy po aktorze
/// </summary>
class Soldier : public Actor
{
public:

	/// <summary>
	/// konstruktor
	/// </summary>
	/// <param name="path"></param>
	/// <param name="grade"></param>
	Soldier(const Path& path, SoldierGrade grade);
	static std::unique_ptr<Actor> make(const Path& path, SoldierGrade grade) {
		return std::make_unique<Soldier>(path, grade);
	}
private:
	/// <summary>
	/// Wylicza kolejne wartosci zolnierza w zaleznosci od stopnia
	/// </summary>
	/// <param name="grade"></param>
	/// <returns></returns>
	static int getTextureId(SoldierGrade grade);
	static float getSpeed(SoldierGrade grade);
	static int getHitPoints(SoldierGrade grade);
	static int getWorth(SoldierGrade grade);
};
