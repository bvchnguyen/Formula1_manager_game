// CS1300 Fall 2020
// Author: Bach Nguyen
// Recitation: 505 -- Madhusudhan Aithal
// Project 3 -- Player implimentation file

#include "Player.h"
#include <string>
using namespace std;

Player::Player() // Intialized default constructors
{
    player_name = "";
    
}
Player::Player(string p_name) //Intialized parameterized constructors
{
    player_name = p_name;
}

void Player::setPlayerName(string p_name) // Set player's name based on input
{
    player_name = p_name;
}

string Player::getPlayerName() const // Return player's name
{
    return player_name;
}
