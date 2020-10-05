#pragma once
#include "Engine_Define.h"
#include "Base.h"


BEGIN(Engine)

class Management : public CBase
{
	DECLARE_SINGLETON(Management)

private:
	explicit Management();
	virtual ~Management();
public:
	virtual void Free(void);
};

END