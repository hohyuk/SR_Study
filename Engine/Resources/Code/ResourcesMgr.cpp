#include "ResourcesMgr.h"

USING(Engine)
IMPLEMENT_SINGLETON(ResourcesMgr)

ResourcesMgr::ResourcesMgr()
	:m_pmapResource{ nullptr }
{

}

ResourcesMgr::~ResourcesMgr()
{
	Free();
}

HRESULT ResourcesMgr::Reserve_ContainerSize(const _ushort & wSize)
{
	if (nullptr != m_pmapResource)
		return E_FAIL;

	m_wSize = wSize;

	m_pmapResource = new map<const _tchar*, Resources*>[wSize];

	return S_OK;
}

HRESULT ResourcesMgr::Ready_Buffer(LPDIRECT3DDEVICE9 pGraphicDev, const _ushort & wContainerIdx, const _tchar * pBufferTag, BUFFERID eID, _ulong dwCntX, _ulong dwCntZ, _ulong dwItv)
{
	if (nullptr == m_pmapResource)
	{
		MSG_BOX("Resource Container not Reserved");
		return E_FAIL;
	}

	Resources*		pResources = Find_Resources(wContainerIdx, pBufferTag);
	if (nullptr != pResources)
		return E_FAIL;

	switch (eID)
	{
	case BUFFER_TRICOL:
		pResources = TriCol::Create(pGraphicDev);
		break;
	case BUFFER_RCTEX:
		pResources = CRcTex::Create(pGraphicDev);
		break;
	}
	NULL_CHECK_RETURN(pResources, E_FAIL);

	m_pmapResource[wContainerIdx].emplace(pBufferTag, pResources);

	return S_OK;
}

HRESULT ResourcesMgr::Ready_Texture(LPDIRECT3DDEVICE9 pGraphicDev, const _ushort & wContainerIdx, const _tchar * pTextureTag, TEXTURETYPE eType, const _tchar * pFilePath, const _uint & iCnt)
{
	if (nullptr == m_pmapResource)
	{
		MSG_BOX("Resource Container not Reserved");
		return E_FAIL;
	}

	Resources*		pResources = Find_Resources(wContainerIdx, pTextureTag);
	if (nullptr != pResources)
		return E_FAIL;

	pResources = CTexture::Create(pGraphicDev, pFilePath, eType, iCnt);
	NULL_CHECK_RETURN(pResources, E_FAIL);

	m_pmapResource[wContainerIdx].emplace(pTextureTag, pResources);

	return S_OK;
}

void ResourcesMgr::Render_Buffer(const _ushort & wContainerIdx, const _tchar * pBufferTag)
{
	Resources*		pResources = Find_Resources(wContainerIdx, pBufferTag);

	if (nullptr == pResources)
		return;

	dynamic_cast<VIBuffer*>(pResources)->Render_Buffer();
}

void ResourcesMgr::Render_Texture(const _ushort & wContainerIdx, const _tchar * pTextureTag, const _uint & iIndex)
{
	Resources*		pResources = Find_Resources(wContainerIdx, pTextureTag);

	if (nullptr == pResources)
		return;

	dynamic_cast<CTexture*>(pResources)->Render_Texture(iIndex);
}

Resources * ResourcesMgr::Find_Resources(const _ushort & wContainerIdx, const _tchar * pResourcesTag)
{
	auto	iter = find_if(m_pmapResource[wContainerIdx].begin(),
		m_pmapResource[wContainerIdx].end(), CTag_Finder(pResourcesTag));

	if (iter == m_pmapResource[wContainerIdx].end())
		return nullptr;

	return iter->second;
}

void ResourcesMgr::Free(void)
{
	for (_uint i = 0; i < m_wSize; ++i)
	{
		for_each(m_pmapResource[i].begin(), m_pmapResource[i].end(), CDeleteMap());
		m_pmapResource[i].clear();
	}
	Safe_Delete_Array(m_pmapResource);
}
