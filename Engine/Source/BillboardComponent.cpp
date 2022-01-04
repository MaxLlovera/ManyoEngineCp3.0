#include "BillboardComponent.h"

BillboardComponent::BillboardComponent(GameObject* own)
{
	type = ComponentType::BILLBOARD;
	owner = own;
}

BillboardComponent::~BillboardComponent()
{
}