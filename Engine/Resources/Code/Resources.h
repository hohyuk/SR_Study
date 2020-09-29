#pragma once

#include "Engine_Define.h"
#include "Base.h"

BEGIN(Engine)

class ENGINE_DLL Resources : public CBase
{
protected:
	explicit	 Resources(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit	 Resources(const Resources& rhs);
	virtual		~Resources();

public:
	virtual void		Free(void);

protected:
	LPDIRECT3DDEVICE9			m_pGraphicDev;
};

END