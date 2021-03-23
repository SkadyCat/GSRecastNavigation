#include "..\Include\Context.h"

void Context::doLog(const rcLogCategory, const char* a, const int s)
{
	printf(a);
}

bool Context::load(string path)
{
	 return m_geom.load(this, path);
}

bool Context::initNavMesh()
{

	
	dtStatus status;

	return true;
}

bool Context::build()
{

	return true;
}
