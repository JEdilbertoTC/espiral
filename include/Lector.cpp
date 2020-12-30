#include "Lector.hpp"

using namespace std;

Lector::Lector(string archivo){
	this->archivo = archivo;
	file = ifstream(archivo);}

Lector::Lector(){}

Lector::~Lector(){}

Vertex Lector::setVertex(float x, float y, float z){
	Vertex vertex = Vertex(x,y,z);
	vertices.push_back(vertex);
	return vertex;
}

Edge Lector::setEdge(Vertex vertex1, Vertex vertex2){
	Edge edge = Edge(vertex1, vertex2);
	edges.push_back(edge);
	return edge;
}

vector<Face> Lector::setFace(vector<Edge> edge){
	vector <Face> face;
	face.push_back(edge);
	faces.push_back(edge);
	return faces;
}

void Lector::printVertices(){
	for(int i = 0; i<vertices.size();i++){
		cout << endl ;vertices[i].imprimir();
	}

}

void Lector::printEdges(){
	for (int i = 0 ; i <edges.size();i++){
		cout << endl; edges[i].imprimir();
	}
}

void Lector::printFaces(){
	for (int i = 0; i < faces.size(); i++){
		cout << "Face" << i+1 << endl;
		faces[i].imprimir();
	}
}

void Lector::setName(string name){this->name = name;}

string Lector::getName(){return name;}

void Lector::printName(){cout << name;}

vector<Vertex> Lector::getVertices(){return vertices;}

vector<Edge> Lector::getEdges(){return edges;}

void Lector::closeFile(){file.close();}

void Lector::lector(){
	Lector vn;
	string linea;
	vector<string> nomobjeto;
    vector<string> elementos;
    nomobjeto = split(archivo, '/');

    string nombre = nomobjeto.at(1);

	while (getline(file, linea)){
    	elementos = split(linea, ' ');
        if(elementos[0].compare("g") == 0){
            if(elementos.size()>1){
                nombre = elementos[1];
            }
        } else if(elementos[0].compare("v") == 0){
    		float x = stof(elementos[1]);
    		float y = stof(elementos[2]);
    		float z = stof(elementos[3]);
            setVertex(x,y,z); //internamente crea una arista y hace push a un vector de vertices
        } else if(elementos[0].compare("f") == 0){
    		int index1 = stoi(split(elementos[1],'/')[0])-1;
    		int index2 = stoi(split(elementos[2],'/')[0])-1;
    		int index3 = stoi(split(elementos[3],'/')[0])-1;
    		Edge edge1 = setEdge(getVertices()[index1],getVertices()[index2]);//Creando aristas con los una vector de vertices del objeto
    		Edge edge2 = setEdge(getVertices()[index2],getVertices()[index3]);
    		Edge edge3 = setEdge(getVertices()[index3],getVertices()[index1]);
    		sortVertices.push_back(vertices[index1]);
            sortVertices.push_back(vertices[index2]);
            sortVertices.push_back(vertices[index3]);
            setFace({edge1,edge2,edge3});
        }
	}
    closeFile();
}

vector<Vertex> Lector::getSortVertices(){
    return sortVertices;
}