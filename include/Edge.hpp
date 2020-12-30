#pragma once
#include <iostream>
#include "Vertex.hpp"

class Edge{

public:
	Edge(Vertex vi, Vertex vf);
	void imprimir();
	float getViX();
	float getViY();
	float getViZ();
	float getVfX();
	float getVfY();
	float getVfZ();
private:
	Vertex vi;
	Vertex vf;
};
