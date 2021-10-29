#include <iostream>
#include <string>
#include <fstream>
#include "Reservation.h"
#include "Machine.h"
#include "Court.h"

using namespace std;

int main(){

    Service* available[20];
    Reservation book[50];

    ifstream servicesDoc;
    servicesDoc.open("Servicios.txt");

    string line;
    string word;
    while(getline(servicesDoc, line)){
        cout<<line<<endl;
        

    }

    return 0;
}