#include "framework.h"
#include "Camera.h"

void Camera::Strafe(float units)
{
}

void Camera::Fly(float units)
{
}

void Camera::Walk(float units)
{
}

void Camera::Pitch(float angle)
{
}

void Camera::Yaw(float angle)
{
}

void Camera::Roll(float angle)
{
}

void Camera::GetViewMatrix(_matrix * view)
{
	// 카메라의 축이 서로 직각이 되도록한다.
	D3DXVec3Normalize(&m_look, &m_look);

	D3DXVec3Cross(&m_up, &m_look, &m_right);
	D3DXVec3Normalize(&m_up, &m_up);

	D3DXVec3Cross(&m_right, &m_up, &m_look);
	D3DXVec3Normalize(&m_right, &m_right);

	// 뷰 행렬을 구성
	float x = -D3DXVec3Dot(&m_right, &m_pos);
	float y = -D3DXVec3Dot(&m_up, &m_pos);
	float z = -D3DXVec3Dot(&m_look, &m_pos);
}

void Camera::SetCameraType(TYPE cameraType)
{
}

void Camera::GetPosition(_vec3 * pos)
{
}

void Camera::SetPosition(_vec3 * pos)
{
}

void Camera::GetRight(_vec3 * right)
{
}

void Camera::GetUp(_vec3 * up)
{
}

void Camera::GetLook(_vec3 * look)
{
}

Camera::Camera()
{
}

Camera::Camera(TYPE cameraType)
{
}

Camera::~Camera()
{
}
