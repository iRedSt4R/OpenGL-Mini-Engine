#pragma once

#include <EngineDLL/Common/Common.h>
#define STB_IMAGE_IMPLEMENTATION
#include <EngineDLL/API/stb_image.h>

namespace OGLME
{
	class OGLME_API OGLTexture2D
	{
	public:
		OGLTexture2D(const char* file_path);


		FORCE_INLINE void Bind() { glBindTexture(GL_TEXTURE_2D, m_texture_id); }
		FORCE_INLINE void UnBind() { glBindTexture(GL_TEXTURE_2D, 0); }
		FORCE_INLINE GLuint GetTextureID() { return m_texture_id; }
		FORCE_INLINE std::pair<size_t, size_t> GetTextureDims() 
		{
			return std::make_pair(m_width, m_height);
		}

		~OGLTexture2D();

	private:
		unsigned char* m_image_data;
		GLuint m_texture_id;
		int m_width, m_height;
		int m_channel_number;
		const char* m_path_used;

	};
}