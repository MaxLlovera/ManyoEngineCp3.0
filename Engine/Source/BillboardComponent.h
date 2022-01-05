#pragma once

#include "Component.h"

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




};