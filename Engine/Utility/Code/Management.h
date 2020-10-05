#pragma once
#include "Engine_Define.h"
#include "Base.h"


BEGIN(Engine)

class Management : public CBase
{
	DECLARE_SINGLETON(Management)

private:
	explicit Management();
	virtual ~Management();
public:
	virtual void Free(void);

public:
	HRESULT		Ready_Management();
	_int		Update_Management(const _float& fTimeDelta);
	void		Render_Management();
};

END