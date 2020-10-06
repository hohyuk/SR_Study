#pragma once

#include "Component.h"

BEGIN(Engine)

class ENGINE_DLL GameObject : public CBase
{
protected:
	explicit GameObject(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~GameObject();

public:
	virtual void	Free(void);

public:
	virtual HRESULT			Ready_Object(void) { return S_OK; };
	virtual _int			Update_Object(const _float& fTimeDelta);
	virtual void			Render_Object(void) {};

protected:
	LPDIRECT3DDEVICE9						m_pGraphicDev;
	map<const _tchar*, Component*>			m_mapComponent[ID_END];
};

END