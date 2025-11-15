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
    cout << endl;

    int time = 1;

    // Simulation loop
    while (!tollBooth.empty()) {
        int prob = rand() % 100 + 1; //1-100

        if (prob <= 55) {
            // Car pays and leaves
            Car leaving = tollBooth.front();
            tollBooth.pop_front();
            cout << "Time: " << time << " Operation: Car paid: ";
            leaving.print();
        } else { // prob 45
            // New car joins
            Car newCar;
            tollBooth.push_back(newCar);
            cout << "Time: " << time << " Operation: Joined lane: ";
            newCar.print();
        }

        // Print current queue
        cout << "Queue:\n";
        if (tollBooth.empty()) {
            cout << "   Empty\n";
        } else {
            for (Car c : tollBooth) {
                cout << "    ";
                c.print();
            }
        }

        cout << endl;
        time++;

    }

    return 0;

}

// branched from lab 32