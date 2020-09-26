#pragma once

#include "Engine_Define.h"
#include "Base.h"
BEGIN(Engine)

class ENGINE_DLL Frame : public CBase
{
private:
	explicit Frame(void);
	virtual ~Frame(void);
public:
	_bool IsRermit_Call(const _float& fTimeDelta);
public:
	HRESULT Ready_Frame(const _float& fCallLimit);
public:
	static Frame*		Create(const _float& fCallLimit);
	virtual void		Free(void);

private:
	_float m_fCallLimit;
	_float m_fAccTimeDelta;
};
END