// CS1300 Fall 2020
// Author: Bach Nguyen
// Recitation: 505 -- Madhusudhan Aithal
// Project 3 -- Car implimentation file

#include "Car.h"
#include <string>
using namespace std;

Car::Car() // Initialized default constructor
{
    static const int total_lap = 70;
    static const int fuel_load = 110;
    tyre = "";
    fuel = 110.0;
    laptime = 0;
    total_time = 0;
    lap_count = 0;

}
Car::Car(string tyre_choice, int current_fuel, int time, int laps) // Initialized parameterized constructor
{
   tyre = tyre_choice; 
   fuel = current_fuel;
   total_time = time;
   lap_count = laps;
}
void Car::setCarTyre(int input) // Set the current tyre that the racer is racing on
{
    if (input == 1) // For soft compound
    {
        tyre = "Soft";
    }
    else if (input == 2) // For soft compound
    {
        tyre = "Medium";
    }
    else if (input == 3) // For soft compound
    {
        tyre = "Hard";
    }
}
void Car::setCarFuel(double fuel_burn) // This will set the fuel flow rate base on user's input in main
{   
    for (int i = 0; i < 10; i++)
    {
        fuel = fuel - fuel_burn;
    }
}
void Car::setLapTimes(int tyre_input, int command) // Set the lap time based on user's input in main
{   
    if (tyre_input == 1) // If soft compound is chosen
    {
        if (command == 1) // Push (go faster) on soft compound
        {
            laptime = 1.84;
        }
        else if (command == 2) // Conserve fuel on soft compound
        {
            laptime = 1.87;
        }
        else if (command == 3) // Decides to do a pit stop and change tyres
        {
           laptime = 1.90; 
        }
    }
    else if (tyre_input == 2) // If medium compound is chosen
    {
        if (command == 1) // Push on medium compound
        {
            laptime = 1.93;
        }
        else if (command == 2) // Conserve fuel on medium compound
        {
            laptime = 1.96;
        }        
        else if (command == 3) // Decides to do a pit stop and change tyres
        {
           laptime = 2.01; 
        }
    }
    else if (tyre_input == 3) // If hard compound is chosen
    {
        if (command == 1) // Push on soft compound
        {
            laptime = 2.04;
        }
        else if (command == 2) // Conserve fuel on hard compound
        {
            laptime = 2.08;
        }
        else if (command == 3) // Decides to do a pit stop and change tyres
        {
           laptime = 2.11; 
        }
    }
    for (int i = 0; i < 10; i++) // Sum up the lap times for each loop iteration
    {
        total_time += laptime;
    }
}
void Car::setCarLaps(int laps) // set the current lap that user's on
{
    lap_count = laps;
}
string Car::getCarTyre() // Return the tyre chosen
{
    return tyre;
}
double Car::getCarFuel() // Return the total fuel
{
    return fuel;
}
double Car::getLapTimes() // Return the time taken to complete the race (70 laps)
{
    return total_time;
}
int Car::getCarLaps() // Return driver's current lap count
{
    return lap_count;
}
