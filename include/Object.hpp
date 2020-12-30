#include <vector>
#include <cmath>
#include <armadillo>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include "Lector.hpp"
#include "Transform.hpp"

class Object{
public:	
	Object(Lector& objetoOBJ);
	~Object();
	void dibuja(float r, float p);
	void dibujaTrayectoria(fmat GH);
	void setColor(const float &R, const float &G, const float &B);
	void setEscala(float x, float y, float z);
private:
	Lector* objectoOBJ;
	float R, G, B;
	fmat escala;
	fmat MB;
	frowvec p1 = frowvec(3);
	frowvec p2 = frowvec(3);
	frowvec p3 = frowvec(3);
	frowvec p4 = frowvec(3);
	float t;
	float angulo;
	float b;
	Transform transform = Transform();
};
