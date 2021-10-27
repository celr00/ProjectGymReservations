#include<iostream>
#include<string>
#include"Service.h"

class Court:public Service{
    public:
        /*Constructors*/
        Court();
        Court(string cd, int mt, char t, double cxh, int pc, string sp);
        /*Set's and Get's*/
        void setCostXHour(double cxh);
        void setPeopleCapacity(int pc);
        void setSport(string sp);
        double getCostXHour();
        int getPeopleCapacity();
        string getSport();
    private:
        double costXHour;
        int peopleCapacity;
        string sport;
};