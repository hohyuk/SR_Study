#pragma once

#include "GameObject.h"

BEGIN(Engine)

class ENGINE_DLL Layer : public CBase
{
private:
	explicit Layer();
	virtual ~Layer();

public:
	static Layer*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual void	Free(void);

public:
	virtual HRESULT		Ready_Layer();
	virtual _int		Update_Layer(const _float& fTimeDelta);
	virtual void		Render_Layer();


private:
	map<const _tchar*, GameObject*>			m_mapObject;
};

END