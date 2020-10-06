#pragma once

#include "Export_Function.h"
#include "GameObject.h"

USING(Engine)

class Player : public GameObject
{
public:
	_vec3 Get_Pos()const { return m_Pos; }
private:
	explicit Player(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual ~Player(void);

public:
	static Player*	Create(LPDIRECT3DDEVICE9 pGraphicDev);
	virtual void Free(void);

public:
	virtual HRESULT			Ready_Object(void);
	virtual _int			Update_Object(const _float& fTimeDelta);
	virtual void			Render_Object(void);

private:
	_vec3 CameraPos{ 0.f,0.f,-3.f };
	_vec3 m_Pos{ 0.f,0.f,0.f };
	float m_fYRot{ 0.f };
	_matrix m_matLocal;
};