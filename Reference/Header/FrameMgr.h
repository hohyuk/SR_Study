#pragma once

#include "Engine_Define.h"
#include "Frame.h"

BEGIN(Engine)

class ENGINE_DLL FrameMgr : public CBase
{
	DECLARE_SINGLETON(FrameMgr)

private:
	explicit FrameMgr();
	virtual ~FrameMgr();

public:
	_bool IsPermit_Call(const _tchar* pFrameTag, const _float& fTimeDelta);

	HRESULT Ready_Frame(const _tchar* pFrameTag, const _float& fCallLimit);

private:
	Frame* Find_Frame(const _tchar* pFrameTag);

public:
	virtual void Free();
private:
	map<const _tchar*, Frame*> m_mapFrame;
};
END