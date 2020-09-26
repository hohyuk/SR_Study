#include "TimerMgr.h"

USING(Engine)

IMPLEMENT_SINGLETON(TimerMgr)

TimerMgr:: TimerMgr()
{

}
TimerMgr::~TimerMgr()
{
	Free();
}

void TimerMgr::Free()
{
	for_each(m_mapTimers.begin(), m_mapTimers.end(), CDeleteMap());
	m_mapTimers.clear();
}

_float TimerMgr::Get_TimeDelta(const _tchar * pTimerTag)
{
	Timer* pTimer = Find_Timer(pTimerTag);

	if (nullptr == pTimer)
		return 0.f;
	return pTimer->Get_TimeDelta();
}

void TimerMgr::Set_TimeDelta(const _tchar * pTimerTag)
{
	Timer* pTimer = Find_Timer(pTimerTag);

	if (nullptr == pTimer)
		return;

	pTimer->SetUp_TimeDelta();
}

HRESULT TimerMgr::Ready_Timer(const _tchar * pTimerTag)
{
	// 타이머 태그라는 키값을 먼저 찾는다.
	Timer* pTimer = Find_Timer(pTimerTag);

	if (nullptr != pTimer)		// 이미 키값이 존재하면 Fail...
		return E_FAIL;

	pTimer = Timer::Create();		// 새로운 타이머를 생성해준다.
	NULL_CHECK_RETURN(pTimer, E_FAIL);

	m_mapTimers.emplace(pTimerTag, pTimer);		// map에 담아준다.
	return S_OK;
}

Timer * TimerMgr::Find_Timer(const _tchar * pTimerTag)
{
	// 조건자로 찾는 이유는 주소값이 아니라 오로지 문자열로 찾기위함
	auto iter = find_if(m_mapTimers.begin(), m_mapTimers.end(), CTag_Finder(pTimerTag));

	if (iter == m_mapTimers.end())		//키값을 못찾았을 경우
		return nullptr;
	return iter->second;
}
