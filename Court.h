#include<iostream>
#include<string>
#include"Service.h"

class Court:public Service{
    public:
        /*Constructors*/
        Court();
        Court(string cd, int mt, char t, double cxh, int pc, string sp);
        /*Set's and Get's*/
        void setCostXHour(double cxh){costXHour = cxh;}
        void setPeopleCapacity(int pc){peopleCapacity = pc;}
        void setSport(string sp){sport = sp;}
        double getCostXHour(){return costXHour;}
        int getPeopleCapacity(){return peopleCapacity;}
        string getSport(){return sport;}
        /*Methods*/
        void show();
        double getFinalCost(int t);
    private:
        double costXHour;
        int peopleCapacity;
        string sport;
};void Court::show(){
    cout<<code<<"| Court: ";
    if(type == 'T' or type == 't')
        cout<<"Tenis"<<endl;
    else if(type == 'F' or type == 'f')
        cout<<"Froton"<<endl;
    else if(type == 'V' or type == 'v')
        cout<<"Volley Ball"<<endl;
    cout<<"People Capacity: "<<peopleCapacity<<endl;
    cout<<"$"<<costXHour<<" every hour."<<endl;
    cout<<"*Max Time of rent: "<<maxTime<<endl<<endl;
}
double Court::getFinalCost(int t){
    return (double)t/60*costXHour;
}