#pragma once

#include <EngineDLL/Common/Common.h>
#include <string>
#include <iostream>
#include <GLAD/glad.h>

namespace OGLME {
    class OGLVertexShader {
    public:
        OGLVertexShader(char* shader_path)
        {
            std::string shaderSourceString = ReadTextFromFile(shader_path);
            const char* shaderSource = shaderSourceString.c_str();

            vertex_shader_compied = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex_shader_compied, 1, &shaderSource, NULL);
            glCompileShader(vertex_shader_compied);

            glGetShaderiv(vertex_shader_compied, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(vertex_shader_compied, 512, NULL, infoLog);
                std::cout << "Failed Compiling GLSL Vertex Shader\n" << infoLog << std::endl;
            }
        }
        ~OGLVertexShader() = default;

        std::string ReadTextFromFile(char* filePath)
        {
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

        FORCE_INLINE GLuint GetOGLVertexShader() { return vertex_shader_compied; }

    private:
        GLuint vertex_shader_compied;

        GLint success;
        GLchar infoLog[512];
    };
}
