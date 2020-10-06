#include "Management.h"

USING(Engine)
IMPLEMENT_SINGLETON(Management)

Management::Management()
{

}

Management::~Management()
{
	Free();
}

void Management::Free(void)
{
	for_each(m_pmapScene.begin(), m_pmapScene.end(), CDeleteMap());
	m_pmapScene.clear();
}

HRESULT Management::Ready_Management(LPDIRECT3DDEVICE9 pGraphicDev, const _tchar* pSceneTag, Scene* pScene)
{
	//pScene = Find_Scene(pSceneTag);

	//if (nullptr != pScene)		// 이미 키값이 존재하면 Fail...
	//	return E_FAIL;

	//NULL_CHECK_RETURN(pScene, E_FAIL);
	m_szSceneTag = pSceneTag;
	m_pmapScene.emplace(pSceneTag, pScene);

	return S_OK;
}

_int Management::Update_Management(const _float & fTimeDelta)
{
	Scene*		pScene = Find_Scene(m_szSceneTag);

	if (nullptr == pScene)
		return 1;

	pScene->Update_Scene(fTimeDelta);
	return 0;
}

void Management::Render_Management()
{
	Scene*		pScene = Find_Scene(m_szSceneTag);

	if (nullptr == pScene)
		return;

	pScene->Render_Scene();
}

Scene * Management::Find_Scene(const _tchar * pSceneTag)
{
	auto iter = find_if(m_pmapScene.begin(), m_pmapScene.end(), CTag_Finder(pSceneTag));

	if (iter == m_pmapScene.end())		//키값을 못찾았을 경우
		return nullptr;
	return iter->second;
}
