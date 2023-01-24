#pragma once

#include <memory>
#include "SceneType.h"

/// <summary>
/// Struktura przechowujaca ktora scena i ktora fala
/// </summary>
struct SceneChangeRequest
{
	SceneType targetScene;
	int waveNumber;
};

using SceneChangeRequestPtr = std::unique_ptr<SceneChangeRequest>;
