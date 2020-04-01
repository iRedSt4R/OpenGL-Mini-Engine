#pragma once

#include <GLAD/glad.h>
#include <EngineDLL/Common/Common.h>

namespace OGLME {
	class OGLIndexBuffer
	{
	public:
		OGLIndexBuffer(size_t size, GLuint* indicies)
			:m_buffer_size(size)
		{
			glGenBuffers(1, &m_buffer_id);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_id);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(GLuint), indicies, GL_STATIC_DRAW);
		}

		FORCE_INLINE void Bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_id); };
		FORCE_INLINE void SetData(size_t size, GLfloat* verticies)
		{
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(GLfloat), verticies, GL_STATIC_DRAW);
		}
		FORCE_INLINE void Unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); };
		FORCE_INLINE GLuint GetOGLIndexBuffer() { return m_buffer_id; }

		~OGLIndexBuffer()
		{
			glDeleteBuffers(1, &m_buffer_id);
		};

	private:
		GLuint m_buffer_id;
		size_t m_buffer_size; // Number of elements
	};
}