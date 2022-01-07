#pragma once

#include "Component.h"
#include "MathGeoLib/src/Geometry/Frustum.h"
#include "MathGeoLib/src/MathBuildConfig.h"
#include "MathGeoLib/src/MathGeoLib.h"
#include "ModuleCamera3D.h"

class TransformComponent;
class IndexBuffer;
class VertexBuffer;
class CameraComponent : public Component
{
public:
	CameraComponent(GameObject* own, TransformComponent* trans);
	~CameraComponent();

	void OnEditor() override;
	bool Update(float dt) override;
	void Draw() override;

	void SetPlanes();
	void CalculateVerticalFov(float horizontalFovRadians, float width, float height);
	void UpdateFovAndScreen(float width, float height);
	void UpdateFov();
	
	void CompileBuffers();
	bool CompareRotations(Quat& quat1, Quat& quat2);
	float4x4 GetViewMatrixFrustumTransposed() const;

	bool OnLoad(JsonParsing& node) override;
	bool OnSave(JsonParsing& node, JSON_Array* array) override;

	float3 CameraComponent::GetFrustumPos() const;


	int CameraComponent::ContainsAaBox(const AABB& boundingBox);

	float4x4 matrixViewFrustum;
	float4x4 matrixProjectionFrustum;



public:

	Frustum camera;
	TransformComponent* transform;
	Quat currentRotation;
	float3 currentPos;

	float nearPlane;
	float farPlane;
	float verticalFov;
	float horizontalFov;
	float currentScreenWidth;
	float currentScreenHeight;

	IndexBuffer* ebo;
	VertexBuffer* vbo;
};