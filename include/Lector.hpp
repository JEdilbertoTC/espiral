#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Face.hpp"
#include "Split.hpp"

using namespace std;

class Lector{

public:
	Lector(string);
	Lector();
	~Lector();
	void lector();
	ifstream file;
	Vertex setVertex(float , float , float );
	Edge setEdge(Vertex, Vertex);
	vector<Face> setFace(vector<Edge>);
	void printVertices();
	void printEdges();
	void printFaces();
	void setName(string);
	string getName();
	vector<Vertex> getVertices();
	vector<Edge> getEdges();
	vector<Face> getFaces();
	void closeFile();
	void printName();
	vector<Vertex> getSortVertices();
	//vector<string> split(const string &text, char sep);
private:
	string name;
	string archivo;
	vector<Vertex> vertices;
	vector<Edge> edges;
	vector<Face> faces;
	vector <string > cadena;
	vector <Vertex> sortVertices;
};