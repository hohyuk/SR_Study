#include "FrameMgr.h"

USING(Engine)

IMPLEMENT_SINGLETON(FrameMgr)

FrameMgr::FrameMgr()
{

}

FrameMgr::~FrameMgr()
{
	Free();
}

_bool FrameMgr::IsPermit_Call(const _tchar * pFrameTag, const _float & fTimeDelta)
{
	Frame* pFrame = Find_Frame(pFrameTag);
	NULL_CHECK_RETURN(pFrame, false);

	return pFrame->IsRermit_Call(fTimeDelta);
}

HRESULT FrameMgr::Ready_Frame(const _tchar * pFrameTag, const _float & fCallLimit)
{
	Frame* pFrame = Find_Frame(pFrameTag);

	if (nullptr != pFrame)
		return E_FAIL;

	pFrame = Frame::Create(fCallLimit);
	NULL_CHECK_RETURN(pFrame, E_FAIL);

	m_mapFrame.emplace(pFrameTag, pFrame);
	return S_OK;
}

Frame * FrameMgr::Find_Frame(const _tchar * pFrameTag)
{
	auto iter = find_if(m_mapFrame.begin(), m_mapFrame.end(), CTag_Finder(pFrameTag));

	if (iter == m_mapFrame.end())
		return nullptr;

	return iter->second;
}

void FrameMgr::Free()
{
	for_each(m_mapFrame.begin(), m_mapFrame.end(), CDeleteMap());
	m_mapFrame.clear();
}
