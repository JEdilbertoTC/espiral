#include <armadillo>
#include <cmath>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include "include/Lector.hpp"
#include "include/Object.hpp"

using namespace arma;

int caidaEnEspiral();

int main(){
    caidaEnEspiral();
}

int caidaEnEspiral(){

    GLFWwindow* window;
    if(!glfwInit()){
        fprintf( stderr, "Fallo al inicializar GLFW\n" );
        getchar();
        return -1;
    }
    window = glfwCreateWindow(1024, 600, "Caida en Espiral", NULL, NULL);

    if(!window){
        fprintf( stderr, "Fallo al abrir la ventana de GLFW.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }

    float pitch = 0, radio = 0.1;
    const string archivoPelota = "models/roca.obj";
    Lector *lectorPelota = new Lector(archivoPelota);
    Object pelota(*lectorPelota);

    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

//  Proyecciones
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    float ar = width / height;

//  Proyección en paralelo
    glViewport(0, 0, width, height);
    glOrtho(-ar, ar, -1.0, 1.0, -40.0, 40.0);

//  Proyección en perspectiva
    //glFrustum(-1.0, 1.0, -1.0, -1.0, 3.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    frowvec eye = {0.0f, 1.0f, 10.0f}; // 0 0 10
    frowvec camera = {0.0f, 0.0f, 0.0f};
    frowvec viewUp = {-1.0f, 0.0f, 0.0f}; //0 1 0

    pelota.setEscala(0.1f, 0.1f, 0.1f);
    pelota.setColor(0.5f, 0.5f, 0.5f);
    do {
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
        	viewUp = {0.0f,1.0f,0.0f};
        }
        if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        	viewUp = {0.0f,0.0f,1.0f};
        }
        if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS){
        	viewUp = {1.0f,0.0f,0.0f};
        }
        if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS){
        	viewUp = {1.0f,1.0f,0.0f};
        }
        if(glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS){
        	viewUp = {0.0f,1.0f,1.0f};
        }
        if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        	viewUp = {1.0f,0.0f,1.0f};
        }
        if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        	viewUp = {1.0f,1.0f,1.0f};
        }
        if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
        	camera[1] -= 0.1;
        }
        if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
        	camera[1] +=0.1;
        }
        if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
        	camera[0] += 0.1f;
        }
        if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
        	camera[0] -= 0.1f;
        }
        if(glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS){
        	pitch+= 0.001;
        }
        if(glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS ){
        	pitch-= 0.001;
        }
        if(glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS){
        	radio+= 0.001;
        }
        if(glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS ){
        	radio-= 0.001;
        }
        
        gluLookAt(eye[0], eye[1], eye[2], camera[0], camera[1], camera[2], viewUp[0], viewUp[1], viewUp[2]);
        
        pelota.dibuja(radio, pitch);  
        glRenderMode(GL_RENDER);
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while(glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );
    glfwTerminate();
    return 0;
}
