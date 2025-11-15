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

    // Print initial queues
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

            // Empty lane rule (50/50)
            if (lanes[i].empty()) {
                int coin = rand() % 2;
                if (coin == 0) {
                    cout << " Lane " << (i + 1) << ": empty move car here\n";
                } else {
                    cout << " Lane " << (i + 1) << ": empty remains empty\n";
                }
                continue; // Skips normal rules for empty line
            }

            // Normal rules
            int r = rand() % 100;
            cout << " Lane " << (i + 1) << ": ";

            if (r < PROB_PAY) {
            // Front car pays and leaves
            Car leaving = lanes[i].front();
            lanes[i].pop_front();
            cout << "Lane: " << i + 1 << "Paid: ";
            leaving.print();
        } else if (r < PROB_PAY + PROB_JOIN) {
            // New car joins
            Car newCar;
            lanes[i].push_back(newCar);
            cout << "Lane: " << i + 1 << " Joined: ";
            newCar.print();
        } else {
            // Rear car switches to different lane


        }
    }

        // Print current queue
        for (int i = 0; i < NUM_LANES; i++) {
            cout << "Lane: " << i + 1 << "Queue:\n";

            if (lanes[i].empty()) {
                cout << "       empty\n";
            } else {
                for (Car &c : lanes[i]) {
                    cout << "       ";
                    c.print();
                }
            }
        }
    }

    return 0;

}

// branched from lab 32