#include "framework.h"
#include "MainApp.h"
#include "KeyManager.h"
#include "LogoScene.h"
#include "StageScene.h"
MainApp::MainApp(void)
{

}

MainApp::~MainApp(void)
{

}

HRESULT MainApp::Ready_MainApp(void)
{
	Engine::GraphicDev*		pDeviceClass{ nullptr };

	FAILED_CHECK_RETURN(Engine::Ready_GraphicDev(g_hWnd, Engine::MODE_WIN, WINCX, WINCY, &pDeviceClass), E_FAIL);
	pDeviceClass->AddRef();
	
	m_pGraphicDev = pDeviceClass->Get_GraphicDev();
	m_pGraphicDev->AddRef();

	// 1, Management생성 어떤 씬을 할지 결정?
	// 필요한것 디바이스, 리소스 스테이지??(이건 잘모르겠다...) L"logo"
	FAILED_CHECK_RETURN(Engine::Ready_Management(m_pGraphicDev, L"Logo", LogoScene::Create(m_pGraphicDev)), E_FAIL);

	Client::Safe_Release(pDeviceClass);

	return S_OK;
}

_int MainApp::Update_MainApp(const _float& fTimeDelta)
{
	Engine::Update_Management(fTimeDelta);
	
	return 0;
}

void MainApp::Render_MainApp(void)
{
	Engine::Render_Begin(D3DXCOLOR(0.f, 0.f, 1.f, 1.f));
	
	//Engine::Render_Texture(Engine::RESOURCE_STATIC, L"Texture_Logo", 0);
	//Engine::Render_Buffer(Engine::RESOURCE_STATIC, L"Buffer_RcTex");
	Engine::Render_Management();
	Engine::Render_End();
}

MainApp* MainApp::Create(void)
{
	MainApp*	pInstance = new MainApp;

	if (FAILED(pInstance->Ready_MainApp()))
	{
		MSG_BOX("CMainApp Create Failed");
		Safe_Release(pInstance);
	}

	return pInstance;
}

void MainApp::Free(void)
{
	Client::Safe_Release(m_pGraphicDev);

	Engine::Release_System();
}

