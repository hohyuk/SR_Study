#ifndef Texture_h__
#define Texture_h__

#include "Resources.h"

BEGIN(Engine)

class ENGINE_DLL CTexture : public Resources
{
private:
	explicit CTexture(LPDIRECT3DDEVICE9 pGraphicDev);
	explicit CTexture(const CTexture& rhs);
	virtual ~CTexture(void);


public:
	HRESULT		Ready_Texture(const _tchar* pPath, TEXTURETYPE eType, const _uint& iCnt);
	void		Render_Texture(const _uint& iIndex = 0);

private:
	vector<IDirect3DBaseTexture9*>			m_vecTexture;

public:
	static CTexture*	Create(LPDIRECT3DDEVICE9 pGraphicDev, const _tchar* pPath, TEXTURETYPE eType, const _uint& iCnt);
	virtual void		Free(void);
};
END
#endif // Texture_h__
