#include "mesh.h"

Mesh::Mesh(Vertex* verticies, unsigned int numVerticies) {
	drawCount = numVerticies;

	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	// Move data onto the gpu
	glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVerticies * sizeof(verticies[0]), verticies, GL_STATIC_DRAW);

	// Tell opengl how to interpret data
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &vertexArrayObject);
}

void Mesh::Draw() {
	glBindVertexArray(vertexArrayObject);

	// Draw the data (vertex and their properties) from the buffer
	glDrawArrays(GL_TRIANGLES, 0, drawCount);

	glBindVertexArray(0);
}