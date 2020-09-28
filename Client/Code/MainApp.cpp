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

	m_pGraphicDev->CreateVertexBuffer(3 * sizeof(m_vtColor), D3DUSAGE_WRITEONLY,
		Engine::FVF_COL, D3DPOOL_MANAGED, &m_pTriangle, 0);


	Engine::VTXCOL* v;
	m_pTriangle->Lock(0, 0, (void**)&v, 0);

	v[0] = Engine::VTXCOL(_vec3{ -1.f,-1.f,1.f }, D3DCOLOR_XRGB(255, 0, 0));
	v[1] = Engine::VTXCOL(_vec3{ 0.f,1.f,1.f }, D3DCOLOR_XRGB(0, 255, 0));
	v[2] = Engine::VTXCOL(_vec3{ 1.f,-1.f,1.f }, D3DCOLOR_XRGB(255, 255, 0));
	m_pTriangle->Unlock();

	// 투영 Matrix를 지정
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI * 0.8f,
		1.f/*(float)WINCX / (float)WINCY*/, 1.f, 1000.f);

	m_pGraphicDev->SetTransform(D3DTS_PROJECTION, &matProj);

	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, false);
	m_pGraphicDev->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	return S_OK;
}

_int MainApp::Update_MainApp(const _float& fTimeDelta)
{
	return 0;
}

void MainApp::Render_MainApp(void)
{
	Engine::Render_Begin(D3DXCOLOR(0.f, 0.f, 1.f, 1.f));

	m_pGraphicDev->SetFVF(Engine::FVF_COL);
	m_pGraphicDev->SetStreamSource(0, m_pTriangle, 0, sizeof(Engine::VTXCOL));

	// 삼각형 그리기
	D3DXMatrixTranslation(&matWorld, 0.f, 0.f, 0.f);
	m_pGraphicDev->SetTransform(D3DTS_WORLD, &matWorld);
	
	m_pGraphicDev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
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

