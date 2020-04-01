#pragma once

#include <EngineDLL/Core/Application.hpp>

namespace OGLME
{
	// TODO: Add multi app support, so different app run in different thread
	class ApplicationManager
	{
	public:
		static void RunApplication(Application* app)
		{
			auto window = app->GetWindow();

			app->Init();

			while (!(window->bShouldClose()))
			{

				//processing input will go here:

				app->Update();

				window->Update();
			}

			app->Clean();
		}
	};
}