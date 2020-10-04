#pragma once

#include "ResourcesMgr.h"

BEGIN(Engine)
inline HRESULT		Reserve_ContainerSize(const _ushort& wSize);
inline HRESULT		Ready_Buffer(LPDIRECT3DDEVICE9 pGraphicDev, const _ushort& wContainerIdx, const _tchar* pBufferTag, BUFFERID eID, _ulong dwCntX = 1, _ulong dwCntZ = 1, _ulong dwItv = 1);
inline void		Render_Buffer(const _ushort& wContainerIdx, const _tchar* pBufferTag);

// Release Resources
inline void Release_Resoures();

#include "Export_Resouces.inl"
END