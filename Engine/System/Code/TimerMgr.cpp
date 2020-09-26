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
	// Ÿ�̸� �±׶�� Ű���� ���� ã�´�.
	Timer* pTimer = Find_Timer(pTimerTag);

	if (nullptr != pTimer)		// �̹� Ű���� �����ϸ� Fail...
		return E_FAIL;

	pTimer = Timer::Create();		// ���ο� Ÿ�̸Ӹ� �������ش�.
	NULL_CHECK_RETURN(pTimer, E_FAIL);

	m_mapTimers.emplace(pTimerTag, pTimer);		// map�� ����ش�.
	return S_OK;
}

Timer * TimerMgr::Find_Timer(const _tchar * pTimerTag)
{
	// �����ڷ� ã�� ������ �ּҰ��� �ƴ϶� ������ ���ڿ��� ã������
	auto iter = find_if(m_mapTimers.begin(), m_mapTimers.end(), CTag_Finder(pTimerTag));

	if (iter == m_mapTimers.end())		//Ű���� ��ã���� ���
		return nullptr;
	return iter->second;
}
