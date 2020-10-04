#pragma once

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL RcCol : public VIBuffer
{
protected:
	explicit RcCol(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit RcCol(const RcCol& rhs);
	virtual ~RcCol(void);

public:
	virtual HRESULT	Ready_Buffer(void);
	virtual void	Render_Buffer(void);
public:
	static RcCol*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual void Free(void);
};

END