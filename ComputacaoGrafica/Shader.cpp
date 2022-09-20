#include "Shader.h"

Shader::Shader() {

}

Shader::~Shader() {

}

void Shader::CreateFromString(const char* vertexCode, const char* fragmetCode) {
	Compile(vertexCode, fragmetCode);
}

void Shader::Compile(const char* vertexCode, const char* fragmetCode) {
	ShaderId = glCreateProgram(); //Cria um programa
	GLuint _vShader = glCreateShader(GL_VERTEX_SHADER); //Cria um shader
	GLuint _fShader = glCreateShader(GL_FRAGMENT_SHADER); //Cria um shader

	//Gambiarra para converter Char em GLChar
	const GLchar* vCode[1];
	const GLchar* fCode[1];
	vCode[0] = vertexCode; //Código do vShader
	fCode[0] = fragmetCode; //Código do fShader

	glShaderSource(_vShader, 1, vCode, NULL); //associa o shader ao código
	glCompileShader(_vShader); //Compila o shader
	glAttachShader(ShaderId, _vShader); //Adiciona o shader ao programa


	glShaderSource(_fShader, 1, fCode, NULL); //associa o shader ao código
	glCompileShader(_fShader); //Compila o shader
	glAttachShader(ShaderId, _fShader); //Adiciona o shader ao programa

	glLinkProgram(ShaderId); //Adiciona o programa

	uniformModel = glGetUniformLocation(ShaderId, "model");
	uniformProjection = glGetUniformLocation(ShaderId, "projection");
}

void Shader::UseProgram() {
	glUseProgram(ShaderId);
}