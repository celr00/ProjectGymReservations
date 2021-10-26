
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
    cout<<minutes<<endl;
}

/***Opertaor Overloading***/
Hour Hour::operator+(int num){
    minutes += num;
    while(minutes >=60){
        minutes -= 60;
        hours++;
        if(hours == 24){
            hours == 0;
        }
    }
    return *this;
}
Hour Hour::operator-(int num){
    minutes -= num;
