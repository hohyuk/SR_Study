#pragma once

#include "Export_Function.h"
#include "GameObject.h"

USING(Engine)

class StageObject : public GameObject
{
protected:
	explicit StageObject();
	explicit StageObject(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~StageObject();
public:
	static StageObject*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual void	Free(void);

public:
	virtual HRESULT		Ready_GameObject();
	virtual _int		Update_GameObject(const _float& fTimeDelta);
	virtual void		Render_GameObject();


};