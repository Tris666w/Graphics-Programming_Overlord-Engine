#include "stdafx.h"
#include "BombermanGameSettings.h"


BombermanGameSettings::~BombermanGameSettings()
{
}

int BombermanGameSettings::GetAmountOfPlayers() const
{
	return m_AmountOfPLayers;
}

int BombermanGameSettings::GetBlockSize() const
{
	return m_BlockSize;
}

int BombermanGameSettings::GetGridSize() const
{
	return m_GridSize;
}

int BombermanGameSettings::GetWallHeight() const
{
	return m_WallHeight;
}

float BombermanGameSettings::GetBreakableSpawnPercent() const
{
	return m_BreakableSpawnPercentage;
}

float BombermanGameSettings::GetSoundVolume() const
{
	return m_SoundVolume;
}

float BombermanGameSettings::GetMusicVolume() const
{
	return m_MusicVolume;
}

std::wstring BombermanGameSettings::GetPlayerTag() const
{
	return m_PlayerTag;
}

std::wstring BombermanGameSettings::GetDestructibleTag() const
{
	return m_DestructibleTag;
}

std::wstring BombermanGameSettings::GetBombTag() const
{
	return m_BombTag;
}

using SchemePair = std::pair<std::vector<int>, std::wstring>;
const std::unordered_map<InputScheme, SchemePair>& BombermanGameSettings::GetSchemeMap() const
{
	return m_SchemeMap;
}

InputScheme BombermanGameSettings::GetPlayerInputScheme(int playerIndex)
{
	if (static_cast<size_t>(playerIndex) >= m_PlayerSchemes.size() || playerIndex < 0)
		Logger::LogWarning(L"BombermanGameSettings::GetPlayerInputScheme, given playerIndex is out of bounds!");

	return m_PlayerSchemes[playerIndex];
}

void BombermanGameSettings::SetSoundVolume(float volume)
{
	m_SoundVolume = volume;
}

void BombermanGameSettings::SetMusicVolume(float volume)
{
	m_MusicVolume = volume;
}


void BombermanGameSettings::SetAmountOfPlayers(int amountOfPlayers)
{
	m_AmountOfPLayers = amountOfPlayers;
}

void BombermanGameSettings::SetPlayerInput(int playerIndex, InputScheme newScheme)
{
	if (playerIndex >= static_cast<int>(m_PlayerSchemes.size()) || playerIndex < 0)
		Logger::LogError(L"BombermanGameSettings::SetPlayerInput, given index is out of bounds!");
	m_PlayerSchemes[playerIndex] = newScheme;
}


BombermanGameSettings::BombermanGameSettings()
{
	for (int index = 0; index < max_amount_of_players; ++index)
		m_PlayerSchemes.push_back(static_cast<InputScheme>(1));

	m_SchemeMap.insert_or_assign(InputScheme::Keyboard1, std::make_pair
	(std::vector<int>{'A', 'D', 'W', 'S', VK_SPACE}, L"Resources/Textures/InputSchemes/KeyboardScheme1.png"));
	m_SchemeMap.insert_or_assign(InputScheme::Keyboard2, std::make_pair
	(std::vector<int>{VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_RETURN}, L"Resources/Textures/InputSchemes/KeyboardScheme2.png"));


	m_SchemeMap.insert_or_assign(InputScheme::Controller, std::make_pair
	(std::vector<int>{static_cast<int>(GamePadKeys::DPAD_LEFT), static_cast<int>(GamePadKeys::DPAD_RIGHT), static_cast<int>(GamePadKeys::DPAD_UP),
		static_cast<int>(GamePadKeys::DPAD_DOWN), static_cast<int>(GamePadKeys::A)}
	, L"Resources/Textures/InputSchemes/ControllerScheme.png"));

}

