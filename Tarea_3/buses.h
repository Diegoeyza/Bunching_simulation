#include<iostream>
#include<string>
#include <vector>
using namespace std;


class Bus {
    private:
    vector<int> passengers;
    int stop_time=-1;
public:
    int id;
    int distance=0;
    void step();
    int pnumber();
    bool stationary=false;
    bool departing=false;
    bool moving=true;
	void arrival(int time);
    void load(int stop);
    void depart(int time);
};

int random_25(int stop);