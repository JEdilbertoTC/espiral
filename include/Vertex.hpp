#pragma once
#include <armadillo>
#include <iostream>

using namespace arma;

class Vertex{
    
public:
	Vertex();
    Vertex(float x, float y, float z);
    float getX();
    float getY();
    float getZ();
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setCoordenadas(float x, float y, float z);
	void imprimir();
    fcolvec homogenea();
private:
    float x;
    float y;
    float z;
};
