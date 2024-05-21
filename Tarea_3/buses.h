#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


class Bus {
    private:
    vector<int> passengers;
    int stop_time=-1;
public:
    int id;
    int p_time=-1;
    int distance=0;
    int pnumber();
    bool stationary=false;
    bool departing=false;
    bool moving=true;
	void arrival(int time);
    void load(int stop);
    void depart(int time);
    void passenger_entering(int time);
    bool check_passengers(int stop);
    void dropoff(int stop);
};

int random_25(int stop);