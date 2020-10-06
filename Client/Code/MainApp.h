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
	HRESULT		SetUp_DefaultSetting(LPDIRECT3DDEVICE9* ppGraphicDev);
	HRESULT		Ready_Scene(LPDIRECT3DDEVICE9 pGraphicDev, Engine::Management** ppManagement);


private:
	LPDIRECT3DDEVICE9		m_pGraphicDev{ nullptr };

private:
	Engine::GraphicDev*		m_pDeviceClass = nullptr;
	Engine::Management*		m_pManagementClass = nullptr;
};

END