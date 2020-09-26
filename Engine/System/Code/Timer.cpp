#include "Timer.h"

USING(Engine)

Timer::Timer()
	: m_fTimeDelta{0.f}
{
}

Timer::~Timer()
{
}

HRESULT Timer::Ready_Timer()
{
	// QueryPerformanceCounter - 고해상도 타이머의 현재 CPU의 클럭수를 얻는 함수
	QueryPerformanceCounter(&m_FrameTime);
	QueryPerformanceCounter(&m_LastTime);

	QueryPerformanceCounter(&m_FixTime);

	// QueryPerformanceFrequency - 고해상도 타이머의 주파수(1초당 진동수)를 반환한다.
	QueryPerformanceFrequency(&m_CpuTick);

	return S_OK;
}

void Timer::SetUp_TimeDelta()
{
	QueryPerformanceCounter(&m_FrameTime);

	if (m_FrameTime.QuadPart - m_FixTime.QuadPart >= m_CpuTick.QuadPart)
	{
		QueryPerformanceFrequency(&m_CpuTick);
		m_FixTime = m_FrameTime;
	}

	m_fTimeDelta = (_float(m_FrameTime.QuadPart) - _float(m_LastTime.QuadPart)) / (_float)m_CpuTick.QuadPart;

	m_LastTime = m_FrameTime;
}

Timer * Timer::Create()
{
	Timer* pInstance = new Timer;

	if (FAILED(pInstance->Ready_Timer()))
		Safe_Release(pInstance);

	return pInstance;
}

void Timer::Free()
{
}
