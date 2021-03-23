
#include <iostream>
#include "Context.h"
#include "InputGeom.h"
#include "Sample_SoloMesh.h"

using namespace std;
int main() {

	rcContext context;
	//context.enableLog(true);
	InputGeom geo;
	geo.load(&context,R"(D:\Project\C++\SNave\build\Share\Debug\nav_test.obj)");
	//bool flag = context.load(R"(D:\Project\C++\SNave\build\Share\Debug\nav_test.obj)");
	Sample_SoloMesh sp;

	sp.setContext(&context);
	sp.handleMeshChanged(&geo);
	sp.loadAll(R"(D:\Project\C++\SNave\build\Share\Debug\nav_test.obj)");

	sp.handleBuild();
	float begin[3] = { 1.67,-2.36,-5.7 };
	float end[3] = { 22.4,-2.36,14.9 };
	sp.findPath(begin, end);
	sp.save();

	//sp.m_navQuery->findPath();
	return 0;
}