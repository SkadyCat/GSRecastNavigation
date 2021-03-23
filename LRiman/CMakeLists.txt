set(LRiman_LIBRARY "NavCore")

set(LRiman_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Include/Context.h
	${CMAKE_CURRENT_SOURCE_DIR}/Include/InputGeom.h
	${CMAKE_CURRENT_SOURCE_DIR}/Include/ChunkyTriMesh.h
	${CMAKE_CURRENT_SOURCE_DIR}/Include/MeshLoaderObj.h
	${CMAKE_CURRENT_SOURCE_DIR}/Include/Sample.h

	${CMAKE_CURRENT_SOURCE_DIR}/Include/Sample_SoloMesh.h
	#${CMAKE_CURRENT_SOURCE_DIR}/Include/NavMeshTesterTool.h
	
)

set(LRiman_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Source/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Context.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Source/InputGeom.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Source/ChunkyTriMesh.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Sample.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Source/MeshLoaderObj.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Sample_SoloMesh.cpp
	#${CMAKE_CURRENT_SOURCE_DIR}/Source/NavMeshTesterTool.cpp
)
SET(EXECUTABLE_OUTPUT_PATH ../Share)

include_directories( 
	#${LUA_INCLUDE_DIR}
	#${TW2CORE_INCLUDE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
	#${PROJECT_SOURCE_DIR}/Lua
)
include_directories(../DebugUtils/Include)
include_directories(../Detour/Include)
include_directories(../DetourCrowd/Include)
include_directories(../DetourTileCache/Include)
include_directories(../Recast/Include)


#add_library(${LRiman_LIBRARY} SHARED ${LRiman_HEADER_FILES} ${LRiman_SOURCE_FILES} )
add_executable(${LRiman_LIBRARY} ${LRiman_HEADER_FILES} ${LRiman_SOURCE_FILES} )
target_link_libraries(${LRiman_LIBRARY} DebugUtils Detour DetourCrowd DetourTileCache Recast)
#add_executable (TowerTest main.cpp ${LAOI_LIBRARY})
#set_target_properties(${LAOI_LIBRARY} PROPERTIES LINKER_LANGUAGE C)


#install(TARGETS ${LAOI_LIBRARY} DESTINATION "${MODULE_INSTALL_PATH}")

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
	set_target_properties(${LRiman_LIBRARY} PROPERTIES PREFIX "")
	set(LIBRARY_OUTPUT_PATH /home/magic/skynets/skynet/luaclib)
	target_link_libraries(${LRiman_LIBRARY} PRIVATE ${LUA_LIBRARY} ${TW2CORE_LIBRARY} lualib)
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	set_target_properties(${LRiman_LIBRARY} PROPERTIES PREFIX "")
	set(LIBRARY_OUTPUT_PATH ../Share)
	target_link_libraries(${LRiman_LIBRARY})
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Windows")