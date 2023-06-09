#include "HLSLProgram.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "Error.h"

using namespace std;

HLSLProgram::HLSLProgram():programID(0), vertexShaderID(0), fragmentShaderID(0), numAtribute(0) {
	
}

HLSLProgram::~HLSLProgram() {

}

void HLSLProgram::compilerShader(const string& shaderPath, GLuint id){
	string filecontent = "";
	string line = "";
	ifstream shaderFile(shaderPath);
	if (shaderFile.fail()) {
		fatalError("Coul not open " + shaderPath);
	}
	while (getline(shaderFile,line)){
		filecontent += line + "\n";
	}
	shaderFile.close();
	const char* contents = filecontent.c_str();
	glShaderSource(id, 1, &contents, nullptr);
	glCompileShader(id);
	GLint isCompiled = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
		vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &infoLog[0]);
		fatalError("Shader " + shaderPath + " could not compiled ");
		printf("%s", &infoLog[0]);
		glDeleteShader(id);
		return;
	}
}




void HLSLProgram::addAtribute(const string attributeName){

}

void HLSLProgram::use(){

}

void HLSLProgram::unuse(){

}

void HLSLProgram::compilerShaders(const string& vertexShaderFilePath, const string& fragmentShaderFilePath){
	programID = glCreateProgram();
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (vertexShaderID == 0) {
		fatalError("Error creating Vertex Shader");
	}
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (fragmentShaderID == 0) {
		fatalError("Error creating Fragment Shader");
	}
	compilerShader(vertexShaderFilePath, vertexShaderID);
	compilerShader(fragmentShaderFilePath, fragmentShaderID);
}

void HLSLProgram::linkShader(){
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
	GLint isLinked = 0;
	glGetProgramiv(programID, GL_LINK_STATUS, (int*)&isLinked);
	if (isLinked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLength);
		vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(programID, maxLength, &maxLength, &infoLog[0]);
		glDeleteProgram(programID);
		fatalError("Shaders could not link " + printf("%s", &*(infoLog[0])));
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);
		return;
	}
	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}

GLuint HLSLProgram::getUniformLocation(const string& name){
	return GLuint();
}
