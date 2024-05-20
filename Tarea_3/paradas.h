#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Stop {
public:
    int id;
	void arrival();
    int people=0;
    int position;
    bool is_bus_here=false;
    int bus_number=0;
};

int random_360();