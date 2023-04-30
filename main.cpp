#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "pilas.hpp"
//#include "categorias.hpp"

using namespace std;

int main(){

    int stock = 350;

    Pila* pilaManzanas= new Pila();

    pilaManzanas->guardarMercaderia(&stock);

    cout << "kilos sobrantes  " <<  stock <<endl;
/*     pilaManzanas->imprimir_info();

    
    cout <<endl;
    cout <<endl;

    int c= 5;

    pilaManzanas->guardarMercaderia(&c);
    pilaManzanas->imprimir_info(); 

    cout <<endl;
    cout <<endl;

    int b= 10;

    pilaManzanas->sacarXKg(&b); */
    pilaManzanas->imprimir_info(); 
    cout << "tamanio pila " << pilaManzanas->size();
    


    delete pilaManzanas;


}