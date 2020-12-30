#include "Object.hpp"

#define PI 3.14159265

using namespace arma;

Object::Object(Lector& objectoOBJ){
    MB = {{-1,3,-3,1},
               {3,-6,3,0}, 
               {-3,3,0,0},
               {1,0,0,0}};
	this->objectoOBJ = &objectoOBJ;
	this->objectoOBJ->lector();
	t = angulo = b = 0.0f;
}

Object::~Object(){}

void Object::dibuja(float r, float p){
    float ang = angulo * PI/360.0f;
    float B = ang *sinf(ang)/(1-cosf(ang))* ((1+cosf(ang))/sinf(ang));
    frowvec P1 = {r*cosf(ang),-r*sinf(ang),-ang*p};
    frowvec P2 = {r*((2+cosf(ang))/(1+(2*cosf(ang)))),-r*(sinf(ang)/(1+(2*cosf(ang)))),-B};
    frowvec P3 = {r*((2+cosf(ang))/(1+(2*cosf(ang)))),r*(sinf(ang)/(1+(2*cosf(ang)))),B};
    frowvec P4 = {r*cosf(ang),r*sinf(ang),ang*p};

    p1 = P1;
    p2 = P2;
    p3 = P3;
    p4 = P4;

    fmat GH(4,3);
    GH.row(0) = p1;
    GH.row(1) = p2;
    GH.row(2) = p3;
    GH.row(3) = p4;
    
	frowvec T = {powf(t,3),powf(t,2),t,1};
	
    t = (t < 1.0) ? t+0.001 : 0.0f;
    angulo+= 1.0f;
    
    frowvec Qt = T * MB * GH;
	dibujaTrayectoria(GH);
    vector <Vertex> verticesObjeto = objectoOBJ->getSortVertices(); //getfacesverts //Regresa todos los vertices
    vector <Vertex>verticesDibujar;
    fmat transf = transform.T(Qt[0],Qt[1],Qt[2]);
    transf *= escala;
    transf *= transform.T(0,0,0);
    for (unsigned int i=0; i<verticesObjeto.size(); i++ ){
        fcolvec v = {verticesObjeto.at(i).homogenea()}; //.h()
        fcolvec vp = transf * v;
        Vertex rv = Vertex();
        frowvec vp2 = trans(vp);
        rv.setCoordenadas(vp2.at(0),vp2.at(1),vp2.at(2)); // setvalues
        verticesDibujar.push_back(rv);
    } 
    glColor3f(this->R, this->G, this->B);
    glBegin(GL_TRIANGLES);
    for (unsigned int i=0; i<verticesDibujar.size(); i++ ) {
        frowvec vert = {verticesDibujar[i].getX(),verticesDibujar[i].getY(),verticesDibujar[i].getZ()}; //getvalues
        glVertex3f(vert[0], vert[1], vert[2]);
    }
    glEnd();
}

void Object::dibujaTrayectoria(fmat GH){
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(p1[0],p1[1],p1[2]);
    glVertex3f(p2[0],p2[1],p2[2]);
    glVertex3f(p3[0],p3[1],p3[2]);
    glVertex3f(p4[0],p4[1],p4[2]);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glPointSize(10);
    glBegin(GL_POINTS);
    for (float t=0; t<1; t+= 0.001) {
        frowvec T = {powf(t,3),powf(t,2),t,1};
        frowvec Qt = T * MB * GH;
        glVertex3f(Qt[0],Qt[1],Qt[2]);
    }
    glEnd();
}

void Object::setColor(const float& R, const float& G, const float& B){
	this->R = R;
	this->G = G;
	this->B = B;
}

void Object::setEscala(float x, float y, float z){
    escala = transform.S(x,y,z);
}
