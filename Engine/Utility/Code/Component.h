#pragma once
#include "Engine_Define.h"
#include "Base.h"


BEGIN(Engine)

class ENGINE_DLL Component : public CBase
{
	
protected:
	explicit Component();
	explicit Component(const Component& rhs);
	virtual ~Component();

public:
	virtual _int		Update_Component(const _float& fTimeDelta);

protected:
	virtual Component*		Clone(void) = 0;
	virtual void			Free(void) = 0;
};

END