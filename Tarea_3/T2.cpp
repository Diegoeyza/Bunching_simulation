#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int Nrandom() {
    return rand() % 5 + 1;
    }

int main(){
    srand(time(0));
    vector<int> passengers;
    for (int i=0; i<25;i++){
        passengers.emplace_back(Nrandom());
        cout<<passengers[i]<<",";
    }
    cout<<endl;
    int i=0;
    while (i<static_cast<int>(passengers.size())){
        cout<<"here: "<<passengers[i]<<endl;
        if (passengers[i]==5){ cout<<"coincidence: "<<passengers[i]<<endl; passengers.erase(find(passengers.begin(), passengers.end(),5));}
    else i++;}
    
    for (int i=0; i<static_cast<int>(passengers.size());i++){
        cout<<passengers[i]<<",";
    }

    return 0;
}
