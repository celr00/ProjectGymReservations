#include<iostream>
#include<string>
#include"Service.h"

class Machine:public Service{
    public:
        /*Constructors*/
        Machine();
        Machine(string cd, int mt, char t, double cst, bool ci, string desc);
        /*Sets and Gets*/
        void setCostoX15min(double cst){costoX15min = cst;}
        void setConInstructor(bool ci){conInstructor = ci;}
        void setDescripcion(string desc){descripcion = desc;}
        double getCostoX15min(){return costoX15min;}
        bool getConInstructor(){return conInstructor;}
        string getDescripcion(){return descripcion;}
        /*Methods*/
        void show();
        double getFinalCost(int t);
    private:
        double costoX15min;
        bool conInstructor;
        string descripcion;
};

/*Constructors*/
Machine::Machine():Service(){
    costoX15min = 0;
    conInstructor = false;
    descripcion = "";
}
Machine::Machine(string cd, int mt, char t, double cst, bool ci, string desc):Service(cd, mt, t){
    costoX15min = cst;
    conInstructor = ci;
    descripcion = desc;
}

/*Methods*/
void Machine::show(){
    cout<<code<<"| Machine: ";
    if(type == 'C' or type == 'c')
        cout<<"Treadmill"<<endl;
    else if(type == 'E' or type == 'e')
        cout<<"Escalator"<<endl;
    else if(type == 'B' or type == 'b')
        cout<<"Stacionary Bicycle"<<endl;
    cout<<"Description: "<<descripcion<<endl;
    cout<<"$"<<costoX15min<<" every 15 minutes."<<endl;
    if(conInstructor)
        cout<<"It includes an instructor."<<endl;
    else
        cout<<"It does not include an instructor."<<endl;
    cout<<"*Max Time of rent: "<<maxTime<<endl<<endl;
    
}
double Machine::getFinalCost(int t){
    return (double)t/15*costoX15min;
}