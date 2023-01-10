#include <iostream>
#include <ctime>
#include "hospital.h"
#include "gamer.h"

using namespace std;

void show_ground(int new_patient, string department[4], int patients_lists[3][4]) /*this func show ground with
  considering division of department*/
{

    for (size_t i = 0; i < 4; i++)
    {
        if (patients_lists[1][i] < 4) // when department divided
        {
            cout << "+--------------------+" << endl;
            cout << "|  " << department[i] << "(" << i << ")"
                 << "    |" << endl;
            cout << "| ";
            for (size_t j = 0; j < patients_lists[0][i] && j < patients_lists[1][i]; j++)
            {
                cout << "    *    ";
            }
            cout << " |" << endl;
            cout << "| ";
            for (size_t j = 0; j < patients_lists[0][i] && j < patients_lists[1][i]; j++)
            {
                cout << "   ***   ";
            }
            cout << " |" << endl;
            cout << "| ";
            for (size_t j = 0; j < patients_lists[0][i] && j < patients_lists[1][i]; j++)
            {
                cout << "    *    ";
            }
            cout << " |" << endl;
            cout << "| ";
            for (size_t j = 0; j < patients_lists[0][i] && j < patients_lists[1][i]; j++)
            {
                cout << "   * *   ";
            }

            cout << " |" << endl;
            cout << "+---------------------+" << endl;
            cout << "|  " << department[patients_lists[2][i]] << "(" << i << ")" // show secend place that' for an other department
                 << "     |" << endl;
            cout << "| ";
            for (size_t j = 0; j < (patients_lists[0][patients_lists[2][i]] - patients_lists[1][patients_lists[2][i]]); j++)
            {
                cout << "    *    ";
            }
            cout << "  |" << endl;
            cout << "| ";
            for (size_t j = 0; j < (patients_lists[0][patients_lists[2][i]] - patients_lists[1][patients_lists[2][i]]); j++)
            {
                cout << "   ***   ";
            }
            cout << "  |" << endl;
            cout << "| ";
            for (size_t j = 0; j < (patients_lists[0][patients_lists[2][i]] - patients_lists[1][patients_lists[2][i]]); j++)
            {
                cout << "    *    ";
            }
            cout << "  |" << endl;
            cout << "| ";
            for (size_t j = 0; j < (patients_lists[0][patients_lists[2][i]] - patients_lists[1][patients_lists[2][i]]); j++)
            {
                cout << "   * *   ";
            }
            cout << "  |" << endl;
        }
        else if (patients_lists[1][i] == 4) // show department with out dividing
        {
            cout << "+-----------------------------+" << endl;
            cout << "|        " << department[i] << "(" << i << ")"
                 << "       |" << endl;
            cout << "| ";
            for (size_t j = 0; j < patients_lists[0][i] && j < patients_lists[1][i]; j++)
            {
                cout << "   *   ";
            }
            cout << "| " << endl;
            cout << "| ";
            for (size_t j = 0; j < patients_lists[0][i] && j < patients_lists[1][i]; j++)
            {
                cout << "  ***  ";
            }
            cout << "| " << endl;
            cout << "| ";
            for (size_t j = 0; j < patients_lists[0][i] && j < patients_lists[1][i]; j++)
            {
                cout << "   *   ";
            }
            cout << "| " << endl;
            cout << "| ";
            for (size_t j = 0; j < patients_lists[0][i] && j < patients_lists[1][i]; j++)
            {
                cout << "  * *  ";
            }
            cout << "| " << endl;
        }
    }
}

