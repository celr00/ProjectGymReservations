#include<iostream>
#include<string>
#include"Service.h"

class Machine:public Service{
    public:
        /*Constructors*/
        Machine();
        Machine(string cd, int mt, char t, double cst, bool ci, string desc);
        /*Sets and Gets*/
        void setCostoX15min(double cst){costX15min = cst;}
        void setWithInstructor(bool ci){withInstructor = ci;}
        void setDescripcion(string desc){descripcion = desc;}
        double getCostoX15min(){return costX15min;}
        bool getWithInstructor(){return withInstructor;}
        string getDescripcion(){return descripcion;}
        /*Methods*/
        void show();
        double getFinalCost(int t);
    private:
        double costX15min;
        bool withInstructor;
        string descripcion;
};

/*Constructors*/
Machine::Machine():Service(){
    costX15min = 0;
    withInstructor = false;
    descripcion = "";
}
Machine::Machine(string cd, int mt, char t, double cst, bool ci, string desc):Service(cd, mt, t){
    costX15min = cst;
    withInstructor = ci;
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
    cout<<"$"<<costX15min<<" every 15 minutes."<<endl;
    if(withInstructor)
        cout<<"Includes an instructor."<<endl;
    else
        cout<<"Without instructor."<<endl;
    cout<<"*Max Time of rent: "<<maxTime<<endl;
}
double Machine::getFinalCost(int t){
    return (double)t/15*costX15min;
}