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
    private:
        double costXHour;
        int peopleCapacity;
        string sport;
};