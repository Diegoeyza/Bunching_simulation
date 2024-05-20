#include<iostream>
using namespace std;
#include"buses.h"
#include <ctime>
#include"paradas.h"
#define TIME 100

int main(){
    srand(time(0));
    Stop stops[25];
    Bus buses[4];
    for(int i = 0; i < 25; i++) {stops[i].id=i+1; stops[i].position=i*400;}
    for(int i = 0; i < 4; i++) {buses[i].id=i+1; buses[i].distance=i*2500;}
    int time=0;
    Bus A;
    while (time<=TIME){
        for(int i = 0; i < 25; i++) stops[i].arrival();
        cout<<"time: "<<time<<" "<<stops[0].people<<endl;
        
        for(int i = 0; i < 25; i++) {
            for(int j = 0; j < 4; j++){
                if (buses[j].distance==stops[i].position && stops[i].people>0 && !stops[i].is_bus_here && !buses[j].departing &&buses[j].pnumber()<40){     //el bus es pesado y no espera a pasajeros que lleguen cuando se está yendo, tampoco van a parar 2 buses juntos a recoger gente, esto no es una utopía, es Santiago de Chile
                    stops[i].is_bus_here=true;
                    stops[i].bus_number=j+1;
                    buses[j].arrival(time);
                }
                if (buses[j].departing==true)  buses[j].depart(time);
            }
            if (stops[i].is_bus_here && stops[i].people>0){
                    if (buses[stops[i].bus_number-1].stationary) {buses[stops[i].bus_number-1].arrival(time);}
                    if (!buses[stops[i].bus_number-1].stationary){
                        buses[stops[i].bus_number-1].load(i);
                        stops[i].people--;
                        if (stops[i].people==0 || buses[stops[i].bus_number-1].pnumber()==40) {stops[i].is_bus_here=false; buses[stops[i].bus_number-1].depart(time);}
                    }
                }
        }
        cout<<"Buses: ";
        for (int j = 0; j < 4; j++){
            if (buses[j].moving && buses[j].distance!=10000-5) buses[j].distance+=5;
            else if (buses[j].distance==10000-5) buses[j].distance=0;
            cout<<buses[j].distance<<";";
        }
        cout<<endl;
        cout<<"passengers: ";
        for (int j = 0; j < 4; j++){
            cout<<buses[j].pnumber()<<";";
        }
        cout<<endl;






        time++;
    }

    return 0;
}