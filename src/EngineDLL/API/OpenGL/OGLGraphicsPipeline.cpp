#include <EngineDLL/API/OpenGL/OGLGraphicsPipeline.h>
#include <EngineDLL/API/OpenGL/OGLShaderManager.hpp>

using namespace OGLME;

OGLGraphicsPipeline::OGLGraphicsPipeline()
{
	//gladLoadGL();
}

// TODO: Create templated SetUniform function
void OGLME::OGLGraphicsPipeline::SetUniformF(const float val, const char* name_in_shader)
{
	glUseProgram(shader_program);
	glUniform1f(glGetUniformLocation(shader_program, name_in_shader), val);
}

void OGLME::OGLGraphicsPipeline::SetUniform4F(const float* val, const char* name_in_shader)
{
	glUseProgram(shader_program);
	glUniform4f(glGetUniformLocation(shader_program, name_in_shader), val[0], val[1], val[2], val[3]);
}

void OGLGraphicsPipeline::Init()
{
	shader_program = OGLShaderManager::CreateOGLShaderProgram(vertex_shader, pixel_shader);

	glGenVertexArrays(1, &vertex_array);
	glBindVertexArray(vertex_array);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer->GetOGLVertexBuffer());
	// Configure vertex attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

}

void OGLGraphicsPipeline::InitWithTextures()
{
	shader_program = OGLShaderManager::CreateOGLShaderProgram(vertex_shader, pixel_shader);

	glGenVertexArrays(1, &vertex_array);
	glBindVertexArray(vertex_array);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer->GetOGLVertexBuffer());
	// Configure vertex attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) (3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);

}

void OGLGraphicsPipeline::Draw(size_t primitive_num)
{
	glUseProgram(shader_program);
	glBindVertexArray(vertex_array);

	if(index_buffer == nullptr)
		glDrawArrays(GL_TRIANGLES, 0, primitive_num);
	else
		glDrawElements(GL_TRIANGLES, primitive_num, GL_UNSIGNED_INT, (void*)0);
}

OGLGraphicsPipeline::~OGLGraphicsPipeline()
{

}