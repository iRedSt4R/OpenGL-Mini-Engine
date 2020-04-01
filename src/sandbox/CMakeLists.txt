INCLUDE_DIRECTORIES(${GLFW_LIB_INCLUDE})
INCLUDE_DIRECTORIES(${GLM_SOURCE_DIR})
INCLUDE_DIRECTORIES(${GLAD_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${ENGINE_SRC_DIR})

LINK_DIRECTORIES(${ENGINE_BUILD_LIBS_DIR})

LINK_DIRECTORIES(${GLFW_LIB_LIB})
LINK_DIRECTORIES(${GLAD_LIB_DIR})


# Using GLAD to import OpenGL functions
add_compile_definitions(GLFW_INCLUDE_NONE)

file(GLOB_RECURSE SourceFiles
${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

add_executable(Sandbox ${SourceFiles})
target_link_libraries(Sandbox ${ENGINE_LIBRARY_NAME})
target_link_libraries(Sandbox glfw3.lib)
target_link_libraries(Sandbox glad.lib)

# Need for fopen to use same path inside VS as executable inside /bin dir 
set_property(TARGET Sandbox PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SourceFiles})
