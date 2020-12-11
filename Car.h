// CS1300 Fall 2020
// Author: Bach Nguyen
// Recitation: 505 -- Madhusudhan Aithal
// Project 3 - Header files

#ifndef Car_H
#define Car_H
#include <string>

using namespace std; 

class Car
{
    public:
        
        Car();
        Car(string tyre_choice, int current_fuel, int time, int laps);
        void setCarTyre(int input);
        void setCarFuel(double fuel_burn);
        void setLapTimes(int tyre_input, int command);
        void setCarLaps(int laps);
        string getCarTyre();
        double getCarFuel();
        double getLapTimes();
        int getCarLaps();

    private:
        
        string tyre, outcome;
        double total_time, fuel, laptime, lap_count;
        static const int total_lap = 70;
        static const int fuel_load = 110;
        double times[total_lap];

};
#endif