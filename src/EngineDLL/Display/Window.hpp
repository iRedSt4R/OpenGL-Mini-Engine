#include <EngineDLL/Common/Common.h>
#include <GLFW/glfw3.h>

class Window {
public:
	Window(size_t width, size_t height, char* name)
		:window_width(width), window_height(height), window_name(name)
	{
		glfwInit();
		if (!glfwInit())
			return;

		window = glfwCreateWindow(width, height, name, NULL, NULL);
		if (window)
			is_created = true;
		else
			glfwTerminate();

		glfwMakeContextCurrent(window);
	};

	FORCE_INLINE bool bShouldClose() { return glfwWindowShouldClose(window); }

	void Update()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	~Window()
	{
		glfwTerminate();
	};

private:
	GLFWwindow* window;
	size_t window_height, window_width;
	char* window_name;
	bool is_created = false;

};
