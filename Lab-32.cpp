#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
using namespace std;

const int INITIAL_CARS = 2;
const int NUM_LANES = 4;
const int TIME_PERIODS = 20;

const int PROB_PAY = 46;    // 46% pays and leaves
const int PROB_JOIN = 39;   // 39% new car joins
const int PROB_SWITCH = 15; // 15% rear car switches lanes

int main() {
    srand(time(0));

    deque<Car> tollBooth;

    // Four toll lanes
    deque<Car> lanes[NUM_LANES];

    // Initialize each lane with 2 cars
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < INITIAL_CARS; j++) {
            lanes[i].push_back(Car());
        }
    }

    // print initial queues
    cout << "Initial queue:\n";
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << (i + 1) << ":\n";
        for (Car &c : lanes[i]) {
            cout << "    ";
            c.print();
        }
    }
    cout << endl;

    // Simulation loop
    for (int t = 1; t <= TIME_PERIODS; t++) {
        cout << "\nTime: " << t << "\n";

        for (int i = 0; i < NUM_LANES; i++) {
            // empty lane rule (50/50)


        }
    }

    // normal lane rules
    int r = rand() % 100;

        if (r < PROB_PAY) {
            // Front car pays and leaves
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