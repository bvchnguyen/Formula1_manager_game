// Car - header

#ifndef car_H
#define car_H
#include <string>

using namespace std; 

class car
{
    public:
        
        car();
        car(string tyre_choice, int current_fuel, int time, int laps);
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
