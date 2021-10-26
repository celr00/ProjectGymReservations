#include <iostream>
#include <string>
#include "Hour.h"

using namespace std;

class Reservation{
    public:
        /*Constructores*/
        Reservation();
        Reservation(string cs, int cc, Hour h, int dur);

        /*Gets y Sets*/

        /*Métodos*/

    protected:
        string claveServicio;
        int claveCliente;
        Hour horaInicio;
        int duracion;
};

/*Constructores*/
Reservation::Reservation(){
    claveServicio = "N/A";
    claveCliente = 0;
    horaInicio = Hour();
    duracion = 0;
}

Reservation::Reservation(string cs, int cc, Hour h, int dur){
    claveServicio = cs;
    claveCliente = cc;
    horaInicio = h;
    duracion = dur;
}