#include "Frame.h"

USING(Engine)

Frame::Frame(void)
	: m_fCallLimit{0.f},
	m_fAccTimeDelta{0.f}
{
}

Frame::~Frame(void)
{
}

_bool Frame::IsRermit_Call(const _float & fTimeDelta)
{
	m_fAccTimeDelta += fTimeDelta;

	if (m_fAccTimeDelta >= m_fCallLimit)
	{
		m_fAccTimeDelta = 0.f;
		return true;
	}
	return false;
}

HRESULT Frame::Ready_Frame(const _float & fCallLimit)
{
	m_fCallLimit = 1.f / fCallLimit;
	return S_OK;
}

Frame * Frame::Create(const _float & fCallLimit)
{
	Frame* pInstance = new Frame;

	if (FAILED(pInstance->Ready_Frame(fCallLimit)))
		Safe_Release(pInstance);

	return pInstance;
}

void Frame::Free(void)
{
}
