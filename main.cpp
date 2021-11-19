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

    bool activo = true;
    char ans;
    while(activo){
        cout<<"***MENU***"<<endl;
        cout<<"1) List of Services"<<endl;
        cout<<"2) List of Reservations"<<endl;
        cout<<"3) Reservations of a Service"<<endl;
        cout<<"4) Reservations per hour"<<endl;
        cout<<"5) Make a Reservation"<<endl;
        cout<<"6) End"<<endl;
        cout<<"Please select your option: ";
        cin>>ans;
        switch(ans){
            case '1':              
                cout<<endl<<"Services: "<<endl;
                for(int i=0;i<contS;i++){
                    available[i]->show();
                    cout<<endl;
                }
                break;
            case '2':
                cout<<endl<<"Reservations: "<<endl;

                Service* service;
                for(int i=0;i<contR;i++){
                    bool siEsta = true;
                    for(int j=0;j<contS;j++){
                        if(book[i]->getServiceCode() == available[j]->getCode()){
                            service = available[j];
                            break;
                        }
                        if(j == contS-1){
                            siEsta = false;
                        }
                    }

                    if(siEsta){
                        service->show();
                        cout<<"Booked by Client #"<<book[i]->getclientId()<<endl;
                        cout<<"Starting Hour: ";book[i]->getStartingHour().show();
                        Hour eh = book[i]->getStartingHour();
                        eh = eh + book[i]->getDuration();
                        cout<<"Ending Hour: ";cout<<eh;cout<<endl;
                        cout<<"Final Cost: "<<service->getFinalCost(book[i]->getDuration())<<endl<<endl;
                    }else{
                        cout<<"Invalid Code"<<endl<<endl;
                    }
                    
                }
                break;
            case '3':
            {
                cout<<endl;

                Service* service;
                string currentCode;
                cout<<"Enter a service code: ";cin>>currentCode;
                bool siEsta = true;

                for(int i=0;i<contS;i++){
                    if(available[i]->getCode() == currentCode){
                        service = available[i];
                        break;
                    }
                    if(i == contS-1){
                        siEsta = false;
                    }
                }
                
                if(siEsta){

                    for(int i=0;i<contR;i++){
                        if(book[i]->getServiceCode() == currentCode){
                            service->show();
                            cout<<"Booked by Client #"<<book[i]->getclientId()<<endl;
                            cout<<"Starting Hour: ";book[i]->getStartingHour().show();
                            Hour eh = book[i]->getStartingHour();
                            eh = eh + book[i]->getDuration();
                            cout<<"Ending Hour: ";cout<<eh;cout<<endl;
                            cout<<"Final Cost: "<<service->getFinalCost(book[i]->getDuration())<<endl<<endl;
                            cout<<"Ending Hour: ";cout<<eh;cout<<endl<<endl;
                        }
                    }
                }else{
                    cout<<"Invalid Code"<<endl<<endl;
                }
            }
                break;
            case '4':
                cout<<"Consultando Reservaciones por Hora..."<<endl;
                break;
            case '5':
                cout<<"Haciendo Reservación..."<<endl;
                break;
            case '6':
                cout<<"Gracias! Vuelva pronto"<<endl;
            {
                activo = false;
                break;
            }break;
            default:
                cout<<"No ingresaste un dato válido."<<endl;
                cout<<"Got no valid data."<<endl;
                break;
        }
    }

    return 0;
}