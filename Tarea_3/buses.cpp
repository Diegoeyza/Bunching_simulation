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

void Bus::arrival(bool condition){
    stationary=condition;
}