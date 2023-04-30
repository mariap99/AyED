#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

class Cajon {
private:
    int pesoMax;
    int capacidad_disponible;
    int cantidad_actual;
    int ID;
    //static int cajonesDisponibles;
    static int num_cajon;
public:
    Cajon() { 
        pesoMax = 20; 
        cantidad_actual = 0; 
        capacidad_disponible = pesoMax; 
        // cajonesDisponibles--; //falta una excepcion para cuando el productor se queda sin cajones 
        ID = num_cajon; 
        num_cajon++;  
    }
    bool esta_lleno() { 
        return cantidad_actual == pesoMax; 
    }
     bool esta_vacio() { 
            return cantidad_actual == 0; 
    }
     void get_info(){
            cout << "Cantidad actual: " << cantidad_actual << endl;
            cout << "Capacidad disponible " << capacidad_disponible << endl;
            cout << "ID: " << ID << endl; 
    }
    void actualizarCapDisponible(){
        capacidad_disponible = pesoMax - cantidad_actual;
    }
    //simplificar codigo
    int llenarCajon(int* kg) {
    if (cantidad_actual + *kg <= pesoMax) { // si hay suficiente espacio para agregar todo
        cantidad_actual += *kg;
        *kg = 0;
    } else { // no hay suficiente espacio para agregar todo
        int sobrante = cantidad_actual + *kg - pesoMax; // calculo cuánto sobra
        cantidad_actual = pesoMax; // lleno el cajón
        *kg = sobrante; // guardo el sobrante para intentar agregarlo en el siguiente cajón
    }
    actualizarCapDisponible();
    return *kg;
}
    int vaciarCajon(int* kg) {
        if (cantidad_actual < *kg) { //la cantidad a quitar es mayor a la cant del cajon
            *kg -= cantidad_actual;
            cantidad_actual = 0;
        } else {
            cantidad_actual -= *kg; //cantidad a quitar es menor que la disponible
            *kg = 0;
        }
        actualizarCapDisponible();
        return *kg;
    }
};
// Inicialización de la variable estática cajonesDisponibles
//int Cajon::cajonesDisponibles = 100;

int Cajon::num_cajon = 0;

