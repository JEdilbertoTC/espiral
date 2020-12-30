#include "Edge.hpp"

using namespace std;

Edge::Edge(Vertex vi, Vertex vf){
	this->vi = vi;
	this->vf = vf;
}

void Edge::imprimir(){
	cout << "Vertice inicial "; vi.imprimir(); cout <<endl;
	cout << "Vertice final "; vf.imprimir(); cout <<endl;
}

float Edge::getViX(){
	return vi.getX();
}

float Edge::getViY(){
	return vi.getY();
}

float Edge::getViZ(){
	return vi.getZ();
}

float Edge::getVfX(){
	return vf.getZ();
}

float Edge::getVfY(){
	return vf.getY();
}

float Edge::getVfZ(){
	return vf.getZ();
}
