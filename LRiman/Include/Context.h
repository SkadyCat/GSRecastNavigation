

#pragma once
#include <string>
#include <iostream>
#include "InputGeom.h"
#include "../Recast/Include/Recast.h"
#include "../Detour/Include/DetourNavMesh.h"
#include "../Detour/Include/DetourNavMeshQuery.h"
using namespace std;
class Context :rcContext{


public:

	void doLog(const rcLogCategory, const char* a, const int s) override;
	

	dtNavMeshQuery m_navQuery;
	dtNavMesh m_navMesh;
	InputGeom m_geom;
	
	bool load(string path);

	bool initNavMesh();
	bool build();


};