int menu() // menu for start game
{
    cout << "*------------------------------*" << endl;
    cout << "|   enter (1) to start game    |" << endl;
    cout << "*------------------------------*" << endl;
    cout << "|   enter (2) for exit         |" << endl;
    cout << "*------------------------------*" << endl;
    int option = 0;
    cin >> option;
    cout << endl;
    system("CLS");
    return option;
}
void play_game(gamer *b1, hospital *a1) /*starting-setting name-calculating
 time limit-control enteral-patient arrival-show hospital-apply changes*/
{
    string name; // for set name
    int control; // user input
    bool temp;   // for determine the player's win
    switch (menu())
    {
    case 1:
        cout << "enter your name :";
        cin >> name;
        cout << endl;

        b1->set_name(name);
        b1->set_time(0); // set first time (0)for first time (1)for final time

        do
        {
            if ((b1->play_time[1]) - (b1->play_time[0]) > 30) // c
            {
                cout << "time of game ended !!!" << endl;
                cout << b1->show_score();
                return;
            }

            srand(static_cast<unsigned int>(time(0))); // use random for finding  new patient
            a1->new_patient = rand() % 4;

            system("CLS");
            cout << a1->department[a1->new_patient] << endl; // show patient
            cout << "   *  \n  *** \n   *  \n  * * \n";
            a1->show_hospital(); // show hospital with patients
            cout << "enter department number : ";
            cin >> control;
            cout << endl;
            system("CLS");

            b1->control_enteral(control);

            temp = a1->check_status(control);
            a1->changing_hospital((b1->control_enteral(control))); /*apply changing in hospital
                         to add patient or  detecting gamer is loss*/
            if (temp)                                              // check win
            {
                cout << "you win ;)))\n your score : ";
                cout << b1->show_score();
                return;
            }

            b1->increase_score();
            b1->set_time(1); // set final time
        } while (control >= 0 && control < 4);

        break;
    case 2:
        cout << "game ended.\ngood bye.\n";
        break;

    default:
        throw invalid_argument("incorrect enteral!!\ngood bye.\n");
        break;
    }
}
//----------------------------------------------------------------------------------------------------------------------//

void hospital::show_hospital() // sending private data to show_ground data
{
    show_ground(new_patient, department, patients_lists);
}
bool hospital::check_status(int control) // just for detecting that gamer is wins
{
    bool flag1 = true;

    if (patients_lists[0][control] == 6) // when the department's capacity that gamer selected  is 6 playar will win
    {
        return true;
    }
    else if (patients_lists[0][new_patient] >= patients_lists[1][new_patient]) /*when capacity of department if full or over
     we have to check new place that */
    {
        for (size_t i = 0; i < 4; i++)
        {
            if (patients_lists[2][i] == control && patients_lists[0][new_patient] - patients_lists[1][new_patient] == 2)
            {
                return true;
            }
            if (patients_lists[0][i] < 3 && patients_lists[1][i] != 2)
            {
                flag1 = false;
            }
        }
        if (flag1)
        {
            return true;
        }
    }

    return false;
}

void hospital::changing_hospital(int order)//this function change the  capacity and division
{
    if (new_patient == order)
    {
        if (patients_lists[0][new_patient] < patients_lists[1][new_patient])
        {
            patients_lists[0][new_patient]++;
        }
        else
        {
            throw out_of_range("you loss!!");
        }
    }
    else if (new_patient != order && patients_lists[0][new_patient] >= patients_lists[1][new_patient])
    {
        if (patients_lists[0][order] < 3 && patients_lists[2][order] == 5)
        {
            patients_lists[0][new_patient]++;
            patients_lists[2][order] = new_patient;
            patients_lists[1][order] -= 2;
        }
        else if (patients_lists[0][order] < 3 && patients_lists[2][order] == new_patient && patients_lists[0][new_patient] < 6)
        {
            patients_lists[0][new_patient]++;
        }
        else
        {
            throw out_of_range("your second department for puting patients dont have enogh capacity\n you loss!!");
        }
    }
    else
    {
        throw out_of_range("you loss!!");
    }
}
//-------------------------------------------------------------------------//

void gamer::set_time(int i)//for set peresent time
{
    play_time[i] = static_cast<int>(time(0));
}
void gamer::set_name(string temp)//set name
{
    name = temp;
    system("CLS");
}
int gamer::control_enteral(int temp)//validation enteral
{
    if (temp >= 0 && temp < 4)
    {
        order = temp;
        return temp;
    }
    else
    {
        throw invalid_argument("the control is not correct\n you loss");
    }
}
void gamer::increase_score()//increasing  score
{
    score += 10;
}
int gamer::show_score()//returning score
{
    return score;
}
