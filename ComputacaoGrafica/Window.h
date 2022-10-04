#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "iostream"

class Window
{
public:
	Window();
	~Window();
	Window(GLint width, GLint heigth);
	int Initialize();
	bool ShoudClose() { return glfwWindowShouldClose(window); };
	GLfloat GetbufferWidth() { return (GLfloat)bufferWidth; };
	GLfloat GetbufferHeight() { return (GLfloat)bufferHeight; };
	void SwapBuffers() { glfwSwapBuffers(window); };

private:
	GLFWwindow* window;
	GLint width, heigth;
	int bufferWidth, bufferHeight;

	bool keys[1024];
	static void hendleKeys(GLFWwindow* window, int key, int code, int action, int mode);
	void CreateCallbacks();
};

