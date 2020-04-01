#version 330 core
  
layout (location = 0) in vec4 position;
layout (location = 1) in vec2 a_text_coord;

out vec2 text_coord;

void main()
{
    gl_Position = position;
    text_coord = a_text_coord;
}