// CS1300 Fall 2020
// Author: Bach Nguyen
// Recitation: 505 -- Madhusudhan Aithal
// Project 3 - Header files

#ifndef Player_H
#define Player_H
#include <string>

using namespace std; 

class Player
{
    public:

        Player();
        Player(string b_name);
        void setPlayerName (string p_name);
        string getPlayerName() const;

    private:

        string player_name;
};
#endif