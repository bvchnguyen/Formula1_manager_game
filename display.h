// display - Header files

#ifndef display_H
#define display_H
#include <string>

class display 
{
    public:

        display();
        display(string file);
        void printWelcome();
        void printInterface(string menu);
        void command();
        void printSubMenu();
        void tireSelections();
    private:

        string text_file;

};
#endif
