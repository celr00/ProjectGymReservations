#include <iostream>
#include <string>
#include "Hour.h"

using namespace std;

class Reservation{
    public:
        /*Constructores*/
        Reservation();
        Reservation(string sc, int ci, Hour sh, int dur);

        /*Gets y Sets*/
        void setServiceCode(string sc);
        void setclientId(int ci);
        void setStartingHour(Hour sh);
        void setDuration(int dur);

        string getServiceCode();
        int getclientId();
        Hour getStartingHour();
        int getDuration();

        /*Métodos*/
        Hour getEndingHour();

    private:
        string serviceCode;
        int clientId;
        Hour startingHour;
        int duration;
};

/*Constructores*/
Reservation::Reservation(){
    serviceCode = "N/A";
    clientId = 0;
    startingHour = Hour();
    duration = 0;
}

Reservation::Reservation(string cs, int ci, Hour h, int dur){
    serviceCode = cs;
    clientId = ci;
    startingHour = h;
    duration = dur;
}

/*Gets y Sets*/
void Reservation::setServiceCode(string sc){serviceCode = sc;}
void Reservation::setclientId(int ci){clientId = ci;}
void Reservation::setStartingHour(Hour sh){startingHour = sh;}
void Reservation::setDuration(int dur){duration = dur;}
string Reservation::getServiceCode(){return serviceCode;}
int Reservation::getclientId(){return clientId;}
Hour Reservation::getStartingHour(){return startingHour;}
int Reservation::getDuration(){return duration;}

/*Métodos*/
Hour Reservation::getEndingHour(){
    return startingHour + duration;
}