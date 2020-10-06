#pragma once
#include "Engine_Define.h"
#include "Base.h"
BEGIN(Engine)

class ENGINE_DLL Scene : public CBase
{
protected:
	explicit Scene();
	explicit Scene(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~Scene();
public:
	static Scene*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual void Free(void);

public:
	virtual HRESULT		Ready_Scene();
	virtual _int		Update_Scene(const _float& fTimeDelta);
	virtual void		Render_Scene();

protected:
	LPDIRECT3DDEVICE9			m_pGraphicDev;
};

END