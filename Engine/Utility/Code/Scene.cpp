#include "Scene.h"

USING(Engine)

Scene::Scene(LPDIRECT3DDEVICE9 pGraphicDev)
	:m_pGraphicDev{pGraphicDev}
{
	Safe_AddRef(m_pGraphicDev);
}

Scene::~Scene()
{
	Free();
}

void Scene::Free(void)
{
	for_each(m_mapLayer.begin(), m_mapLayer.end(), CDeleteMap());
	m_mapLayer.clear();

	Safe_Release(m_pGraphicDev);
}

HRESULT Scene::Ready_Scene()
{
	return S_OK;
}

_int Scene::Update_Scene(const _float & fTimeDelta)
{
	_int iExit = 0;

	for (auto& iter : m_mapLayer)
	{
		iExit = iter.second->Update_Layer(fTimeDelta);

		if (iExit & 0x80000000)
		{
			MSG_BOX("Layer Problem");
			return iExit;
		}
	}

	return iExit;
}

void Scene::Render_Scene()
{
	for (auto& iter : m_mapLayer)
		iter.second->Render_Layer();
}
