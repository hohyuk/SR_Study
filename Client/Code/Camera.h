#pragma once
#include "Export_Function.h"

USING(Engine)
class Camera
{
public:
	enum TYPE { LANDOBJECT, AIRCRAFT };

public:
	void Strafe(float units);
	void Fly(float units);
	void Walk(float units);

	void Pitch(float angle);		// 우향벡터로 회전
	void Yaw(float angle);			// 상향벡터로 회전
	void Roll(float angle);			// 전방벡터로 회전

	void GetViewMatrix(_matrix* view);
	void SetCameraType(TYPE cameraType);
	void GetPosition(_vec3* pos);
	void SetPosition(_vec3* pos);
	void GetRight(_vec3* right);
	void GetUp(_vec3* up);
	void GetLook(_vec3* look);
public:
	explicit Camera();
	explicit Camera(TYPE cameraType);
	~Camera();

private:
	TYPE m_eType;
	_vec3 m_right;
	_vec3 m_up;
	_vec3 m_look;
	_vec3 m_pos;
};