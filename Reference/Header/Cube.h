#pragma once

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL Cube : public VIBuffer
{
protected:
	explicit Cube(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit Cube(const Cube& rhs);
	virtual ~Cube(void);

public:
	virtual HRESULT	Ready_Buffer(void);
	virtual void	Render_Buffer(void);
public:
	static Cube*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual void Free(void);
};

END