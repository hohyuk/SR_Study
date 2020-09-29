#pragma once

#include "Resources.h"

BEGIN(Engine)

class ENGINE_DLL VIBuffer : public Resources
{
protected:
	explicit VIBuffer(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit VIBuffer(const VIBuffer& rhs);
	virtual ~VIBuffer(void);

public:
	virtual HRESULT	Ready_Buffer(void);
	virtual void	Render_Buffer(void);

	virtual void Free(void);
protected:
	LPDIRECT3DVERTEXBUFFER9		m_pVB;
	LPDIRECT3DINDEXBUFFER9		m_pIB;

public:
};