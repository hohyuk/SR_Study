#pragma once
#include "Define.h"
#include "Base.h"

BEGIN(Client)

class MainApp : public CBase
{
private:
	explicit MainApp();
	virtual ~MainApp();

public:
	HRESULT		Ready_MainApp();
	_int		Update_MainApp(const _float& fTimeDelta);
	void		Render_MainApp();


public:
	static MainApp*		Create(void);
	virtual void		Free(void);
};

END