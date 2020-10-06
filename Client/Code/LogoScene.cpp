#include "framework.h"
#include "LogoScene.h"
#include "KeyManager.h"
#include "StageScene.h"
LogoScene::LogoScene()
{
}

LogoScene::LogoScene(LPDIRECT3DDEVICE9 pGraphicDev)
	:Scene{pGraphicDev}
{
}

LogoScene::~LogoScene()
{
}

LogoScene * LogoScene::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	LogoScene*	pInstance = new LogoScene(pGraphicDev);

	if (FAILED(pInstance->Ready_Scene()))
		Safe_Release(pInstance);

	return pInstance;
}

void LogoScene::Free(void)
{
}

HRESULT LogoScene::Ready_Scene()
{
	FAILED_CHECK_RETURN(Engine::Reserve_ContainerSize(Engine::RESOURCE_END), E_FAIL);

	FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Buffer_RcTex", Engine::BUFFER_RCTEX), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Texture_Logo", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Logo/Logo.jpg"), E_FAIL);

	CameraPos = D3DXVECTOR3(0.f, 0.f, -3.f);
	m_Pos = _vec3(0.f, 0.f, 0.f);
	return S_OK;
}

_int LogoScene::Update_Scene(const _float & fTimeDelta)
{
	if (KeyManager::GetInstance()->DOWN('Q'))
	{
		FAILED_CHECK_RETURN(Engine::Ready_Management(m_pGraphicDev, L"Stage", StageScene::Create(m_pGraphicDev)), E_FAIL);
	}

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

void LogoScene::Render_Scene()
{
	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);
	Engine::Render_Texture(Engine::RESOURCE_STATIC, L"Texture_Logo", 0);
	Engine::Render_Buffer(Engine::RESOURCE_STATIC, L"Buffer_RcTex");
}
