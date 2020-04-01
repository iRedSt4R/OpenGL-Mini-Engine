#include "OGLTexture2D.h"

using namespace OGLME;

OGLTexture2D::OGLTexture2D(const char* file_path)
	:m_path_used(file_path)
{
	gladLoadGL();

	m_image_data = stbi_load(file_path, &m_width, &m_height, &m_channel_number, 0);
	glGenTextures(1, &m_texture_id);
	glBindTexture(GL_TEXTURE_2D, m_texture_id);

	// Texture mapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_image_data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(m_image_data);
}

OGLTexture2D::~OGLTexture2D()
{
	glDeleteTextures(1, &m_texture_id);
}

