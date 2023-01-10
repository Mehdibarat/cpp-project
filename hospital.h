#include <iostream>

using namespace std;
#ifndef HOSPITAL_H
#define HOSPITAL_H

class hospital
{
public:
    void show_hospital();                                                                // sending private data to show_ground data
    bool check_status(int);                                                              // just for detecting that gamer is wins
    void changing_hospital(int);                                                         // this function change the  capacity and division
    int new_patient;                                                                     // random create new patient category
    string department[4] = {"orthopedics", " maternity ", " neurology ", "   heart   "}; // name of department

private:
    int patients_lists[3][4] = {{0, 0, 0, 0}, {4, 4, 4, 4}, {5, 5, 5, 5}}; // [0][i] number  of patient in each department
    /*[1][i]capacity of each department*/
    /*[2][i]the number of the department divided by this department*/
    /*[5] is  an invalid initialization*/
};
#endif
