#pragma once
#include "Engine_Define.h"
#include "Base.h"


BEGIN(Engine)

class ENGINE_DLL Component : public CBase
{
	DECLARE_SINGLETON(Component)

private:
	explicit Component();
	virtual ~Component();
public:
	virtual void Free(void);

public:
	virtual HRESULT		Ready_Component();
	virtual _int		Update_Component(const _float& fTimeDelta);
	virtual void		Render_Component();
};

END