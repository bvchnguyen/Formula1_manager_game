// CS1300 Fall 2020
// Author: Bach Nguyen
// Recitation: 505 -- Madhusudhan Aithal
// Project 3 -- Game implimentation file

#include <iostream>
#include "Display.h"
#include <string>
#include <fstream>

using namespace std;

Display::Display()
{
    text_file = "";
}
Display::Display(string file)
{
    text_file = file;
}
void Display::printWelcome() // Print this when player first enters the game
{
    cout << "welcome in! The team is waiting for you in the paddock." << endl;
    cout << "Before you enter the pit box, security has asked for your credential. Please enter your first name: " << endl;

return;
}
void Display::printInterface(string menu) // Printing the main menu from text file
{   
    ifstream inFile;
    inFile.open(menu);
    string line;

    if (!inFile.fail())
    {
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
    }
    inFile.close();
return;
}
void Display::command() // Print the main command in the main game loops
{
    cout << "1. PUSH (go faster but -- consume 1.70 kg fuel / per lap)" << endl;
    cout << "2. CONSERVE FUEL (go slower but -- consume 1.30 kg fuel / per lap)" << endl;
    cout << "3. BOX, BOX (Change tyres but -- add 26 seconds to the total time)" << endl;
    cout << "Please choose an instruction for the next 10 laps (1-3): " << endl;
}
void Display::printSubMenu() // Sub menu (within the main menu)
{
    cout << "Please choose an option (1-3): " << endl;
    cout << "1. Pre-race briefing" << endl;
    cout << "2. Instructions" << endl;
    cout << "3. Back to main menu" << endl;
}
void Display::tireSelections() // This will print the tyre choice every time user pits
{
    cout << "1. SOFTS (fastest but least durable)" << endl;
    cout << "2. MEDIUMS (less fast but more durable)" << endl;
    cout << "3. HARD (slowest but most durable)" << endl;
    cout << "Enter your tyre selection (1-3): " << endl;

return;
}
