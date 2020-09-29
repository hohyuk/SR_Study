#pragma once

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL TriCol : public VIBuffer
{
protected:
	explicit TriCol(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit TriCol(const TriCol& rhs);
	virtual ~TriCol(void);

public:
	virtual HRESULT	Ready_Buffer(void);

public:
	static TriCol*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual void Free(void);
};

END