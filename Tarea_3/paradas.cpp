#include <cstdlib>
#include "paradas.h"
using namespace std;

int random_num(int number) {
    return rand() % number + 1;
    }

void Stop::arrival(int number){
    int condition=0;
    condition=(random_num(number));
    if (condition<=1) people++;
}