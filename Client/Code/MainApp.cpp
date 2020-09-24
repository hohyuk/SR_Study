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
	return S_OK;
}

_int MainApp::Update_MainApp(const _float& fTimeDelta)
{
	return 0;
}

void MainApp::Render_MainApp(void)
{

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

