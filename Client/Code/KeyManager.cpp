#include "framework.h"
#include "KeyManager.h"

IMPLEMENT_SINGLETON(KeyManager)

bool KeyManager::UP(const int& iKey)
{
	if (!Pressing(iKey))
	{
		if (PrevKey[iKey] == iKey)
		{
			PrevKey[iKey] = NULL;
			return true;
		}
	}
	return false;
}

bool KeyManager::DOWN(const int& iKey)
{
	if (GetAsyncKeyState(iKey) & 0x8000)
	{
		if (!KeyInput[iKey])
		{
			KeyInput[iKey] = true;
			return true;
		}
	}
	else KeyInput[iKey] = false;

	return false;
}

bool KeyManager::Pressing(const int& iKey)
{
	if (GetAsyncKeyState(iKey) & 0x8000)
	{
		PrevKey[iKey] = iKey;
		return true;
	}
	return false;
}

KeyManager::KeyManager()
{
	ZeroMemory(KeyInput, sizeof(KeyInput));
	ZeroMemory(PrevKey, sizeof(PrevKey));
}

KeyManager::~KeyManager()
{
}
