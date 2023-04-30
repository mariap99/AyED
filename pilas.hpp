#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "categorias.hpp"

#define MAX 10

using namespace std;

class Pila {
private:
    Cajon d[MAX];
    int p;
public:
    Pila() { p = -1; };
    void apilar(Cajon x) { d[++p] = x; };
    Cajon& ultimoCajon(void) { return d[p]; };
    void desapilar(void) { p--; };
    bool pilavacia() { return p == -1; };
    bool pilallena() { return p == MAX-1;};
    int size() { return p+1; };


    Cajon nuevoCajon() { Cajon cajon; return cajon; };

    void guardarMercaderia(int* kg) {
        if(*kg > 0 && !this->pilallena()){ //pila no esta llena y hay mercaderia para guardar
            if (this->pilavacia() || this->ultimoCajon().esta_lleno()) { //pila vacia o ultimo cajon lleno
                Cajon nuevo_cajon = nuevoCajon();
                nuevo_cajon.llenarCajon(kg);
                this->apilar(nuevo_cajon);
                guardarMercaderia(kg);
        } 
        else if (this->size()<= 10 && !this->ultimoCajon().esta_lleno()) { //ultimo cajon con lugar
             this->ultimoCajon().llenarCajon(kg);
             this->ultimoCajon().get_info();
            guardarMercaderia(kg);
        } 
    }  
}
//corregir funcion recursiva
void pedidoMinorista(int* kg) {
    if(!this->pilavacia() && *kg>0){
        if(this->ultimoCajon().esta_vacio()) this->desapilar();
        this->ultimoCajon().vaciarCajon(kg);
        pedidoMinorista(kg);
    }
} 
//cambiar int a float
//falta restituir cajones a medida que se liberan

//corregir funcion recursiva
void pedidoMayorista(int* unidades) {
    if(!this->pilavacia() && *unidades>0){
        this->desapilar();
        unidades--;
        pedidoMayorista(unidades);
    }
} 
//falta contemplar caso: cajon incompleto y se pide cajon entero, desapilar, sacar y volver a apilar

void imprimir_info() {
    Pila tmp;
    Cajon cajon;
    while (!this->pilavacia()) {
        cajon = this->ultimoCajon();
        cajon.get_info();
        tmp.apilar(cajon);
        this->desapilar();
    }
    while (!tmp.pilavacia()) {
        this->apilar(tmp.ultimoCajon());
        tmp.desapilar();
    }
}

};

