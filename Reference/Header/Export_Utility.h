#pragma once

#include "Management.h"

BEGIN(Engine)

inline HRESULT Create_Management(Management** ppManagement);
inline HRESULT	SetUp_Scene(Scene* pScene);
inline _int	Update_Scene(const _float& fTimeDelta);
inline void	Render_Scene(void);

inline void Release_Utility(void);

#include "Export_Utility.inl"
END