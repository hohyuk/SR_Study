#include "Management.h"

USING(Engine)
IMPLEMENT_SINGLETON(Management)

Management::Management(void)
	: m_pScene(nullptr)
{

}

Management::~Management(void)
{
	Free();
}

HRESULT Management::SetUp_Scene(Scene * pScene)
{
	Safe_Release(m_pScene);			// 

	m_pScene = pScene;

	return S_OK;
}

_int Management::Update_Scene(const _float & fTimeDelta)
{
	if (nullptr == m_pScene)
		return -1;

	m_pScene->Update_Scene(fTimeDelta);

	return 0;
}

void Management::Render_Scene(void)
{
	if (nullptr == m_pScene)
		return;

	m_pScene->Render_Scene();
}

void Management::Free(void)
{
	Safe_Release(m_pScene);
}


