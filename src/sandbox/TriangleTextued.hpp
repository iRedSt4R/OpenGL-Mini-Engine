#pragma once

#include <EngineDLL/OGL_API.h>

using namespace OGLME;

class TriangleTextued : public Application
{
	using Application::Application;
	
public:
	virtual void Init() final override
	{
		vertex_buffer = new OGLVertexBuffer(sizeof(GLfloat) * sizeof(vertices), vertices);

		vertex_shader = new OGLVertexShader("Shaders\\TriangleTextured\\vertex_shader_basic.glsl");
		pixel_shader = new OGLPixelShader("Shaders\\TriangleTextured\\pixel_shader_basic.glsl");

		texture = new OGLTexture2D("Assets\\Textures\\fuzzy_box.jpg");

		graphics_pipeline = new OGLGraphicsPipeline();

		graphics_pipeline->SetVertexBuffer(vertex_buffer);
		graphics_pipeline->SetVertexShader(vertex_shader);
		graphics_pipeline->SetPixelShader(pixel_shader);

		graphics_pipeline->InitWithTextures();
	}


	virtual void Update() final override
	{
		glClearColor(0.5f, 0.6f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glActiveTexture(GL_TEXTURE0);
		texture->Bind();

		graphics_pipeline->Draw(3);
	}


	virtual void Clean() final override
	{
		
	}

	~TriangleTextued()
	{
		delete vertex_buffer;
		delete vertex_shader;
		delete pixel_shader;
		delete graphics_pipeline;
	}

private:
	OGLVertexBuffer* vertex_buffer;
	OGLVertexShader* vertex_shader;
	OGLPixelShader* pixel_shader;
	OGLTexture2D* texture;

	OGLGraphicsPipeline* graphics_pipeline;

	float vertices[5 * 3] = {
	-0.5f, -0.5f, 0.0f, 0.f, 0.f,
	 0.5f, -0.5f, 0.0f, 1.f, 0.f,
	 0.0f,  0.5f, 0.0f, 0.5f, 1.f,
	};
};