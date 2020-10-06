#pragma once

#include "Export_Function.h"
#include "Scene.h"

USING(Engine)

class LogoScene : public Scene
{
private:
	explicit LogoScene(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~LogoScene(void);

public:
	static LogoScene*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual void Free(void);

public:
	virtual HRESULT		Ready_Scene();
	virtual _int		Update_Scene(const _float& fTimeDelta);
	virtual void		Render_Scene();

private:
	HRESULT		Ready_Resource(Engine::RESOURCETYPE eType);

private:
	_vec3 CameraPos{ 0.f,0.f,-3.f };
	_vec3 m_Pos{ 0.f,0.f,0.f };
	float m_fYRot{ 0.f };
};