#include "Cube.h"

USING(Engine)

Cube::Cube(LPDIRECT3DDEVICE9 pGraphicDev)
	: VIBuffer{ pGraphicDev }
{
}

Cube::Cube(const Cube & rhs)
	: VIBuffer(rhs)
{
}

Cube::~Cube(void)
{
}

HRESULT Cube::Ready_Buffer(void)
{
	FAILED_CHECK_RETURN(m_pGraphicDev->CreateVertexBuffer(sizeof(VTXCOL) * 8,
		0, // 정적버퍼로 할당하겠다는 옵션
		FVF_COL,
		D3DPOOL_MANAGED,
		&m_pVB,
		NULL),
		E_FAIL);

	VTXCOL*		pVertex = NULL;

	m_pVB->Lock(0, 0, (void**)&pVertex, NULL);

	pVertex[0].vPos = _vec3(-1.f, -1.f, -1.f);
	pVertex[1].vPos = _vec3(-1.f, 1.f, -1.f);
	pVertex[2].vPos = _vec3(1.f,  1.f, -1.f);
	pVertex[3].vPos = _vec3(1.f, -1.f, -1.f);

	pVertex[4].vPos = _vec3(-1.f, -1.f, 1.f);
	pVertex[5].vPos = _vec3(-1.f, 1.f,  1.f);
	pVertex[6].vPos = _vec3(1.f,  1.f,  1.f);
	pVertex[7].vPos = _vec3(1.f, -1.f,  1.f);



	pVertex[0].dwColor = D3DXCOLOR(1.f, 0.f, 0.f, 1.f);
	pVertex[1].dwColor = D3DXCOLOR(0.f, 1.f, 0.f, 1.f);
	pVertex[2].dwColor = D3DXCOLOR(1.f, 0.f, 1.f, 1.f);
	pVertex[3].dwColor = D3DXCOLOR(1.f, 1.f, 0.f, 1.f);

	pVertex[4].dwColor = D3DXCOLOR(0.f, 1.f, 0.f, 1.f);
	pVertex[5].dwColor = D3DXCOLOR(0.f, 1.f, 0.f, 1.f);
	pVertex[6].dwColor = D3DXCOLOR(0.f, 1.f, 0.f, 1.f);
	pVertex[7].dwColor = D3DXCOLOR(0.f, 1.f, 0.f, 1.f);
	m_pVB->Unlock();


	FAILED_CHECK_RETURN(m_pGraphicDev->CreateIndexBuffer(sizeof(WORD) * 36,
		0, // 정적버퍼로 할당하겠다는 옵션
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&m_pIB,
		0),
		E_FAIL);

	WORD* indices = nullptr;
	m_pIB->Lock(0, 0, (void**)&indices, 0);
	// 전면
	indices[0] = 0; indices[1] = 1; indices[2] = 2;
	indices[3] = 0; indices[4] = 2; indices[5] = 3;

	// 후면
	indices[6] = 4; indices[7] = 6; indices[8] = 5;
	indices[9] = 4; indices[10] = 7; indices[11] = 6;

	// 왼쪽측면
	indices[12] = 4; indices[13] = 5; indices[14] = 1;
	indices[15] = 4; indices[16] = 1; indices[17] = 0;

	// 오른쪽측면
	indices[18] = 3; indices[19] = 2; indices[20] = 6;
	indices[21] = 3; indices[22] = 6; indices[23] = 7;

	// 상단
	indices[24] = 1; indices[25] = 5; indices[26] = 6;
	indices[27] = 1; indices[28] = 6; indices[29] = 2;

	// 하단
	indices[30] = 4; indices[31] = 0; indices[32] = 3;
	indices[33] = 4; indices[34] = 3; indices[35] = 7;
	m_pIB->Unlock();

	return S_OK;
}

void Cube::Render_Buffer(void)
{
	// 그래픽 디바이스 장치에게 현재 내가 그리려는 버퍼를 링크시켜주는 함수
	m_pGraphicDev->SetStreamSource(0, m_pVB, 0, sizeof(VTXCOL));
	m_pGraphicDev->SetIndices(m_pIB);

	m_pGraphicDev->SetFVF(FVF_COL);
	
	m_pGraphicDev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);
}

Cube * Cube::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	Cube*	pInstance = new Cube(pGraphicDev);

	if (FAILED(pInstance->Ready_Buffer()))
		Safe_Release(pInstance);

	return pInstance;
}

void Cube::Free(void)
{
	VIBuffer::Free();
}
