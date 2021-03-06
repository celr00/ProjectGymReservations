#include <iostream>
#include <string>

using namespace std;

class Hour{
    public:
        /***Constructors***/
        Hour();
        Hour(int hr, int min);

        /***Sets and Gets***/
        void setHour(int hr);
        void setMinute(int min);
        int getHour();
        int getMinute();

        /***Methods***/
        void show();

        /***Opertaor Overloading***/
        Hour operator+(int num);
        Hour operator-(int num);
        bool operator<(Hour b);
        bool operator<=(Hour b);
        bool operator>(Hour b);
        bool operator>=(Hour b);
        bool operator==(Hour b);
        friend ostream& operator<<(ostream& os, Hour& dt);
        friend istream& operator>>(istream& is, Hour& dt);

    private:
        int hours;
        int minutes;
};

/*Constructors*/
Hour::Hour(){
    hours = 0;
    minutes = 0;
}
Hour::Hour(int hr, int min){
    hours = hr;
    minutes = min;
}

/*Sets and Gets*/
void Hour::setHour(int hr){
    if(hr<24 && hr>=0)
        hours = hr;
}
void Hour::setMinute(int min){
    if(min<60 && min>=0)
        minutes = min;
}
int Hour::getHour(){
    return hours;
}
int Hour::getMinute(){
    return minutes;
}

/***Methods***/
void Hour::show(){
    if(hours<10)
        cout<<"0";
    cout<<hours<<":";

    if(minutes<10)
        cout<<"0";
    cout<<minutes;
}

/***Opertaor Overloading***/
Hour Hour::operator+(int num){
    Hour newHour = Hour(hours, minutes);
    newHour.minutes += num;
    while(newHour.minutes >=60){
        newHour.minutes -= 60;
        newHour.hours++;
        if(newHour.hours == 24){
            newHour.hours == 0;
        }
    }
    return newHour;
}
Hour Hour::operator-(int num){
    Hour newHour = Hour(hours, minutes);
    newHour.minutes -= num;
    while(newHour.minutes < 0){
        newHour.minutes += 60;
        newHour.hours--;
        if(newHour.hours == -1){
            newHour.hours = 23;
        }
    }
    return newHour;  
}
bool Hour::operator<(Hour b){
    if(hours*60 + minutes < b.hours*60 + b.minutes){
        return true;
    }
    return false;
}
bool Hour::operator<=(Hour b){
    if(hours*60 + minutes <= b.hours*60 + b.minutes){
        return true;
    }
    return false;
}
bool Hour::operator>(Hour b){
    if(hours*60 + minutes > b.hours*60 + b.minutes){
        return true;
    }
    return false;
}
bool Hour::operator>=(Hour b){
    if(hours*60 + minutes >= b.hours*60 + b.minutes){
        return true;
    }
    return false;
}
bool Hour::operator==(Hour b){
    if(hours*60 + minutes == b.hours*60 + b.minutes){
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, Hour& h){
    if(h.hours<10)
        os<<"0";
    os<<h.hours<<":";

    if(h.minutes<10)
        os<<"0";
    os<<h.minutes;
    return os;
}

istream &operator>>(istream& is, Hour& dt) {
    is >> dt.hours >> dt.minutes;
    return is;
}