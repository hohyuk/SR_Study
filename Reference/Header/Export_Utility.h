#pragma once

#include "Management.h"

BEGIN(Engine)

inline HRESULT		Ready_Management(LPDIRECT3DDEVICE9 pGraphicDev, const _tchar* pSceneTag, Scene* pScene);
inline _int		Update_Management(const _float& fTimeDelta);
inline void		Render_Management();
// Release_Utility
inline void Release_Management();

#include "Export_Utility.inl"
END