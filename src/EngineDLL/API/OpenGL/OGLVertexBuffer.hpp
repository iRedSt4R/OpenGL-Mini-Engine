#pragma once

#include <EngineDLL/Common/Common.h>

namespace OGLME {
	class OGLVertexBuffer
	{
	public:
		OGLVertexBuffer(size_t size, GLfloat* verticies)
			:m_buffer_size(size)
		{
			glGenBuffers(1, &m_buffer_id);
			glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id);
			glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), verticies, GL_STATIC_DRAW);
		}

		FORCE_INLINE void Bind() { glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id); };
		FORCE_INLINE void SetData(size_t size, GLfloat* verticies) 
		{ 
			glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), verticies, GL_STATIC_DRAW); 
		}
		FORCE_INLINE void Unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); };
		FORCE_INLINE GLuint GetOGLVertexBuffer() { return m_buffer_id; }

		~OGLVertexBuffer() = default;


	private:
		GLuint m_buffer_id;
		size_t m_buffer_size; // Number of elements
	};
}