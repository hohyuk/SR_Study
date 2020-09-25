#pragma once

#include "Engine_Define.h"
#include "Base.h"

BEGIN(Engine)

class ENGINE_DLL Timer : public CBase
{
private:
	explicit			Timer();
	virtual				~Timer();

public:
	_float				Get_TimeDelta()const { return m_fTimeDelta; }

public:
	HRESULT				Ready_Timer();
	void				SetUp_TimeDelta();

public:
	static	Timer*		Create();
	virtual void		Free();

private:
	_float		m_fTimeDelta;

private:
	LARGE_INTEGER		m_FrameTime;
	LARGE_INTEGER		m_FixTime;
	LARGE_INTEGER		m_LastTime;
	LARGE_INTEGER		m_CpuTick;
};

END