#pragma once

#include "Export_Function.h"
#include "Scene.h"

USING(Engine)

class StageScene : public Scene
{
protected:
	explicit StageScene(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~StageScene();
public:
	static StageScene*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual void Free(void);

public:
	virtual HRESULT		Ready_Scene();
	virtual _int		Update_Scene(const _float& fTimeDelta);
	virtual void		Render_Scene();

};