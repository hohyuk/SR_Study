#pragma once

#include "Scene.h"

BEGIN(Engine)

class ENGINE_DLL Management : public CBase
{
	DECLARE_SINGLETON(Management)

private:
	explicit Management(void);
	virtual ~Management(void);

public:
	HRESULT	SetUp_Scene(Scene* pScene);
	_int	Update_Scene(const _float& fTimeDelta);
	void	Render_Scene(void);

private:
	Scene*			m_pScene;

public:
	virtual void Free(void);
};

END