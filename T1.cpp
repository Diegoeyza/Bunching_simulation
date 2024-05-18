#include<iostream>
#include<string>
#include <vector>
#include<cstdlib>
using namespace std;

int random_num(){
    srand((unsigned) time(NULL));
	return 100 + (rand() % 101);
}

vector<int> passengers;
int main(){
    for (int i = 0; i < 40; i++) {
        passengers.emplace_back(rand() % 24 + 1);
    }
    cout << "\nThe vector elements are: "; 
    for (int i = 0; i < static_cast<int>(passengers.size()); i++) {
        cout << passengers[i] << " "<<endl;
    }
    return 0;
}