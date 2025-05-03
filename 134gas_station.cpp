 #include <bits/stdc++.h>
using namespace std;


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total_tank = 0;
    int current_tank = 0;
    int starting_station = 0;
    for (int i = 0; i < gas.size();i++){
        int gain = gas[i] - cost[i];
        total_tank += gain;
        current_tank += gain;


        if(current_tank <0){
            starting_station = i + 1;
            current_tank = 0;
        }
    }
    return total_tank >= 0 ? starting_station : -1;
}
int main() {

   
    return 0;
}