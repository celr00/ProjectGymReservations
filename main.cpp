#include <iostream>
#include <string>
#include <fstream>
#include "Reservation.h"
#include "Machine.h"
#include "Court.h"

using namespace std;

int main(){

    Service* available[20]; int contS = 0;
    Reservation* book[50]; int contR = 0;

    /*Loading the information of the service document to de array
    */
    ifstream servicesDoc;
    servicesDoc.open("Servicios.txt");

    string line, code, timeS, typeS, costS, instructorS, amountPeopleS, description, sport;

    int time, amountPeople;
    char type;
    double cost;
    bool instructor;

    while(getline(servicesDoc, line)){
        code = line.substr(0, line.find(" "));
        line = line.substr(line.find(" ")+1);

        timeS = line.substr(0, line.find(" "));
        time = stoi(timeS);
        line = line.substr(line.find(" ")+1);

        typeS = line.substr(0, line.find(" "));
        type = typeS[0];
        line = line.substr(line.find(" ")+1);

        costS = line.substr(0, line.find(" "));
        cost = stod(costS);
        line = line.substr(line.find(" ")+1);

        if(type == 'C' || type == 'E' || type == 'B'){
            instructorS = line.substr(0, line.find(" "));
            if(instructorS == "T") instructor = true;
            else instructor = false;
            description = line.substr(line.find(" ")+1);

            available[contS] = new Machine(code, time, type, cost, instructor, description);
            contS++;
        }       

        if(type == 'T' || type == 'F' || type == 'V'){
            amountPeopleS = line.substr(0, line.find(" "));
            amountPeople = stoi(amountPeopleS);

            sport = line.substr(line.find(" ")+1);

            available[contS] = new Court(code, time, type, cost, amountPeople, sport);
            contS++;
        }
    }

    /*Loading the information of the reservation's document to the array*/

    ifstream reservationsDoc;
    reservationsDoc.open("Reserva.txt");

    string serviceCode, startHourS, startMinuteS, durationS;
    int clientID, duration, startHour, startMinute;

    while(getline(reservationsDoc, line)){
        serviceCode = line.substr(0, line.find(" "));
        line = line.substr(line.find(" ")+1);

        startHourS = line.substr(0, line.find(" "));
        startHour = stoi(startHourS);
        line = line.substr(line.find(" ")+1);

        startMinuteS = line.substr(0, line.find(" "));
        startMinute = stoi(startMinuteS);
        line = line.substr(line.find(" ")+1);

        durationS = line.substr(0, line.find(" "));
        duration = stoi(durationS);

        clientID = stoi(line.substr(line.find(" ")+1));

        book[contR] = new Reservation(serviceCode, clientID, Hour(startHour, startMinute), duration);
        contR++;
    }

    return 0;
}