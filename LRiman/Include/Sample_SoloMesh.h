//
// Copyright (c) 2009-2010 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef RECASTSAMPLESOLOMESH_H
#define RECASTSAMPLESOLOMESH_H

#include "Sample.h"
#include "DetourNavMesh.h"
#include "Recast.h"
#include "../Detour/Include/DetourNavMeshQuery.h"
class Sample_SoloMesh : public Sample
{
public:
	bool m_keepInterResults;
	float m_totalBuildTimeMs;
	dtPolyRef m_startRef;
	dtPolyRef m_endRef;
	unsigned char* m_triareas;
	rcHeightfield* m_solid;
	rcCompactHeightfield* m_chf;
	rcContourSet* m_cset;
	rcPolyMesh* m_pmesh;
	int m_npolys;
	static const int MAX_POLYS = 256;
	static const int MAX_SMOOTH = 2048;
	int m_nsmoothPath;
	float m_smoothPath[MAX_SMOOTH * 3];
	int m_pathIterPolyCount;
	float m_prevIterPos[3], m_iterPos[3], m_steerPos[3], m_targetPos[3];
	dtPolyRef m_polys[MAX_POLYS];
	dtPolyRef m_pathIterPolys[MAX_POLYS];
	dtQueryFilter m_filter;
	//≈‰÷√Œƒº˛ rcConfig
	rcConfig m_cfg;	
	rcPolyMeshDetail* m_dmesh;

	void copyPos(float a[3], float b[3]);
	float m_spos[3];
	float m_epos[3];

	float m_polyPickExt[3];
	enum DrawMode
	{
		DRAWMODE_NAVMESH,
		DRAWMODE_NAVMESH_TRANS,
		DRAWMODE_NAVMESH_BVTREE,
		DRAWMODE_NAVMESH_NODES,
		DRAWMODE_NAVMESH_INVIS,
		DRAWMODE_MESH,
		DRAWMODE_VOXELS,
		DRAWMODE_VOXELS_WALKABLE,
		DRAWMODE_COMPACT,
		DRAWMODE_COMPACT_DISTANCE,
		DRAWMODE_COMPACT_REGIONS,
		DRAWMODE_REGION_CONNECTIONS,
		DRAWMODE_RAW_CONTOURS,
		DRAWMODE_BOTH_CONTOURS,
		DRAWMODE_CONTOURS,
		DRAWMODE_POLYMESH,
		DRAWMODE_POLYMESH_DETAIL,
		MAX_DRAWMODE
	};
	
	DrawMode m_drawMode;
	
	void cleanup();

public:
	Sample_SoloMesh();
	virtual ~Sample_SoloMesh();
	
	virtual void handleSettings();
	virtual void handleTools(int type);
	virtual void handleDebugMode();
	
	virtual void handleRender();
	virtual void handleRenderOverlay(double* proj, double* model, int* view);
	virtual void handleMeshChanged(class InputGeom* geom);
	virtual bool handleBuild();

	void findPath(float begin[3], float end[3]);

	void load();
	void save();
private:
	// Explicitly disabled copy constructor and copy assignment operator.
	Sample_SoloMesh(const Sample_SoloMesh&);
	Sample_SoloMesh& operator=(const Sample_SoloMesh&);
};


#endif // RECASTSAMPLESOLOMESHSIMPLE_H
