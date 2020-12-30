#pragma once
#include <armadillo>
#include <iostream>
#include <vector>
#include "Edge.hpp"

using namespace std;

class Face{
	
public:
	Face(vector<Edge> edges);
	void imprimir();
	void normales();
private:
	vector<Edge>edges;
};

