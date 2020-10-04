#pragma once

#include "Engine_Define.h"
#include "Base.h"

#include "TriCol.h"
#include "RcCol.h"
#include "Cube.h"
BEGIN(Engine)

class ENGINE_DLL ResourcesMgr : public CBase
{
	DECLARE_SINGLETON(ResourcesMgr)

private:
	explicit ResourcesMgr();
	virtual ~ResourcesMgr();

public:
	HRESULT		Reserve_ContainerSize(const _ushort& wSize);
	HRESULT		Ready_Buffer(LPDIRECT3DDEVICE9 pGraphicDev,
		const _ushort& wContainerIdx,
		const _tchar* pBufferTag,
		BUFFERID eID,
		_ulong dwCntX = 1,
		_ulong dwCntZ = 1,
		_ulong dwItv = 1);

	void		Render_Buffer(const _ushort& wContainerIdx, const _tchar* pBufferTag);


private:
	Resources*		Find_Resources(const _ushort& wContainerIdx, const _tchar* pResourcesTag);

private:
	map<const _tchar*, Resources*>*		m_pmapResource;
	_ushort									m_wSize = 0;

public:
	virtual void Free(void);
};

END