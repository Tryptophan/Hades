#pragma once

#include <string>
#include <GL/glew.h>

class Shader {
public:
	Shader(const std::string& filename);
	virtual ~Shader();

	void Bind();
protected:
private:
	Shader(const Shader& other) {}
	Shader& operator=(const Shader& other) {}

	static const unsigned int NUM_SHADERS = 2;

	GLuint program;
	GLuint shaders[NUM_SHADERS];
};

