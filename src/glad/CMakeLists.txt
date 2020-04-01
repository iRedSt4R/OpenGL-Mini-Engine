INCLUDE_DIRECTORIES(${GLAD_INCLUDE_DIR})

add_library(GLAD STATIC include/glad/glad.h src/glad.c)
