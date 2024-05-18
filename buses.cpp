#include<iostream>
#include <vector>
#include "buses.h"
using namespace std;

int Bus::pnumber(){
    return static_cast<int>(passengers.size());
}