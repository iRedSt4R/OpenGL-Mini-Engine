#pragma once

#include <EngineDLL/Common/Common.h>
#include <GLAD/glad.h>
#include <iostream>
#include <string>

namespace OGLME {
	class OGLPixelShader {
	public:
		OGLPixelShader(char* shader_path) {
			std::string shaderSourceString = ReadTextFromFile(shader_path);
			const char* shaderSource = shaderSourceString.c_str();

			pixel_shader_compied = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(pixel_shader_compied, 1, &shaderSource, NULL);
			glCompileShader(pixel_shader_compied);

			glGetShaderiv(pixel_shader_compied, GL_COMPILE_STATUS, &success);
			if (!success) {
				glGetShaderInfoLog(pixel_shader_compied, 512, NULL, infoLog);
				std::cout << "Failed Compiling GLSL Pixel Shader\n" << infoLog << std::endl;
			}
		}

		~OGLPixelShader() = default;

		std::string ReadTextFromFile(char* filePath) {
			FILE* fp = fopen(filePath, "r");
			fseek(fp, 0, SEEK_END);
			long fileLenght = ftell(fp);
			fseek(fp, 0, SEEK_SET);
			char* contents = new char[fileLenght + 1];
			for (int i = 0; i < fileLenght; i++) {
				contents[i] = 0;
			}
			fread(contents, 1, fileLenght, fp);
			contents[fileLenght + 1] = '\0';
			fclose(fp);

			std::string result(contents);
			return result;
		};

		FORCE_INLINE GLuint GetOGLPixelShader() { return pixel_shader_compied; }

	private:
		GLuint pixel_shader_compied;

		GLint success;
		GLchar infoLog[512];
	};
}
