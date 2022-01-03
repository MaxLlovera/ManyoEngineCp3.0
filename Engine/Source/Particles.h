#pragma once

#include "Resource.h"
#include <vector>

typedef unsigned int uint;

//class Resource;


class Particles : public Resource
{
public:
	Particles(uint uid, std::string& assets, std::string& library);
	virtual ~Particles();


	void CleanUp() /*override*/;


};