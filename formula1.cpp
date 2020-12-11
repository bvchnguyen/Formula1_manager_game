// CS1300 Fall 2020
// Author: Bach Nguyen
// Recitation: 505 -- Madhusudhan Aithal
// Project 3 - Main Driver File
// Compile C&P - g++ player.cpp Driver.cpp Car.cpp Display.cpp formula1.cpp

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include "Display.h"
#include "Player.h"
#include "Driver.h"
#include "Car.h"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

// Function prototyping
int random(int size);
int IDverify(string engineer_name);
double tireWear(int counter, int tyre_choice, Car Ferrari);
int getResult(int lap, int checker, double time, Car Ferrari, Driver Vettel);
void printStats(int lap, double time, Car Ferrari, Driver Vettel);
void recordResults(int outcome, int counter, Car Ferrari, Driver Vettel, Player engineer);

int main()
{   
    // Declaring variables and class
    // count starts at 1 & lap_count at 10 as we are entering the main game after the first 10 laps
    double total_time, fuel;
    int x, y, z, option, result;
    int DNF_check = 0, count = 1, lap_count = 10;
    string name;
    Display play;
    Player engineer;
    Driver Vettel;
    Car Ferrari;

    //cout << "Welcome to the Formula 1 Manager Game!" << endl; // Welcome header
    play.printInterface("HeaderWelcome.txt");
    // Main menu
    while (x != 4 && x != 5) // Only runs when x is not 3 (going into the game) or 4 (exit game)
    {
        play.printInterface("menu.txt"); // Main menu
        cout << "Please enter an option (1-5): " << endl;
        cin >> x;
        
        if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5) // Checking for user error
        {
            switch(x) // Using switch statement for the main menu
            {
                case 1:
                    
                    while (z != 3) // Exit input
                    {
                        play.printSubMenu(); // Print sub menu
                        cin >> z;
                        
                        if (z == 1 || z == 2 || z == 3) // Checking for user error
                        {
                            if (z == 1)
                            {
                                play.printInterface("Race_Briefing.txt"); // Race background
                            }
                            else if (z == 2)
                            {
                                play.printInterface("Instructions.txt"); // Instructions for the race
                            }
                            else if (z == 3)
                            {
                                break; // Break out of the loop and back to main menu
                            }
                        }
                        else // Invalid input (anything other than 1-3)
                        {
                            cout << "Invalid option. Please try again" << endl; // Checking for user error
                        }
                    }
                    break;
                
                case 2:
                    // Print point system from text file
                    play.printInterface("Points_Systems.txt");
                    break;

                case 3:

                    // Print the current championship standing
                    play.printInterface("Championship_standing.txt");

                    break;

                case 5:
                    // Player quits
                    cout << "Goodbye!" << endl;
                    break;
            }
        }
        else
        {
            // If user input is invalid
            cout << "Invalid option. Please try again" << endl;
        }
    }
    if (x == 4) // Entering the game
    {
        play.printWelcome(); // Print instructions
        cin >> name; 
        while (IDverify(name) != 1) // Check for user error -- Credentials must be alphabetical value
        {
            cout << "Invalid -- Terminal only accepts alphabetical values" << endl;
            cin >> name;

        }
        engineer.setPlayerName(name); // Set the player's name
        cout << "Credentials accepted | Before the race starts, which tyre would you like Vettel to start with?" << endl;
        play.tireSelections(); // Display tyre choices
        cin >> y;
        while (y < 1 || y > 3) // Checking for user error
        {
            cout << "Invalid option. Please try again." << endl;
            play.tireSelections(); // Display tyre choices
            cin >> y;
            if (y >= 1 && y <= 3) // If user enters correct choices
            {
                break; // break out of the loops
            }
        }
        cout << "The Race has begin. We will let Vettel settled down and check in with him every 10 laps" << endl;
        Ferrari.setLapTimes(y, 1); // Set the lap times base off of the tyre choice
        Ferrari.setCarTyre(y); // Set the current tyre compound based on user's input
        Ferrari.setCarFuel(1.57); // Set the fuel consumption for the first 10 laps (not pushing or conserving fuel)
        Ferrari.setCarLaps(lap_count); // Set the lap count
        total_time = Ferrari.getLapTimes(); // Set total_time to the sum of the lap times of the first 10 laps

        while (lap_count < 70) // Loop will run while the lap count is less than 70
        {   
            printStats(lap_count, total_time, Ferrari, Vettel);

            // Ask user what to instruct Vettel to do
            play.command();
            cin >> option;

            if (option == 1 || option == 2 || option == 3) // Check for user error
            {
                if (option == 1) // Command Vettel to push (go faster)
                {   
                    Ferrari.setLapTimes(y, option); // Lap times will be based Vettel pushing
                    Ferrari.setCarFuel(1.67); // Fuel consumption will increase to 1.7 kg / per lap for the next 10 laps
                    count++; // Counter to use to affect lap times if you ask Vettel to stay out beyond the tyre's recommended max usage
                }
                else if (option == 2) // Command Vettel to conserve fuel (slow down)
                {
                    Ferrari.setLapTimes(y, option); // Lap times will be based Vettel conserving fuel
                    Ferrari.setCarFuel(1.37); // Fuel consumption will decrease to 1.3 kg / per lap for the next 10 laps
                    count++; // Counter to use to affect lap times if you ask Vettel to stay out beyond the tyre's recommended max usage
                }
                else if (option == 3) // Command Vettel to put and change tyres
                {
                    cout << "what tyres do you want Vettel to change to?" << endl;
                    Ferrari.setCarFuel(1.57); // Fuel consumption will stay at 1.45 kg / per lap for the next 10 laps
                    play.tireSelections(); // Display tyre choices
                    cin >> y;
                    while (y < 1 || y > 3) // Checking for user error
                    {
                        cout << "Invalid option. Please try again." << endl;
                        play.tireSelections(); // Display tyre choices
                        cin >> y;
                        if (y >= 1 && y <= 3) // If user enters correct choices
                        {
                            break; // break out of the loops
                        }
                    }
                    Ferrari.setLapTimes(y, option); // Set lap times accordingly to the tyre choice
                    Ferrari.setCarTyre(y); // Set the current tyre compound based on user's input // Add 26 seconds due to the pit stop
                    count = 1; // Reset count as Vettel made a pit stop to put on fresh tyres
                }
                if (count >= 2) // If you ask Vettel to stay out for too long
                {
                    tireWear(count, y, Ferrari);
                    total_time = Ferrari.getLapTimes() + tireWear(count, y, Ferrari); // Lap times will be increased
                    lap_count += 10; // Increase the lap count for the loop iteration
                    if (tireWear(count, y, Ferrari) == -1) // If tireWear returns -1;
                    {   
                        // The tyres blew out because you asked Vettel to use the same set of tyre beyond it's max capability
                        cout << "DNF, tire failure! Better luck next season mate." << endl;
                        DNF_check++; // increase DNF checker if Vettel fails to complete the race
                        break; // End the loop (break out of it)
                    }
                }
                else // You've instructed Vettel to put on new sets of rubber
                {   
                    total_time = Ferrari.getLapTimes();
                    Ferrari.setCarLaps(lap_count); // set Vettel's lap count
                    lap_count += 10; // Increase the lap count for the loop iteration
                } 
                // If Vettel runs out of fuel before the race is completed
                if ((Ferrari.getCarFuel() <= 0 || Ferrari.getCarFuel() < 13.7) && lap_count < 70)             
                {   
                    cout << "DNF! Looks like you ran out of fuel and cannot finish the race. Better luck next season." << endl;
                    DNF_check++; // increase DNF checker if Vettel fails to complete the race
                    break; // End the loop (break out of it)
                }         
            }
            else // If user doesn't enter the correct input choices that are displayed
            {
                cout << "Invalid option. Please try again." << endl;
            }

        }
        if (DNF_check == 0)
        {
            result = getResult(lap_count, DNF_check, total_time, Ferrari, Vettel); // Get result if Vettel finish the race

            cout << "Total Time: " << total_time << " minutes | Remaining Fuel: " << Ferrari.getCarFuel() << " kg" << endl; 

            if (result == 1)
            {
                Vettel.setDriverPoints(10); // 10 points is according to 5th position finish 
                cout << "Congratulations! You have helped Sebastian Vettel to his 5th World Championship!" << endl;
            }
            else if (result == -1)
            {
                Vettel.setDriverPoints(8); // 8 points earned is according to 6th position finish
                cout << "Looks like Vettel finished outside of the targetted 5th place. Better luck next season." << endl;
            }
            else if (result == -2)
            {
                Vettel.setDriverPoints(0); // No points earned as Vettel did not finish (DNF)
                cout << "DNF! Looks like Vettel ran out of fuel within the last 10 laps. Tough luck!" << endl;
            }
        }
        else
        {
            result = getResult(lap_count, DNF_check, total_time, Ferrari, Vettel); // Get result if DNF happens before Vettel completes the race
        }
        recordResults(result, DNF_check, Ferrari, Vettel, engineer); // Record results to a text file
        play.printInterface("Results.txt"); // Print the final result
    }
