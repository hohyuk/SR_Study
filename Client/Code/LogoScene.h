#pragma once

#include "Export_Function.h"
#include "Scene.h"

USING(Engine)

class Player;
class Monster;

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
	Player* m_pPlayer{ nullptr };
	Monster* m_pMonster{ nullptr };
};