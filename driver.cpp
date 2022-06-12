// Driver - implimentation file

#include "driver.h"
#include <string>
#include <cmath>

using namespace std;

    driver::driver() // Initialized default constructor
    {
        points = 300;
        total_points = 0;
        current_lap = 0;
        championship = 4;
        racer_name = "";
        outcome = "";
    }
    driver::driver(string driver_name, string out_come, int total_points, int total_championship) // Initialized parameterized constructor
    {
        outcome = out_come;
        racer_name = driver_name;
        points = total_points;
        championship = total_championship;
    }
    void driver::setDriverName(string driver_name) // Set the racer name that user is managing
    {
        driver_name = "Vettel"; // In this specific iteration of the game, user will manage Vettel
        racer_name = driver_name;
    }
    void driver::setDriverPoints(int gained_points) // Set the total points based on the results of the game
    {   
        total_points = points + gained_points;
        points = total_points;
    }
    void driver::setDriverChampionship(int result) // set Vettel's number of championship based off the results
    {
        // Since Vettel is currently a 4 time world champion
        if (result == 1) // Result will return 1 if he finishes 5th, thus adding 1 more championship to his name (5 total)
        {    
            championship += 1;
        }
        else // If he finish lower than 5th, he will not win the championship thus championship gained is zero
        {
            championship += 0;
        }
    }
    void driver::setDriverResult(int result)
    {  
        if (result == 1)
        {
            outcome = "5th";
        }
        else if (result == -1)
        {
            outcome = "6th";
        }
        else if (result == -2)
        {
            outcome = "DNF"; 
        }
    }
    string driver::getDriverName() // Return the driver name
    {
        return racer_name;
    }
    string driver::getDriverResult()
    {
        return outcome;
    }
    int driver::getDriverPoints() // Return the total points
    {
        return points;
    }
    int driver::getDriverChampionship() // Return the number of championship Vettel has based on the results
    {
        return championship;
    }
