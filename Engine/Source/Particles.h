#pragma once
#include "GameObject.h"
#include "ResourceManager.h"
#include "ModuleScene.h"
#include "glmath.h"
#include "MathGeoLib/src/Geometry/Frustum.h"

class Particles {
public:
	Particles(GameObject* parent);
	Particles(Particles* particleReference, GameObject* parent);

	~Particles() {}

	bool OnLoad(JsonParsing& node);
	bool OnSave(JsonParsing& node, JSON_Array* array);

public:
	std::shared_ptr<Texture> tex;
	GameObject* plane;

	Quat rotationQuat;
	float lifeTime;
	float3 rot;
	float3 position;
	float3 dir;
	float3 accel;
	float3 size;
	float3 speed;
	Vec4 color;
	bool isActive;

};
