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
