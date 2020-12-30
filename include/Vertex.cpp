#include "Vertex.hpp"

using namespace arma;

Vertex::Vertex(){
	x=z=y=0.0f;
}
Vertex::Vertex(float x, float y, float z){
	this->x= x;
	this->y= y;
	this->z= z;
}

void Vertex::setX(float x){
	this->x = x;
}
void Vertex::setY(float y){
	this->y = y;
}

void Vertex::setZ(float z){
	this->z = z;
}

void Vertex::setCoordenadas(float x, float y, float z){
	this->x= x;
	this->y= y;
	this->z= z;
}

void Vertex::imprimir(){
	cout <<"("<< x<<"," << y <<","<< z<<")";
}

float Vertex::getX(){
	return x;
}

float Vertex::getY(){
	return y;
}

float Vertex::getZ(){
	return z;
}

fcolvec Vertex::homogenea(){
	fcolvec hom = {x,y,z,1.0};
	return hom;
}
