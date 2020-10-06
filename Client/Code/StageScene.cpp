#include "framework.h"
#include "StageScene.h"
#include "KeyManager.h"


StageScene::StageScene(LPDIRECT3DDEVICE9 pGraphicDev)
	:Scene{pGraphicDev}
{
}

StageScene::~StageScene()
{
	Scene::Free();
}

StageScene * StageScene::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	StageScene*	pInstance = new StageScene(pGraphicDev);

	if (FAILED(pInstance->Ready_Scene()))
		Safe_Release(pInstance);

	return pInstance;
}

void StageScene::Free(void)
{
	Engine::Scene::Free();
}

HRESULT StageScene::Ready_Scene()
{
	
	return S_OK;
}

_int StageScene::Update_Scene(const _float & fTimeDelta)
{
	// 이동
	//{
	//	if (KeyManager::GetInstance()->Pressing(VK_RIGHT))
	//		m_Pos.x += fTimeDelta;
	//	if (KeyManager::GetInstance()->Pressing(VK_LEFT))
	//		m_Pos.x -= fTimeDelta;
	//	if (KeyManager::GetInstance()->Pressing(VK_UP))
	//		m_Pos.y += fTimeDelta;
	//	if (KeyManager::GetInstance()->Pressing(VK_DOWN))
	//		m_Pos.y -= fTimeDelta;
	//}
	//// 카메라의 위치 방향 조정
	//_vec3 target(0.f, 0.f, 1.f);
	//_vec3 up(0.f, 1.f, 0.f);
	//D3DXMATRIX view;
	//D3DXMatrixLookAtLH(&view, &CameraPos, &target, &up);
	//m_pGraphicDev->SetTransform(D3DTS_VIEW, &view);

	//// 투영행렬
	//D3DXMATRIX proj;
	//D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI * 0.5f, (float)WINCX / (float)WINCY, 1.f, 1000.f);
	//m_pGraphicDev->SetTransform(D3DTS_PROJECTION, &proj);


	//// 월드 행렬
	//D3DXMATRIX matTrans, matRotY;
	//D3DXMatrixRotationY(&matRotY, D3DXToRadian(m_fYRot));
	//D3DXMatrixTranslation(&matTrans, m_Pos.x, m_Pos.y, m_Pos.z);
	//D3DXMATRIX world = matRotY * matTrans;
	//m_pGraphicDev->SetTransform(D3DTS_WORLD, &world);
	return 0;
}

void StageScene::Render_Scene()
{
	/*Engine::Render_Texture(Engine::RESOURCE_STATIC, L"Texture_Stage", 0);
	Engine::Render_Buffer(Engine::RESOURCE_STATIC, L"Buffer_RcTex");*/
}
