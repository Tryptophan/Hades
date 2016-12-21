#include <iostream>
#include <GL/glew.h>

#include "display.h"
#include "shader.h"
#include "mesh.h"

int main(int argc, char** argv) {
	Display display(800, 600, "Hades");

	Vertex verticies[] = { 
		Vertex(glm::vec3(-0.5, -0.5, 0.0)),
		Vertex(glm::vec3(0.0, 0.5, 0.0)),
		Vertex(glm::vec3(0.5, -0.5, 0.0))
	};

	Mesh mesh(verticies, sizeof(verticies) / sizeof(verticies[0]));

	Shader shader("StandardShader");

	while (!display.IsClosed()) {
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);

		shader.Bind();
		mesh.Draw();

		display.Update();
	}

	return 0;
}