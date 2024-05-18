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
    for(int i = 0; i < 4; i++) buses[i].id=i+1;
    int time=0;
    Bus A;
    cout<<stops[0].id<<endl;
    while (time<=TIME){
        for(int i = 0; i < 25; i++) stops[i].arrival();
        
        if (buses[0].stationary==true)




        time++;
    }

    return 0;
}