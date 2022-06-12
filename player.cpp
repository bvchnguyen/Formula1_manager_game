// CS1300 Fall 2020
// Author: Bach Nguyen
// Recitation: 505 -- Madhusudhan Aithal
// Project 3 -- Player implimentation file

#include "player.h"
#include <string>

player::player() // Intialized default constructors
{
    player_name = "";
    
}
player::player(string p_name) //Intialized parameterized constructors
{
    player_name = p_name;
}

void player::setPlayerName(string p_name) // Set player's name based on input
{
    player_name = p_name;
}

string player::getPlayerName() const // Return player's name
{
    return player_name;
}
