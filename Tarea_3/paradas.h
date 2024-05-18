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
};

int random_360();