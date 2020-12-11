// CS1300 Fall 2020
// Author: Bach Nguyen
// Recitation: 505 -- Madhusudhan Aithal
// Project 3 - Header files

#ifndef Display_H
#define Display_H
#include <string>

using namespace std; 

class Display 
{
    public:

        Display();
        Display(string file);
        void printWelcome();
        void printInterface(string menu);
        void command();
        void printSubMenu();
        void tireSelections();
    private:

        string text_file;

};
#endif