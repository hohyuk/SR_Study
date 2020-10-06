#pragma once

#include "Export_Function.h"
#include "GameObject.h"

USING(Engine)
class Player;
class Monster : public GameObject
{
private:
	explicit Monster(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~Monster(void);

public:
	static Monster*	Create(LPDIRECT3DDEVICE9 pGraphicDev, Player* pPlayer);
	virtual void Free(void);

public:
	virtual HRESULT			Ready_Object(void);
	virtual _int			Update_Object(const _float& fTimeDelta);
	virtual void			Render_Object(void);

private:
	_vec3 CameraPos{ 0.f,0.f,-3.f };
	_vec3 m_Pos{ 0.f,0.f,0.f };
	_vec3 m_Dir{ 0.f,0.f,0.f };
	float m_fYRot{ 0.f };
	_matrix m_matLocal;
	float m_fSpeed;
	Player* m_pPlayer{ nullptr };
};