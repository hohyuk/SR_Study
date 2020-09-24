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
	Engine::Ready_GraphicDev(g_hWnd, Engine::WINMODE::MODE_WIN, WINCX, WINCY, &m_Dev);
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

}

