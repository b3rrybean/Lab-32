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


    // Initialize each lane with 2 cars
    for (int i = 0; i < INITIAL_CARS; i++) {
        tollBooth.push_back(Car());
    }

    // print initial queues
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