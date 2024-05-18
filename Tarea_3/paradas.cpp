#include<iostream>
#include <cstdlib>
#include<string>
#include "paradas.h"
using namespace std;

int random_360() {
    return rand() % 360 + 1;
    }

void Stop::arrival(){
    int condition=0;
    condition=(random_360());
    if (condition<=10) people++;
}