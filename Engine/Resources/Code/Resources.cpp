#include "Resources.h"

USING(Engine)

Resources::Resources(LPDIRECT3DDEVICE9 pGraphicDev)
	:m_pGraphicDev{ pGraphicDev }
{
	Safe_AddRef(m_pGraphicDev);
}

Resources::Resources(const Resources & rhs)
	:m_pGraphicDev{rhs.m_pGraphicDev}
{
	Safe_AddRef(m_pGraphicDev);
}

Resources::~Resources()
{
}

void Resources::Free(void)
{
	Safe_Release(m_pGraphicDev);
}
