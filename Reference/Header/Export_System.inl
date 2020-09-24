
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

inline void Release_System()
{
	Engine::GraphicDev::GetInstance()->DestroyInstance();
}
