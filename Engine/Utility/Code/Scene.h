#pragma once

#include "Layer.h"

BEGIN(Engine)

class Layer;
class ENGINE_DLL Scene : public CBase
{
protected:
	explicit Scene(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~Scene();
public:
	virtual void Free(void);

public:
	virtual HRESULT		Ready_Scene();
	virtual _int		Update_Scene(const _float& fTimeDelta);
	virtual void		Render_Scene();

protected:
	LPDIRECT3DDEVICE9			m_pGraphicDev;
	map<const _tchar*, Layer*>		m_mapLayer;
};

END