USING(Engine)

HRESULT		Reserve_ContainerSize(const _ushort& wSize)
{
	return ResourcesMgr::GetInstance()->Reserve_ContainerSize(wSize);
}
HRESULT		Ready_Buffer(LPDIRECT3DDEVICE9 pGraphicDev, const _ushort& wContainerIdx, const _tchar* pBufferTag, BUFFERID eID, _ulong dwCntX, _ulong dwCntZ, _ulong dwItv)
{
	return ResourcesMgr::GetInstance()->Ready_Buffer(pGraphicDev, wContainerIdx, pBufferTag, eID, dwCntX, dwCntZ, dwItv);
}
void		Render_Buffer(const _ushort& wContainerIdx, const _tchar* pBufferTag)
{
	ResourcesMgr::GetInstance()->Render_Buffer(wContainerIdx, pBufferTag);
}

// Release Resources
void Release_Resoures()
{
	ResourcesMgr::GetInstance()->DestroyInstance();
}