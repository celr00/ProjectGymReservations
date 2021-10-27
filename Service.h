#ifndef ServiceClass
#define ServiceClass
#include <iostream>
#include <string>

using namespace std;

class Service{
    public:
        /*Constructors*/
        Service();
        Service(string cd, int mt, char t);
        /*Sets and Gets*/
        void setCode(string cd){code = cd;}
        void setMaxTime(int mt){maxTime = mt;}
        void setType(char t){type = t;}
        string getCode(){return code;}
        int getMaxTime(){return maxTime;}
        char getType(){return type;}
        /*Methods*/
        virtual void show() = 0;
        virtual double getFinalCost(int t) = 0;
    protected:
        string code;
        int maxTime;
        char type;
};

Service::Service(){
    code = " ";
    maxTime = 60;
    type = ' ';
}
Service::Service(string cd, int mt, char t){
    code = cd;
    maxTime = mt;
    type = t;
}

#endif