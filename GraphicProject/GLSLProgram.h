#pragma once

#include <string>
#include <include/GL/glew.h>

class GLSLProgram
{
public:
	GLSLProgram();
	~GLSLProgram();

	void compilerShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilepath);
	void linkShaders();
	void addAttribute(const std::string& attributeName);

	GLint getUniformLocation(const std::string& uniformName);
	void use();
	void unuse();

private:
	int _numAttribute;
	void compileShader(const std::string& filePath, GLuint id);
	GLuint _programID;

	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;
};