return 0;
}
int random(int size)
{
    // This function will fill an array with randomly generated value from 0 to 3, then return the value at the last index of the array
    // We will then use this helper function to help determine the chance or a random event happening

    srand(time(0)); // To maximize randomness cite: https://www.youtube.com/watch?v=naXUIEAIt4U&t=506s
    int random[size]; // Initialize the array

    for (int i = 0; i < size; i++) // Loop to traverse through the array
    {
        random[i] = rand() % 3; // Filling array
    }
return random[size - 1]; // Use the last index of the array to compare
}
int IDverify(string engineer_name)
{
    // This function checks for user error when entering the name (credential)

    int count_checker = 0; // Declare a checker variable
    for (int i = 0; i < engineer_name.length(); i++) // Loop to traverse trough the length of name entered
    {
        if (!isalpha(engineer_name[i])){ // If one of the value is not a letter

            return -1;
            count_checker++; // Checker will increment
        }
    }
    if (count_checker == 0) // If checker stays at 0, return 1
    {
        return 1;
    }
return 1;
}
double tireWear(int counter, int tyre_choice, Car Ferrari)
{
    // This function will take in a count checker, the tyre choice and the lap time to compute tyre wear 

    // Declare variables
    int chance = 0; 
    double increase;

    if (tyre_choice == 1) // If the chosen tyre choice is the soft compound
    {
        if (counter >= 2) // You instructed Vettel to stay out for more than 20 laps on the same set of soft compound
        {
            chance = random(2); // 30% chance of a tyre failure
            if (chance == 1)// If chance match
            {
                return -1; // Return -1 if tyres did blow out
            }
            else
            {
                increase = (Ferrari.getLapTimes() * (0.02)); // If not a blow out, the lap times will increase by 6%
            }
        }
    }
    else if (tyre_choice == 2) // If the chosen tyre choice is the medium compound
    {
        if (counter >= 3) // You instructed Vettel to stay out for more than 30 laps on the same set of medium compound
        {
            chance = random(2); // 30% chance of a tyre failure
            if (chance == 1) // If chance match
            {
                return -1; // Return -1 if tyres did blow out
            }
            else
            {
                increase = (Ferrari.getLapTimes() * (0.03)); // If not a blow out, the lap times will increase by 4%
            }
        }
    }
    else if (tyre_choice == 3) // If the chosen tyre choice is the hard compound
    {
        if (counter >= 4) // You instructed Vettel to stay out for more than 40 laps on the same set of medium compound
        {
            chance = random(2); // 30% chance of a tyre failure
            if (chance == 1) // If chance match
            {
                return -1; // Return -1 if tyres did blow out
            }
            else
            {
                increase = (Ferrari.getLapTimes() * (0.04)); // If not a blow out, the lap times will increase by 3%
            }
        }
    }
return increase;
}
int getResult(int lap, int checker, double time, Car Ferrari, Driver Vettel)
{
    // This function will return a value depending on the final result
    if (time <= 140.00 && Ferrari.getCarFuel() > 0 && checker == 0) // If Vettel finish 5th place (less than or equal to 140 minutes and finish with fuel left)
    {
        return 1;
    }
    else if ((time > 140.00 && Ferrari.getCarFuel() > 0) && checker == 0) // If Vettel finish 6th place (greater than 140 minutes or finish with negative fuel)
    {
        return -1;
    }
    else if (Ferrari.getCarFuel() <= 0 || checker > 0) // If Vettel ran out of fuel or suffered a tyre blow out (DNF)
    {
        return -2;
    }
return 1;
}
void printStats(int lap, double time, Car Ferrari, Driver Vettel)
{   
    // This function will print the stats of Vettel (current lap, fuel, time, and tyres)

    Ferrari.setCarLaps(lap);

    cout << "Vettel is now on lap " << Ferrari.getCarLaps(); // Print current lap
    cout << " -- Current Tyre: " << Ferrari.getCarTyre(); // Print current tyre compound
    cout << " -- Current Fuel load: " << Ferrari.getCarFuel() << " kg"; // Print current fuel
    cout << " -- Current Time: " << time << " minutes" << endl; // Print current time

return;
}
void recordResults(int outcome, int counter, Car Ferrari, Driver Vettel, Player engineer)
{
    // This function will print the result into a text file
    Vettel.setDriverName("Vettel");
    Vettel.setDriverChampionship(outcome); // Set Championship count based on outcome
    Vettel.setDriverResult(outcome); // Set Result of the season based on outcome

    ofstream outFile;
    outFile.open("Results.txt");
    if (!outFile.fail())
    {   
        // Printing normal statistics
        outFile << "\n======= POST RACE STATISTICS =======\n" << endl;
        outFile << "Player Name: " << engineer.getPlayerName() << endl;
        outFile << "Driver Name: " << Vettel.getDriverName() << endl;
        outFile << "Total Time: " << Ferrari.getLapTimes() << endl;
        outFile << "Fuel Remaining: " << Ferrari.getCarFuel() << endl;
        outFile << "Total points: " << Vettel.getDriverPoints() << endl;

        if (outcome == 1) // Print this if Vettel won the championship
        {
            outFile << "Result: " << Vettel.getDriverResult() << " -- Won the Championship" << endl;
            outFile << "Championship: " << Vettel.getDriverChampionship() << endl; // Will display that Vettel has his 5th championship
            
        }
        else if (outcome == -1 || outcome == -2) // Print one of this base on the condition met (if Vettel lose/DNF)
        {   
            if (counter > 0 || outcome == -2)
            {
                outFile << "Result: " << Vettel.getDriverResult() << " -- lost the Championship" << endl; // DNF result
                outFile << "Championship: " << Vettel.getDriverChampionship() << endl; // Will display that Vettel has 4 championship
            }
            else
            {
                outFile << "Result: " << Vettel.getDriverResult() << " -- lost the Championship" << endl; // Finished but outside of 140 minutes
                outFile << "Championship: " << Vettel.getDriverChampionship() << endl; // Will display that Vettel has 4 championship
            }
        }
        outFile << "____________________________________" << endl;
    }

outFile.close();
return;
}