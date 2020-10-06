#include "GameObject.h"

USING(Engine)

GameObject::GameObject(LPDIRECT3DDEVICE9 pGraphicDev)
	: m_pGraphicDev(pGraphicDev)
{
	Safe_AddRef(m_pGraphicDev);
}

GameObject::~GameObject()
{
}

void GameObject::Free(void)
{
	for (_uint i = 0; i < ID_END; ++i)
	{
		for_each(m_mapComponent[i].begin(), m_mapComponent[i].end(), CDeleteMap());
		m_mapComponent[i].clear();
	}

	Safe_Release(m_pGraphicDev);
}

_int GameObject::Update_Object(const _float & fTimeDelta)
{
	_int iExit = 0;

	for (auto& iter : m_mapComponent[ID_DYNAMIC])
	{
		iExit = iter.second->Update_Component(fTimeDelta);

		if (iExit & 0x80000000)
		{
			MSG_BOX("Component Problem");
			return -1;
		}
	}

	return iExit;
}
