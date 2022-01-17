#pragma once
#include "Component.h"
#include "Application.h"
#include "ModuleCamera3D.h"
#include "CameraComponent.h"
#include "TransformComponent.h"

class BillboardComponent : public Component {

public:

	BillboardComponent(GameObject* own, TransformComponent* trans);
	~BillboardComponent();

	bool Update(float dt) override;

	//Quat ScreenAligned(CameraComponent* camera);
	//Quat WorldAligned(CameraComponent* camera, float3 pos);
	//Quat AxisAligned(CameraComponent* camera, float3 pos);
	Quat RotateToFaceCamera();

	void OnEditor() override;

public:

	TransformComponent* transform;
};