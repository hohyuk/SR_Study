#pragma once
#include "Engine_Define.h"
#include "Base.h"

#include "Scene.h"
BEGIN(Engine)

class ENGINE_DLL Management : public CBase
{
	DECLARE_SINGLETON(Management)

private:
	explicit Management();
	virtual ~Management();
public:
	virtual void Free(void);

public:
	HRESULT		Ready_Management(LPDIRECT3DDEVICE9 pGraphicDev, const _tchar* pSceneTag, Scene* pScene);
	_int		Update_Management(const _float& fTimeDelta);
	void		Render_Management();

private:
	Scene*		Find_Scene(const _tchar* pSceneTag);

private:
	map<const _tchar*, Scene*>		m_pmapScene;
	const _tchar* m_szSceneTag;
};

END