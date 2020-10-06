#include "Layer.h"

USING(Engine)
Layer::Layer()
{
}

Layer::~Layer()
{
}

Layer * Layer::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	Layer*		pInstance = new Layer;

	if (FAILED(pInstance->Ready_Layer()))
		Safe_Release(pInstance);

	return pInstance;
}

void Layer::Free(void)
{
	for_each(m_mapObject.begin(), m_mapObject.end(), CDeleteMap());
	m_mapObject.clear();
}

HRESULT Layer::Ready_Layer()
{
	return S_OK;
}

_int Layer::Update_Layer(const _float & fTimeDelta)
{
	_int iExit = 0;

	for (auto& iter : m_mapObject)
	{
		iExit = iter.second->Update_Object(fTimeDelta);

		if (iExit & 0x80000000)
		{
			MSG_BOX("GameObject Problem");
			return iExit;
		}
	}

	return iExit;
}

void Layer::Render_Layer()
{
	for (auto& iter : m_mapObject)
		iter.second->Render_Object();
}
