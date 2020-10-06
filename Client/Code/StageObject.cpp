#include "framework.h"
#include "StageObject.h"

StageObject::StageObject()
{
}

StageObject::StageObject(LPDIRECT3DDEVICE9 pGraphicDev)
{
}

StageObject::~StageObject()
{
}

StageObject * StageObject::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
	return nullptr;
}

void StageObject::Free(void)
{
}

HRESULT StageObject::Ready_GameObject()
{
	return E_NOTIMPL;
}

_int StageObject::Update_GameObject(const _float & fTimeDelta)
{
	return _int();
}

void StageObject::Render_GameObject()
{
}
