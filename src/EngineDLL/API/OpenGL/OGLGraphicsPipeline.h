#pragma once

#include <EngineDLL/API/OpenGL/OGLVertexBuffer.hpp>
#include <EngineDLL/API/OpenGL/OGLIndexBuffer.hpp>
#include <EngineDLL/API/OpenGL/OGLVertexShader.hpp>
#include <EngineDLL/API/OpenGL/OGLPixelShader.hpp>
#include <EngineDLL/API/OpenGL/OGLShaderManager.hpp>

namespace OGLME {
	class OGLME_API OGLGraphicsPipeline
	{
	public:
		struct EPipelineStatus
		{
		};

		OGLGraphicsPipeline();

		FORCE_INLINE void SetVertexBuffer(OGLVertexBuffer* vb) { vertex_buffer = vb; };
		FORCE_INLINE void SetVertexBuffer(OGLIndexBuffer* ib) { index_buffer = ib; };
		FORCE_INLINE void SetVertexShader(OGLVertexShader* vs) { vertex_shader = vs; };
		FORCE_INLINE void SetPixelShader(OGLPixelShader* ps) { pixel_shader = ps; };

		FORCE_INLINE void SetUniformF(const float val, const char* name_in_shader);
		FORCE_INLINE void SetUniform4F(const float* val, const char* name_in_shader);

		void Init();
		void InitWithTextures();
		void Draw(size_t primitive_num);

		~OGLGraphicsPipeline();

	private:
		// Pipeline stage:
		OGLVertexBuffer* vertex_buffer = nullptr;
		OGLIndexBuffer* index_buffer = nullptr;
		OGLVertexShader* vertex_shader = nullptr;
		OGLPixelShader* pixel_shader = nullptr;

		GLuint vertex_array;
		GLuint shader_program;

	};
}