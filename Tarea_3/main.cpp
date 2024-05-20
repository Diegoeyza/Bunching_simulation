#include<iostream>
using namespace std;
#include"buses.h"
#include <ctime>
#include"paradas.h"
#define TIME 36000             //El tiempo de simulación
#define BUSES 4                //La cantidad de buses, si lo aumento a 40, debo dividir la distancia entre buses por 10 para que funcione bien
#define BUSES_DISTANCE 2500    //la distancia entre los buses
#define PROBABILITY 360        //La probabilidad de que llegue un pasajero, como base es 1/360, pero si modifico el 360 a 36 por ejemplo, multiplicaría por 10 la frecuencia de llegada de pasajeros
#define SPEED 5               //La velocidad del bus, debe ser múltiplo de 400

int main(){
    srand(time(0));
    //float Q,S;
    vector<int> bus_positions;
    Stop stops[25];
    Bus buses[BUSES];
    for(int i = 0; i < 25; i++) {stops[i].id=i+1; stops[i].position=i*400;}
    for(int i = 0; i < BUSES; i++) {buses[i].id=i+1; buses[i].distance=i*BUSES_DISTANCE; bus_positions.push_back(i*BUSES_DISTANCE);}
    int time=0;
    Bus A;
    while (time<=TIME){
        for(int i = 0; i < 25; i++) stops[i].arrival(PROBABILITY);
        
        for(int i = 0; i < 25; i++) {
            for(int j = 0; j < BUSES; j++){
                if ((buses[j].distance==stops[i].position && stops[i].people>0 && !stops[i].is_bus_here && !buses[j].departing && buses[j].pnumber()<40)||(buses[j].distance==stops[i].position && buses[j].check_passengers(stops[i].id))){     //el bus es pesado y no espera a pasajeros que lleguen cuando se está yendo, tampoco van a parar 2 buses juntos a recoger gente, esto no es una utopía, es Santiago de Chile
                    stops[i].is_bus_here=true;
                    stops[i].bus_number=j+1;
                    buses[j].arrival(time);
                }
                if (buses[j].departing==true)  buses[j].depart(time);
            }
            if (stops[i].is_bus_here && buses[stops[i].bus_number-1].stationary) {buses[stops[i].bus_number-1].arrival(time);}   //verifico si esque el bus llegó al paradero

            if (stops[i].is_bus_here && !buses[stops[i].bus_number-1].stationary && buses[stops[i].bus_number-1].check_passengers(stops[i].id)) buses[stops[i].bus_number-1].dropoff(stops[i].id);      //echo a todos los pasajeros de una patada

            if (stops[i].is_bus_here && stops[i].people>0 && !buses[stops[i].bus_number-1].stationary && buses[stops[i].bus_number-1].pnumber()<40 && buses[stops[i].bus_number-1].p_time==-1) buses[stops[i].bus_number-1].passenger_entering(time);

            else if (stops[i].is_bus_here && stops[i].people>0 && !buses[stops[i].bus_number-1].stationary && buses[stops[i].bus_number-1].pnumber()<40){         //comienzan a subir los pasajeros a la vez que bajan los otros, porque los buses tienen 2 puertas
                buses[stops[i].bus_number-1].load(i);
                stops[i].people--;
                buses[stops[i].bus_number-1].passenger_entering(time);
                if (stops[i].people==0 || buses[stops[i].bus_number-1].pnumber()==40) {stops[i].is_bus_here=false; buses[stops[i].bus_number-1].depart(time);}
            }
        }
        for (int j = 0; j < 4; j++){
            if (buses[j].moving && buses[j].distance!=10000-SPEED) buses[j].distance+=5;
            else if (buses[j].distance==10000-SPEED) buses[j].distance=0;
        }

        if (time%3600==0 && time!=0){
            cout<<"t="<<time<<"s\n========="<<endl;
            for (int i=0; i<25; i++) cout<<"parada "<<stops[i].id<<": "<<stops[i].people<<" pax esperando"<<endl;
            for (int j=0; j<BUSES; j++) {cout<<"bus "<<buses[j].id<<": "<<buses[j].pnumber()<<" pax, en y="<<buses[j].distance<<endl; bus_positions[j]=buses[j].distance;}
            sort(bus_positions.begin(),bus_positions.end());
            //Q=0;
            for (int i=0;i<BUSES;i++){

            }
        }
        time++;
    }
    return 0;
}