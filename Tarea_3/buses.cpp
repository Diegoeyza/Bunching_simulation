#include<iostream>
#include <vector>
#include "buses.h"
using namespace std;

int Bus::pnumber(){
    return static_cast<int>(passengers.size());
}

void Bus::step(){
    distance+=5;
}

void Bus::arrival(int time){
    if (stop_time==-1) {stop_time=time; stationary=true; moving=false;}
    else if (time-stop_time==5) {stop_time=-1; stationary=false;}
}

void Bus::depart(int time){
    if (stop_time==-1) {stop_time=time; departing=true;}
    else if (time-stop_time==6) {stop_time=-1; departing=false; moving=true;cout<<"departing"<<endl;}  //aquí pongo 6 segundos porque uno de esos segundos es cuando se sube el último pasajero
}

void Bus::load(int stop){
        passengers.emplace_back(random_25(stop));
}

int random_25(int stop) {
    int temp=rand() % 25 + 1;
    while (temp==stop) temp=rand() % 25 + 1;
    return temp;
    }