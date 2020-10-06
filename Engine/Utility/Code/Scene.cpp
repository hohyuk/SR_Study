#include "Scene.h"

#include "Export_Resouces.h"
#include "ResourcesMgr.h"
USING(Engine)

Scene::Scene()
{

}

Scene::Scene(LPDIRECT3DDEVICE9 pGraphicDev)
	:m_pGraphicDev{pGraphicDev}
{
	Safe_AddRef(m_pGraphicDev);
}

Scene::~Scene()
{
}

Scene * Scene::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	Scene*	pInstance = new Scene(pGraphicDev);

	if (FAILED(pInstance->Ready_Scene()))
		Safe_Release(pInstance);

	return pInstance;
}

void Scene::Free(void)
{
	Safe_Release(m_pGraphicDev);
}

HRESULT Scene::Ready_Scene()
{
	//FAILED_CHECK_RETURN(Engine::Reserve_ContainerSize(Engine::RESOURCE_END), E_FAIL);

	//FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Buffer_RcTex", Engine::BUFFER_RCTEX), E_FAIL);
	//FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Texture_Logo", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Logo/Logo.jpg"), E_FAIL);

	return S_OK;
}

_int Scene::Update_Scene(const _float & fTimeDelta)
{
	return 0;
}

void Scene::Render_Scene()
{
	/*Engine::Render_Texture(Engine::RESOURCE_STATIC, L"Texture_Logo", 0);
	Engine::Render_Buffer(Engine::RESOURCE_STATIC, L"Buffer_RcTex");*/
}
