#include "Component.h"

USING(Engine)
IMPLEMENT_SINGLETON(Component)

Component::Component()
{

}

Component::~Component()
{
	Free();
}

void Component::Free(void)
{
}

HRESULT Component::Ready_Component()
{
	return E_NOTIMPL;
}

_int Component::Update_Component(const _float & fTimeDelta)
{
	return _int();
}

void Component::Render_Component()
{
}
