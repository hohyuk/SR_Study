#pragma once

#include "Export_Function.h"

USING(Engine)
class KeyManager final
{
	DECLARE_SINGLETON(KeyManager)
public:
	bool UP(const int& iKey);
	bool DOWN(const int& iKey);
	bool Pressing(const int& iKey);
private:
	explicit KeyManager();
	~KeyManager();

private:
	bool KeyInput[256];
	BYTE PrevKey[256];
};

