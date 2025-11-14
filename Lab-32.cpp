#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
using namespace std;

const int INITIAL_CARS = 2;

int main() {
    srand(time(0));

    deque<Car> tollBooth;

    // Initial population of cars
    for (int i = 0; i < INITIAL_CARS; i++) {
        tollBooth.push_back(Car());
    }

    cout << "Initial queue:\n";
    for (Car c : tollBooth) {
        cout << "    ";
        c.print();
    }
     int time = 1;
     
    // Simulation loop

    
    // Print current queue

}
