#include "BillboardComponent.h"
#include "ModuleScene.h"

BillboardComponent::BillboardComponent(GameObject* own, TransformComponent* trans)
{
	type = ComponentType::BILLBOARD;
	owner = own;
	transform = trans;
}

BillboardComponent::~BillboardComponent()
{
}

bool BillboardComponent::Update(float dt)
{
	return false;
}

Quat BillboardComponent::RotateToFaceCamera()
{
	Frustum cameraFrustum = app->scene->mainCamera->camera;

	Quat cameraRot = app->scene->mainCamera->currentRotation;
	float3 cameraRotationDegrees = cameraRot.ToEulerXYZ();

	return cameraRot;
}

//Quat BillboardComponent::ScreenAligned(CameraComponent* camera)
//{
//
//	float4x4 viewmatrix = camera->GetViewMatrixFrustumTransposed();
//	float3x3 rot = float3x3(viewmatrix.WorldX(), viewmatrix.WorldY(), viewmatrix.WorldZ());
//	return rot.ToQuat();
//
//}

//Quat BillboardComponent::WorldAligned(CameraComponent* camera, float3 pos)
//{
//	float3 front = (camera->GetFrustumPos() - pos).Normalized();
//	float3 up = camera->GetViewMatrixFrustumTransposed().WorldY();
//	float3 right = up.Cross(front);
//	up = front.Cross(right);
//
//	float3x3 rot = float3x3(right, up, front);
//	return rot.ToQuat();
//
//}

//Quat BillboardComponent::AxisAligned(CameraComponent* camera, float3 pos)
//{
//	float3 front = (camera->GetFrustumPos() - pos).Normalized();
//
//	float3 up = float3::unitY;
//	float3 right = up.Cross(front);
//	front = right.Cross(up);
//
//	float3x3 rot = float3x3(right, up, front);
//	return rot.ToQuat();
//}

void BillboardComponent::OnEditor()
{
	if (ImGui::CollapsingHeader("Billboard"))
	{
		ImGui::PushItemWidth(90);
		ImGui::Separator();
	}
}
