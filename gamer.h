#include <iostream>

using namespace std;

class gamer
{
public:
    void set_name(string);    /// setting name
    int control_enteral(int); // validation enteral
    void set_time(int);       // for set first time and final time
    void increase_score();    // increasing score
    int show_score();         // return mount of score
    int play_time[2] = {0, 0};

private:
    int order; // for selecting location for each patient
    string name;
    int score = 0;
};
