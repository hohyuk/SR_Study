#pragma once

#include "Export_Function.h"
#include "Scene.h"

USING(Engine)

class LogoScene : public Scene
{
protected:
	explicit LogoScene();
	explicit LogoScene(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~LogoScene();
public:
	static LogoScene*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual void Free(void);

public:
	virtual HRESULT		Ready_Scene();
	virtual _int		Update_Scene(const _float& fTimeDelta);
	virtual void		Render_Scene();

	// Test
private:
	_vec3 CameraPos;
	_vec3 m_Pos;
	float m_fYRot{};
};