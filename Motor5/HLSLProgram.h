#pragma once
#include<GL/glew.h>
#include<string>
using namespace std;

class HLSLProgram
{
private:
	GLuint programID;
	GLuint fragmentShaderID;
	GLuint vertexShaderID;

	void compilerShader(const string& shaderPath, GLuint id);
public:
	HLSLProgram();
	~HLSLProgram();
	int numAtribute; 
	void addAtribute(const string attributeName);
	void use();
	void unuse();
	void compilerShaders(const string& vertexShaderFilePath, const string& fragmentShaderFilePath);
	void linkShader();
	GLuint getUniformLocation(const string& name);
};

