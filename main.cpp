#include <iostream>
#include <string>
#include "Reservation.h"

using namespace std;

int main(){

    Hour fh(13,30);

    Reservation num1 = Reservation("CL001", 1, fh, 30);

    cout<<fh<<endl;
    cout<<num1.getEndingHour()<<endl;

    return 0;
}