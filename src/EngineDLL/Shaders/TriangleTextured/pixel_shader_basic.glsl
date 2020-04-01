#version 330 core

// inputs
in vec2 text_coord;

// output
out vec4 color;

uniform sampler2D ourTexture;

void main()
{
    color = texture(ourTexture, text_coord);
}