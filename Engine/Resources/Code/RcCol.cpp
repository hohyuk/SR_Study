#include "RcCol.h"

USING(Engine)

RcCol::RcCol(LPDIRECT3DDEVICE9 pGraphicDev)
	: VIBuffer{ pGraphicDev }
{
}

RcCol::RcCol(const RcCol & rhs)
	: VIBuffer(rhs)
{
}

RcCol::~RcCol(void)
{
}

HRESULT RcCol::Ready_Buffer(void)
{
	FAILED_CHECK_RETURN(m_pGraphicDev->CreateVertexBuffer(sizeof(VTXCOL) * 4,
		0, // 정적버퍼로 할당하겠다는 옵션
		FVF_COL,
		D3DPOOL_MANAGED,
		&m_pVB,
		NULL),
		E_FAIL);

	VTXCOL*		pVertex = NULL;

	m_pVB->Lock(0, 0, (void**)&pVertex, NULL);

	// 좌측 상단
	pVertex[0].vPos = _vec3(-1.f, 1.f, 0.f);
	pVertex[0].dwColor = D3DXCOLOR(1.f, 0.f, 0.f, 1.f);

	// 우측 상단
	pVertex[1].vPos = _vec3(1.f, 1.f, 0.f);
	pVertex[1].dwColor = D3DXCOLOR(0.f, 1.f, 0.f, 1.f);

	// 우측 하단
	pVertex[2].vPos = _vec3(1.f, -1.f, 0.f);
	pVertex[2].dwColor = D3DXCOLOR(0.f, 0.f, 1.f, 1.f);

	// 좌측 하단
	pVertex[3].vPos = _vec3(-1.f, -1.f, 0.f);
	pVertex[3].dwColor = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);

	m_pVB->Unlock();


	FAILED_CHECK_RETURN(m_pGraphicDev->CreateIndexBuffer(sizeof(WORD) * 6,
		0, // 정적버퍼로 할당하겠다는 옵션
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&m_pIB,
		0),
		E_FAIL);

	WORD* indices = nullptr;
	m_pIB->Lock(0, 0, (void**)&indices, 0);
	indices[0] = 0; indices[1] = 1; indices[2] = 2;

	indices[3] = 0; indices[4] = 2; indices[5] = 3;
	m_pIB->Unlock();


	//// 카메라의 위치 방향 조정
	//D3DXVECTOR3 pos(10.f, 0.f, -3.f);
	//_vec3 target(0.f, 0.f, 0.f);
	//_vec3 up(0.f, 1.f, 0.f);
	//D3DXMATRIX view;
	//D3DXMatrixLookAtLH(&view, &pos, &target, &up);
	//m_pGraphicDev->SetTransform(D3DTS_VIEW, &view);

	//// 투영행렬
	//D3DXMATRIX proj;
	//D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI * 0.5f, (float)WINCX / (float)WINCY, 1.f, 1000.f);
	//m_pGraphicDev->SetTransform(D3DTS_PROJECTION, &proj);
	return S_OK;
}

void RcCol::Render_Buffer(void)
{
	// 그래픽 디바이스 장치에게 현재 내가 그리려는 버퍼를 링크시켜주는 함수
	m_pGraphicDev->SetStreamSource(0, m_pVB, 0, sizeof(VTXCOL));
	m_pGraphicDev->SetIndices(m_pIB);

	m_pGraphicDev->SetFVF(FVF_COL);
	
	m_pGraphicDev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
}

RcCol * RcCol::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	RcCol*	pInstance = new RcCol(pGraphicDev);

	if (FAILED(pInstance->Ready_Buffer()))
		Safe_Release(pInstance);

	return pInstance;
}

void RcCol::Free(void)
{
	VIBuffer::Free();
}
