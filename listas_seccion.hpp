#include <cstdlib>
#include <iostream>
#include <sstream>
#include "pilas.hpp"

using namespace std;

class Nodo {
private:
    Pila pila;
    Nodo* next;
public:
    Nodo() { next = NULL; };
    Nodo(Pila a) { pila = a; next = NULL; };
    void set_next(Nodo* n) { next = n; };
    Pila get_dato() { return pila; }; 
    Nodo* get_next() { return next; };
    bool es_vacio() { return next == NULL; } 
};

class Seccion {
private: Nodo* primera;
     
public:
    Seccion() { primera = new Nodo(); };
    Seccion(Nodo* n) { primera = n; };
    //~Lista(void);
    void add(Pila p){ //sumar nodos a la lista
    Nodo* nuevo = new Nodo(p);
    nuevo->set_next(primera);
    primera = nuevo;
}  
    bool esvacia(void) {return primera->es_vacio();}
    Pila &primerPila(void){
        if (this->esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return NULL;
    }
    return czo->get_dato();
    } //retorna el dato del primer nodo
    Seccion* resto(void); //retorna el puntero al "resto" de la lista
                        //resto= lo que queda de la lista sin la cabeza
    string toPrint(string p);
    float suma(); // kg totales de todas las pilas contenidas
    int size(); //pilas totales contenidas
    void borrar(void); //borra la cabeza
};