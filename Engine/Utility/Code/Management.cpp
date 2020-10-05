#include "Management.h"

USING(Engine)
IMPLEMENT_SINGLETON(Management)

Management::Management()
{

}

Management::~Management()
{
	Free();
}

void Management::Free(void)
{
}

HRESULT Management::Ready_Management()
{
	return S_OK;
}

_int Management::Update_Management(const _float & fTimeDelta)
{
	return 0;
}

void Management::Render_Management()
{
}
