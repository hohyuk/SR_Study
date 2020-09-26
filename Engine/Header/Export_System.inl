
inline HRESULT  Ready_GraphicDev(HWND hWnd, Engine::WINMODE eMode,
	const Engine::_uint& iSizeX, const Engine::_uint& iSizeY, Engine::GraphicDev** ppGraphicDev)
{
	return Engine::GraphicDev::GetInstance()->Ready_GraphicDev(hWnd, eMode, iSizeX, iSizeY, ppGraphicDev);
}

inline void Render_Begin(D3DXCOLOR Color)
{
	Engine::GraphicDev::GetInstance()->Render_Begin(Color);
}
inline void Render_End()
{
	Engine::GraphicDev::GetInstance()->Render_End();
}

Engine::_float Get_TimeDelta(const Engine::_tchar* pTimerTag)
{
	return Engine::TimerMgr::GetInstance()->Get_TimeDelta(pTimerTag);
}

void Set_TimeDelta(const Engine::_tchar* pTimerTag)
{
	Engine::TimerMgr::GetInstance()->Set_TimeDelta(pTimerTag);
}

HRESULT	Ready_Timer(const Engine::_tchar* pTimerTag)
{
	return Engine::TimerMgr::GetInstance()->Ready_Timer(pTimerTag);
}


Engine::_bool		IsPermit_Call(const Engine::_tchar* pFrameTag, const Engine::_float& fTimeDelta)
{
	return Engine::FrameMgr::GetInstance()->IsPermit_Call(pFrameTag, fTimeDelta);
}
HRESULT		Ready_Frame(const Engine::_tchar* pFrameTag, const Engine::_float& fCallLimit)
{
	return Engine::FrameMgr::GetInstance()->Ready_Frame(pFrameTag, fCallLimit);
}




inline void Release_System()
{
	Engine::TimerMgr::DestroyInstance();
	Engine::FrameMgr::DestroyInstance();
	Engine::GraphicDev::GetInstance()->DestroyInstance();
}
