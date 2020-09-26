#include "framework.h"
#include "MainApp.h"



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

	Client::Safe_Release(pDeviceClass);
	return S_OK;
}

_int MainApp::Update_MainApp(const _float& fTimeDelta)
{
	return 0;
}

void MainApp::Render_MainApp(void)
{
	Engine::Render_Begin(D3DXCOLOR(0.f, 0.f, 1.f, 1.f));

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

