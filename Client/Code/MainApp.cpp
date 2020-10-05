#include "framework.h"
#include "MainApp.h"
#include "KeyManager.h"


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


	/*{
		FAILED_CHECK_RETURN(Engine::Reserve_ContainerSize(Engine::RESOURCE_END), E_FAIL);
		FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Buffer_TriCol", Engine::BUFFER_TRICOL), E_FAIL);
	}*/
	
	/*{
		FAILED_CHECK_RETURN(Engine::Reserve_ContainerSize(Engine::RESOURCE_END), E_FAIL);
		FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Buffer_RcCol", Engine::BUFFER_RCCOL), E_FAIL);
	}*/

	{
		FAILED_CHECK_RETURN(Engine::Reserve_ContainerSize(Engine::RESOURCE_END), E_FAIL);
		//FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Buffer_CubeCol", Engine::BUFFER_CUBETEX), E_FAIL);
		FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Buffer_RcTex", Engine::BUFFER_RCTEX), E_FAIL);
		FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Texture_Logo", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Logo/Logo.jpg"), E_FAIL);

	}
	Client::Safe_Release(pDeviceClass);


	CameraPos= D3DXVECTOR3(0.f, 0.f, -3.f);
	m_Pos = _vec3(0.f, 0.f, 0.f);
	return S_OK;
}

_int MainApp::Update_MainApp(const _float& fTimeDelta)
{
	
	if (KeyManager::GetInstance()->Pressing('D'))
		CameraPos.x += fTimeDelta;

	if (KeyManager::GetInstance()->Pressing('A'))
		CameraPos.x -= fTimeDelta;

	// 이동
	{
		if (KeyManager::GetInstance()->Pressing(VK_RIGHT))
			m_Pos.x += fTimeDelta;
		if (KeyManager::GetInstance()->Pressing(VK_LEFT))
			m_Pos.x -= fTimeDelta;
		if (KeyManager::GetInstance()->Pressing(VK_UP))
			m_Pos.y += fTimeDelta;
		if (KeyManager::GetInstance()->Pressing(VK_DOWN))
			m_Pos.y -= fTimeDelta;
	}
	// 줌인 줌아웃
	{
		if (KeyManager::GetInstance()->Pressing('Z'))
			m_Pos.z += fTimeDelta;

		if (KeyManager::GetInstance()->Pressing('X'))
			m_Pos.z -= fTimeDelta;
	}
	// 회전
	{
		if (KeyManager::GetInstance()->Pressing('C'))
			m_fYRot += 5.f;
	}
	// 카메라의 위치 방향 조정
	_vec3 target(0.f, 0.f, 1.f);
	_vec3 up(0.f, 1.f, 0.f);
	D3DXMATRIX view;
	D3DXMatrixLookAtLH(&view, &CameraPos, &target, &up);
	m_pGraphicDev->SetTransform(D3DTS_VIEW, &view);

	// 투영행렬
	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI * 0.5f, (float)WINCX / (float)WINCY, 1.f, 1000.f);
	m_pGraphicDev->SetTransform(D3DTS_PROJECTION, &proj);


	// 월드 행렬
	D3DXMATRIX matTrans, matRotY;
	D3DXMatrixRotationY(&matRotY, D3DXToRadian(m_fYRot));
	D3DXMatrixTranslation(&matTrans, m_Pos.x, m_Pos.y, m_Pos.z);
	D3DXMATRIX world = matRotY * matTrans;

	
	m_pGraphicDev->SetTransform(D3DTS_WORLD, &world);
	return 0;
}

void MainApp::Render_MainApp(void)
{
	Engine::Render_Begin(D3DXCOLOR(0.f, 0.f, 1.f, 1.f));
	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);
	Engine::Render_Texture(Engine::RESOURCE_STATIC, L"Texture_Logo", 0);
	Engine::Render_Buffer(Engine::RESOURCE_STATIC, L"Buffer_RcTex");

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

