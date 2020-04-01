#pragma once

#include <EngineDLL/Display/Window.hpp>

namespace OGLME
{
	class Application
	{
	public:
		struct Desc
		{
			size_t window_height = 600;
			size_t window_width = 800;
			char* window_name = "OGLME App";
		};

		Application(Desc& app_desc)
			:m_app_desc(app_desc)
		{
			// Add error checking
			m_window = new Window(app_desc.window_width, app_desc.window_height, app_desc.window_name);
			

		};

		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Clean() = 0;

		virtual ~Application() 
		{
			delete m_window;
		};

		FORCE_INLINE Window* GetWindow() { return m_window; }

	protected:
		Window* m_window;
		Desc m_app_desc;
	};
}