// driver - Header files

#ifndef driver_H
#define driver_H
#include <string>

using namespace std; 

class driver
{

    public:

        driver();
        driver(string driver_name, string out_come, int total_points, int total_championship);
        void setDriverName(string driver_name);
        void setDriverPoints(int gained_points);
        void setDriverChampionship(int result);
        void setDriverResult(int result);
        string getDriverName();
        string getDriverResult();
        int getDriverPoints();
        int getDriverChampionship();

    private:

        string racer_name, outcome;
        int points, total_points, current_lap, championship;
};
#endif
