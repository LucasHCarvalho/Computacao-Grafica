#include "Window.h"

Window::Window() {
	width = 800;
	heigth = 600;
	Initialize();
}

Window::Window(GLint width, GLint heigth) {
	Window::width = width;
	Window::heigth = heigth;
	Initialize();
}

Window::~Window() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

int Window::Initialize() {
	for (int i = 0; i < 1024; i++) {
		keys[i] = false;
	}

	if (!glfwInit()) {
		printf("GLFW: Não pode ser iniciado");
		return 1;
	}

	window = glfwCreateWindow(width, heigth, "Nova janela", NULL, NULL);
	if (!window) {
		printf("GLFW: Não foi possível criar a janela");
		glfwTerminate();
		return 1;
	}

	glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		printf("Glew: Não pode ser iniciado!");
		glfwDestroyWindow(window);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, bufferWidth, bufferHeight);
	glfwSetWindowUserPointer(window, this);
	CreateCallbacks();
}

void Window::hendleKeys(GLFWwindow* window, int key, int code, int action, int mode) {
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >= 0 && key <= 1024) {
		if (action == GLFW_PRESS) {
			theWindow->keys[key] = true;
			printf("\nApertou %d\n", key);
		}
		else if (action == GLFW_RELEASE) {
			theWindow->keys[key] = false;
			printf("\nSoltou %d\n", key);
		}
	}
}

void Window::CreateCallbacks() {
	glfwSetKeyCallback(window, hendleKeys);
}