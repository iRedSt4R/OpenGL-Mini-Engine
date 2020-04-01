
#include <EngineDLL/Core/ApplicationManager.hpp>
#include "TraingleColorAnim.hpp"
#include "TriangleTextued.hpp"

using namespace OGLME;

int main()
{
	Application::Desc desc = {};

	Application* app = new TriangleTextued(desc);

	ApplicationManager::RunApplication(app);

}