#pragma once
#include "Define.h"
#include "Base.h"

#include "Export_Function.h"

BEGIN(Client)

class MainApp : public CBase
{
private:
	explicit MainApp();
	virtual ~MainApp();

public:
	HRESULT		Ready_MainApp();
	_int		Update_MainApp(const _float& fTimeDelta);
	void		Render_MainApp();


public:
	static MainApp*		Create(void);
	virtual void		Free(void);

private:
	LPDIRECT3DDEVICE9		m_pGraphicDev{ nullptr };

	_matrix matWorld;
	_matrix matProj;
	LPDIRECT3DVERTEXBUFFER9 m_pTriangle{ nullptr };
	Engine::VTXCOL m_vtColor;
};

END