#include "framework.h"
#include "StageScene.h"

StageScene::StageScene()
{
}

StageScene::StageScene(LPDIRECT3DDEVICE9 pGraphicDev)
	:Scene{pGraphicDev}
{
}

StageScene::~StageScene()
{
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
}

HRESULT StageScene::Ready_Scene()
{
	FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Buffer_RcTex1", Engine::BUFFER_RCTEX), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Texture_Logo1", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/LogoBack/LogoBack_0.png"), E_FAIL);

	return S_OK;
}

_int StageScene::Update_Scene(const _float & fTimeDelta)
{
	return _int();
}

void StageScene::Render_Scene()
{
	Engine::Render_Texture(Engine::RESOURCE_STATIC, L"Texture_Logo1", 0);
	Engine::Render_Buffer(Engine::RESOURCE_STATIC, L"Buffer_RcTex1");
}
