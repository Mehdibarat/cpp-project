#include <iostream>
#include <ctime>
#include "hospital.h"
#include "gamer.h"

using namespace std;

hospital a1;//public object of hospital
int menu();//show starting menu
void show_ground(int, string, int);//show ground of game whit patients
void play_game(gamer *, hospital *);//starting-setting name-calculating time limit-control enteral-patient arrival-show hospital-apply changes

int main()
{

    gamer b1;//object of player
    try
    {
        play_game(&b1, &a1);//sending object to play game function
    }
    catch (invalid_argument &e)
    {

        cerr << e.what() << '\n';
        cout << "score : " << b1.show_score();
    }
    catch (out_of_range &e)
    {
        cerr << e.what() << '\n';
        cout << "score : " << b1.show_score();
    }

    return 0;
}