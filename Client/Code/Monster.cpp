#include "framework.h"
#include "Monster.h"
#include "Player.h"

Monster::Monster(LPDIRECT3DDEVICE9 pGraphicDev)
	:GameObject{pGraphicDev}
{
}

Monster::~Monster(void)
{
}

Monster * Monster::Create(LPDIRECT3DDEVICE9 pGraphicDev, Player* pPlayer)
{
	Monster*	pInstance = new Monster(pGraphicDev);

	if (nullptr == dynamic_cast<Monster*>(pInstance)->m_pPlayer)
		dynamic_cast<Monster*>(pInstance)->m_pPlayer = pPlayer;
	if (FAILED(pInstance->Ready_Object()))
		Safe_Release(pInstance);

	return pInstance;
}

void Monster::Free(void)
{
}

HRESULT Monster::Ready_Object(void)
{
	FAILED_CHECK_RETURN(Engine::Ready_Buffer(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Buffer_Monster", Engine::BUFFER_RCTEX), E_FAIL);
	FAILED_CHECK_RETURN(Engine::Ready_Texture(m_pGraphicDev, Engine::RESOURCE_STATIC, L"Texture_Monster", Engine::TEX_NORMAL, L"../Bin/Resource/Texture/Logo/Logo.jpg"), E_FAIL);

	m_Pos = _vec3{ -2.f,0.f,0.f };
	return S_OK;
}

_int Monster::Update_Object(const _float & fTimeDelta)
{
	if (m_pPlayer)
	{
		Engine::Distance_Dir(m_Dir, m_pPlayer->Get_Pos(), m_Pos);

		if (Distance_Pos(m_pPlayer->Get_Pos(), m_Pos) >= 0.1)
		{
			m_Pos.x += m_Dir.x*fTimeDelta / 2.f;
			m_Pos.y += m_Dir.y*fTimeDelta / 2.f;
			m_Pos.z += m_Dir.z*fTimeDelta / 2.f;
		}
	}
	
	

	D3DXMATRIX matTrans, matRotY;
	D3DXMatrixRotationY(&matRotY, D3DXToRadian(m_fYRot));
	D3DXMatrixTranslation(&matTrans, m_Pos.x, m_Pos.y, m_Pos.z);
	m_matLocal = matRotY * matTrans;
	
	return 0;
}

void Monster::Render_Object(void)
{
	m_pGraphicDev->SetTransform(D3DTS_WORLD, &m_matLocal);
	Engine::Render_Texture(Engine::RESOURCE_STATIC, L"Texture_Monster", 0);
	Engine::Render_Buffer(Engine::RESOURCE_STATIC, L"Buffer_Monster");
}
