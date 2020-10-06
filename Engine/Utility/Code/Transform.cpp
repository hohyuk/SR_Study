#include "Transform.h"

USING(Engine)

TransformComponent::TransformComponent()
{
}

TransformComponent::~TransformComponent()
{
}

void TransformComponent::Free(void)
{
}

HRESULT TransformComponent::Ready_Component()
{
	return E_NOTIMPL;
}

_int TransformComponent::Update_Component(const _float & fTimeDelta)
{
	return _int();
}

void TransformComponent::Render_Component()
{
}

void TransformComponent::Move()
{
}
