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
	// QueryPerformanceCounter - ���ػ� Ÿ�̸��� ���� CPU�� Ŭ������ ��� �Լ�
	QueryPerformanceCounter(&m_FrameTime);
	QueryPerformanceCounter(&m_LastTime);

	QueryPerformanceCounter(&m_FixTime);

	// QueryPerformanceFrequency - ���ػ� Ÿ�̸��� ���ļ�(1�ʴ� ������)�� ��ȯ�Ѵ�.
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
