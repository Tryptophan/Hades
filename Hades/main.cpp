#include <iostream>
#include <GL/glew.h>

#include "display.h"
#include "shader.h"

int main(int argc, char** argv) {
	Display display(800, 400, "Hades");

	Shader shader("StandardShader");

	while (!display.IsClosed()) {
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
		shader.Bind();

		display.Update();
	}

	return 0;
}