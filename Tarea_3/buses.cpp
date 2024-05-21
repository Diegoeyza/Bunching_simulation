#include "buses.h"
using namespace std;

int Bus::pnumber(){
    return static_cast<int>(passengers.size());
}

void Bus::arrival(int time){
    if (stop_time==-1) {stop_time=time; stationary=true; moving=false;}
    else if (time-stop_time==5) {stop_time=-1; stationary=false;}
}

void Bus::depart(int time){
    if (stop_time==-1) {stop_time=time; departing=true;}
    else if (time-stop_time==6) {stop_time=-1; departing=false; moving=true;}  //aquí pongo 6 segundos porque uno de esos segundos es cuando se sube el último pasajero
}

void Bus::passenger_entering(int time){
    if (p_time==-1) p_time=time;
    else if (time-p_time==1) {p_time=-1;}
}

void Bus::load(int stop){               //agrego el destino del pasajero y lo guardo, este no va a poder ser la parada actual
        passengers.emplace_back(random_25(stop));
}

bool Bus::check_passengers(int stop){               //reviso si esque algún pasajero se quiere bajar en la parada actual
    for (int i=0; i<static_cast<int>(passengers.size());i++){
        if (passengers[i]==stop) return true;
    }
    return false;
}

void Bus::dropoff(int stop){
    for (int i=0; i<static_cast<int>(passengers.size());i++){
        if (passengers[i]==stop) {passengers.erase(find(passengers.begin(), passengers.end(),stop));}
    }
}

int random_25(int stop) {
    int temp=rand() % 25 + 1;
    while (temp==stop) temp=rand() % 25 + 1;
    return temp;
}