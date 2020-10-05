#pragma once
#include "Engine_Define.h"
#include "Base.h"


BEGIN(Engine)

class Component : public CBase
{
	DECLARE_SINGLETON(Component)

private:
	explicit Component();
	virtual ~Component();
public:
	virtual void Free(void);
};

END