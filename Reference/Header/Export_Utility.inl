USING(Engine)
HRESULT Create_Management(Management** ppManagement)
{
	Management*		pManagement = Management::GetInstance();
	NULL_CHECK_RETURN(pManagement, E_FAIL);

	*ppManagement = pManagement;

	return S_OK;
}

HRESULT	SetUp_Scene(Scene* pScene)
{
	return Management::GetInstance()->SetUp_Scene(pScene);
}
_int	Update_Scene(const _float& fTimeDelta)
{
	return Management::GetInstance()->Update_Scene(fTimeDelta);
}
void	Render_Scene(void)
{
	return Management::GetInstance()->Render_Scene();
}

void Release_Utility(void)
{
	Management::GetInstance()->DestroyInstance();
}