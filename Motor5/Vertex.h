#pragma once
#include<GL/glew.h>
struct Position {
	float x; 
	float y;

	void set(float x, float y) {
		this->x = x;
		this->y = y;
	}
};

struct Color{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
	void set(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
};
struct Vertex {
	Position position;
	Color color;
	void setPosition(float x, float y) {
		position.set(x, y);
	}
	void SetColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
		color.set(r, g, b, a);
	}
};
