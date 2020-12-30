#include "Face.hpp"

using namespace arma;

Face::Face(vector <Edge> edges){
	this->edges = edges;
}

void Face::imprimir(){
	for(int i=0;i< edges.size();i++){
		edges[i].imprimir();
		normales();
	}
}

void Face::normales(){
	frowvec v1 = {edges[0].getViX(),edges[0].getViY(),edges[0].getViZ()};
	frowvec v2 = {edges[1].getViX(),edges[1].getViY(),edges[1].getViZ()};
	frowvec v3 = {edges[2].getViX(),edges[2].getViY(),edges[2].getViZ()};
	frowvec Normal = cross(v2-v1, v3-v1);
	cout << "Normal:" << Normal << endl;
}

