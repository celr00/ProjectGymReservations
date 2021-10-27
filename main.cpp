#include <iostream>
#include <string>
#include "Reservation.h"
#include "Machine.h"

using namespace std;

int main(){

    Machine fm("CL001", 60, 'C', 15.5, true, "Some description.");

    fm.show();

    return 0;
}