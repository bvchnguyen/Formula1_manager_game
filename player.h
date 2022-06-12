// player - Header files

#ifndef player_H
#define player_H
#include <string>

using namespace std; 

class player
{
    public:

        player();
        player(string b_name);
        void setPlayerName (string p_name);
        string getPlayerName() const;

    private:

        string player_name;
};
#endif
