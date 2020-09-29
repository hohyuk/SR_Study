#include "TriCol.h"

USING(Engine)

TriCol::TriCol(LPDIRECT3DDEVICE9 pGraphicDev)
	: VIBuffer{ pGraphicDev }
{
}

TriCol::TriCol(const TriCol & rhs)
	: VIBuffer(rhs)
{
}

TriCol::~TriCol(void)
{
}

HRESULT TriCol::Ready_Buffer(void)
{
	FAILED_CHECK_RETURN(CVIBuffer::Ready_Buffer(), E_FAIL);

	return S_OK;
}

TriCol * TriCol::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	TriCol*	pInstance = new TriCol(pGraphicDev);

	if (FAILED(pInstance->Ready_Buffer()))
		Safe_Release(pInstance);

	return pInstance;
}

void TriCol::Free(void)
{
	VIBuffer::Free();
}
