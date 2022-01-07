#pragma once

#include "Component.h"
#include "TransformComponent.h"
#include "CameraComponent.h"
#include "Color.h"


enum class BillboardType
{
	NONE,
	SCREEN,
	WORLD,
	AXIS
};

class BillboardComponent : public Component
{
public:
	BillboardComponent(GameObject* own);
	~BillboardComponent();

	void AlignBillboardType();
	Quat ScreenAligned(CameraComponent* camera);
	Quat WorldAligned(CameraComponent* camera, float3 pos);
	Quat AxisAligned(CameraComponent* camera, float3 pos);
	void Draw(Color color);

public:
	TransformComponent* transform;

	BillboardType billboardType;

};