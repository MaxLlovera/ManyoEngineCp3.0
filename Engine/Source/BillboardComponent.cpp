#include "BillboardComponent.h"
#include "Application.h"
#include "ModuleCamera3D.h"
#include "ModuleScene.h"
#include "glew/include/GL/glew.h"

BillboardComponent::BillboardComponent(GameObject* own)
{
	type = ComponentType::BILLBOARD;
	owner = own;
	transform = nullptr;
}

BillboardComponent::~BillboardComponent()
{
}

void BillboardComponent::AlignBillboardType()
{
	switch (billboardType)
	{
	case BillboardType::SCREEN:
		ScreenAligned(app->scene->getmainCamera());
		break;
	case BillboardType::WORLD:
		WorldAligned(app->scene->getmainCamera(), transform->GetPosition());
		break;
	case BillboardType::AXIS:
		AxisAligned(app->scene->getmainCamera(), transform->GetPosition());
		break;
	default:
		break;
	}
}

Quat BillboardComponent::ScreenAligned(CameraComponent* camera)
{
	float4x4 viewmatrix = camera->GetViewMatrixFrustumTransposed();
	float3x3 rot = float3x3(viewmatrix.WorldX(), viewmatrix.WorldY(), viewmatrix.WorldZ());
	return rot.ToQuat();

}
Quat BillboardComponent::WorldAligned(CameraComponent* camera, float3 pos)
{
	float3 front = (camera->GetFrustumPos() - pos).Normalized();
	float3 up = camera->GetViewMatrixFrustumTransposed().WorldY();
	float3 right = up.Cross(front);
	up = front.Cross(right);

	float3x3 rot = float3x3(right, up, front);
	return rot.ToQuat();

}
Quat BillboardComponent::AxisAligned(CameraComponent* camera, float3 pos)
{
	float3 front = (camera->GetFrustumPos() - pos).Normalized();

	float3 up = float3::unitY;
	float3 right = up.Cross(front);
	front = right.Cross(up);

	float3x3 rot = float3x3(right, up, front);
	return rot.ToQuat();
}

void BillboardComponent::Draw(Color color)
{
	AlignBillboardType();

	//if (owner->particle_system != nullptr)
	//{
		//if (owner->particle_system->particle_material != nullptr)
		//{
			glColor4f(color.r, color.g, color.b, color.a);

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			//if (owner->particle_system->particle_material->GetResourceTexture() != nullptr && owner->particle_system->particle_material->HasTexture())
				//glBindTexture(GL_TEXTURE_2D, owner->particle_system->particle_material->GetTexID());
			//else
				//glColor4f(mat->color.r, mat->color.g, mat->color.b, mat->color.a);
		//}
	//}

	//transform->RecalculateMatrix();

	glPushMatrix();
	glMultMatrixf(transform->localMatrix.Transposed().ptr());

	//res_mesh->Draw();

	glPopMatrix();
}