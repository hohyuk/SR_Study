#pragma once
#include "Engine_Define.h"
#include "Component.h"


BEGIN(Engine)

class ENGINE_DLL TransformComponent : public Component
{
	
protected:
	explicit TransformComponent();
	virtual ~TransformComponent();
public:
	virtual void Free(void);

public:
	virtual HRESULT		Ready_Component();
	virtual _int		Update_Component(const _float& fTimeDelta);
	virtual void		Render_Component();

	void Move();

private:
	_vec3 m_Pos;
	_vec3 m_Rot;
	_vec3 m_Scal;
};

END