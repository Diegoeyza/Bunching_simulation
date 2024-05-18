#include<iostream>
#include<string>
#include <vector>
using namespace std;


class Bus {
    private:
    vector<int> passengers;
public:
    int id;
    int pnumber();
	bool arrival();
    void load();
};

