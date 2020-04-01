#pragma once

#include <EngineDLL/OGL_API.h>

using namespace OGLME;

class TraingleColorAnim : public Application
{
	using Application::Application;
	
public:
	virtual void Init() final override
	{
		vertex_buffer = new OGLVertexBuffer(sizeof(GLfloat) * sizeof(vertices), vertices);

		vertex_shader = new OGLVertexShader("Shaders\\Triangle\\vertex_shader_basic.glsl");
		pixel_shader = new OGLPixelShader("Shaders\\Triangle\\pixel_shader_basic.glsl");

		graphics_pipeline = new OGLGraphicsPipeline();

		graphics_pipeline->SetVertexBuffer(vertex_buffer);
		graphics_pipeline->SetVertexShader(vertex_shader);
		graphics_pipeline->SetPixelShader(pixel_shader);

		graphics_pipeline->Init();
	}


	virtual void Update() final override
	{
		glClearColor(0.5f, 0.6f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		float timeValue = glfwGetTime();
		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;

		graphics_pipeline->SetUniformF(greenValue, "u_Random");

		graphics_pipeline->Draw(3);
	}


	virtual void Clean() final override
	{
		
	}

	~TraingleColorAnim()
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

	OGLGraphicsPipeline* graphics_pipeline;

	float vertices[9] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};
};