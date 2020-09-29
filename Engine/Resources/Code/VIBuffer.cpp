#include "VIBuffer.h"

USING(Engine)

VIBuffer::VIBuffer(LPDIRECT3DDEVICE9 pGraphicDev)
	:Resources{ pGraphicDev },
	m_pVB{nullptr},m_pIB{nullptr}
{
}

VIBuffer::VIBuffer(const VIBuffer & rhs)
	: Resources(rhs),
	m_pVB{ rhs.m_pVB }, m_pIB{ rhs.m_pIB }
{
	Safe_AddRef(m_pVB);
	Safe_AddRef(m_pIB);
}

VIBuffer::~VIBuffer(void)
{
}

HRESULT VIBuffer::Ready_Buffer(void)
{
	FAILED_CHECK_RETURN(m_pGraphicDev->CreateVertexBuffer(sizeof(VTXCOL) * 3,
		0, // �������۷� �Ҵ��ϰڴٴ� �ɼ�
		FVF_COL,
		D3DPOOL_MANAGED,
		&m_pVB,
		NULL),
		E_FAIL);

	VTXCOL*		pVertex = NULL;

	m_pVB->Lock(0, 0, (void**)&pVertex, NULL);
	// 1���� : ��𼭺��� ��� ���ΰ�
	// 2���� : ���ڰ� 0�̸� ��ü ������ ��ٴ�.
	// 3���� : ���ڰ��� ���ؼ� ���ؽ� ���� �� ���� �� ù��° �ּҸ� ���´�.
	// 4���� : ��״� ���¸� ���� ����, ���� ������ ��� 0

	pVertex[0].vPos = _vec3(0.f, 1.f, 0.f);
	pVertex[0].dwColor = D3DXCOLOR(1.f, 0.f, 0.f, 1.f);

	pVertex[1].vPos = _vec3(1.f, -1.f, 0.f);
	pVertex[1].dwColor = D3DXCOLOR(0.f, 1.f, 0.f, 1.f);

	pVertex[2].vPos = _vec3(-1.f, -1.f, 0.f);
	pVertex[2].dwColor = D3DXCOLOR(0.f, 0.f, 1.f, 1.f);

	m_pVB->Unlock();

	return S_OK;
}

void VIBuffer::Render_Buffer(void)
{
	// �׷��� ����̽� ��ġ���� ���� ���� �׸����� ���۸� ��ũ�����ִ� �Լ�
	m_pGraphicDev->SetStreamSource(0, m_pVB, 0, sizeof(VTXCOL));
	// 1���� : �� �� ���Կ� ������ ���ΰ�
	// 2���� : � ���� �Ѱ��� ���ΰ�
	// 3���� : ��𼭺��� �׸� ���ΰ�
	// 4���� : � ������ ǥ���� ���ΰ�

	m_pGraphicDev->SetFVF(FVF_COL);
	m_pGraphicDev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
}

void VIBuffer::Free(void)
{
	Safe_Release(m_pVB);
	Safe_Release(m_pIB);

	Resources::Free();
}
