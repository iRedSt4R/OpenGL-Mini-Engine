#pragma once

#include <EngineDLL/API/OpenGL/OGLVertexShader.hpp>
#include <EngineDLL/API/OpenGL/OGLPixelShader.hpp>

namespace OGLME {
	class OGLShaderManager
	{
	public:
		static GLuint CreateOGLShaderProgram(OGLVertexShader* vs, OGLPixelShader* ps)
		{
			GLint success;
			GLchar info_log[512];

			GLuint shader_program = glCreateProgram();
			glAttachShader(shader_program, vs->GetOGLVertexShader());
			glAttachShader(shader_program, ps->GetOGLPixelShader());
			glLinkProgram(shader_program);
			glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader_program, 512, NULL, info_log);
				std::cout << "Failed to create OGL Shader Program!" << std::endl;
				std::cout << "Logs:" << std::endl;
				std::cout << info_log << std::endl;
			}

			return shader_program;
		}
	};
}
