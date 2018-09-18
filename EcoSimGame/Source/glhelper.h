#pragma once
#include "PointerBag.h"
class glhelper
{
public:
	glhelper();
	glhelper(PointerBag* pointerbag);
	~glhelper();

private:
	PointerBag * pointerbag;
};

