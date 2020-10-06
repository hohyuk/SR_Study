USING(Engine)

HRESULT		Ready_Management(LPDIRECT3DDEVICE9 pGraphicDev, const _tchar* pSceneTag, Scene* pScene)
{
	return Management::GetInstance()->Ready_Management(pGraphicDev, pSceneTag, pScene);
}

_int		Update_Management(const _float& fTimeDelta)
{
	return Management::GetInstance()->Update_Management(fTimeDelta);
}

void		Render_Management()
{
	Management::GetInstance()->Render_Management();
}

// Release Management
void Release_Management()
{
	Management::GetInstance()->DestroyInstance();
}