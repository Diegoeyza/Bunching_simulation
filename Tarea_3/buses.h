#include<iostream>
#include<string>
#include <vector>
using namespace std;


class Bus {
    private:
    vector<int> passengers;
public:
    int id;
    int distance=0;
    void step();
    int pnumber();
    bool stationary=false;
	void arrival(bool condition);
    void load();
};

