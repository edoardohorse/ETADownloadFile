#include <iostream>
#define HOUR " ore : "
#define MINUTE " minuti "

using namespace std;

void calculate(float, float, int*, int*);
string printableTime(int, string);

int main(){

    int hours = 0, minutes = 0;
    float dim = 0, dSpeed = 0;
    string toPrint; 

    cout << "Inserisci la dimensione del file da scaricare (GB): ";
    cin >> dim;
    cout << "Inserisci la velocita' (Mbps): ";
    cin >> dSpeed;

    calculate(dim, dSpeed, &hours, &minutes);


    if(hours != 0)
        toPrint     = printableTime(hours, HOUR);

    toPrint     += printableTime(minutes, MINUTE);

    cout << "Mancano " << toPrint << endl;

    system("pause");
    return 0;
}

void calculate(float dim, float dSpeed, int* h, int* m){
    string toPrint;
    float dSpeedInMB = dSpeed / 8;
    float temp = dim*1024/dSpeedInMB/60;
    int hours = *h, minutes = *m;
    
    if(temp >= 60){
        temp /= 60;
    
        hours = temp;
        minutes = (temp - hours) * 100;
        
        if(minutes >= 60){
            minutes = minutes - 60;
            hours++;
        }
    }
    else{
        minutes = temp;
    }

    *h = hours;
    *m = minutes;

}

string printableTime(int time, string str){
    string toPrint;
    string timeS = to_string(time);
    if(time != 0){
        if (time < 10) timeS = "0" + timeS;
        
        toPrint += timeS + str;
    }

    return toPrint;
}
