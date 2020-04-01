#version 330 core

// output
out vec4 color;

uniform float u_Random;

void main()
{
    color = vec4(u_Random, u_Random, u_Random, 1.f);
}