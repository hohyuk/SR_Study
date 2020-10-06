#include "framework.h"
#include "LogoScene.h"
#include "StageScene.h"
#include "Player.h"
#include "Monster.h"

LogoScene::LogoScene(LPDIRECT3DDEVICE9 pGraphicDev)
	:Scene{pGraphicDev}
{
}

LogoScene::~LogoScene()
{
	Scene::Free();
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
	Engine::Scene::Free();
}

HRESULT LogoScene::Ready_Scene()
{
	FAILED_CHECK_RETURN(Ready_Resource(RESOURCE_END), E_FAIL);

	return S_OK;
}

_int LogoScene::Update_Scene(const _float & fTimeDelta)
{
	m_pMonster->Update_Object(fTimeDelta);
	m_pPlayer->Update_Object(fTimeDelta);
	return 0;
}

void LogoScene::Render_Scene()
{
	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_pMonster->Render_Object();
	m_pPlayer->Render_Object();
	/*Engine::Render_Texture(Engine::RESOURCE_STATIC, L"Texture_Logo", 0);
	Engine::Render_Buffer(Engine::RESOURCE_STATIC, L"Buffer_RcTex");*/
}

HRESULT LogoScene::Ready_Resource(Engine::RESOURCETYPE eType)
{
	FAILED_CHECK_RETURN(Engine::Reserve_ContainerSize(eType), E_FAIL);

	m_pPlayer = Player::Create(m_pGraphicDev);
	m_pMonster = Monster::Create(m_pGraphicDev, m_pPlayer);
	return S_OK;
}
