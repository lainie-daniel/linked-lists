/**
 * @file WaitList.h
 * @author lainie daniel 
 * @brief waitlist class that keeps track of people in line for appointments 
 * @version 0.1
 * @date 2023-03-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */



#ifndef WAIT_H
#define WAIT_H

#include "node.h"
#include "appointment.h"
/*
1. Add a new Appointment request to the list. (It will be inserted in order.)
2. View the entire list of Appointments, in the order they are stored.
3. Remove a person’s appointment because they have found an appointment at another
location. This will use the find function, and both will take a string which is the name of
the patient.
4. Learn the number of people waiting in line.
5. See the wait time for the person waiting the longest. (This person should be at the front
of the line.)
6. See the average wait time for everyone in the list.
7. Identify the oldest person in the list.
8. Identify the youngest person in the list.
9. See the average age of those waiting.
*/

class WaitList{
    public:
        WaitList() {head = nullptr;}

        //big 3
        ~WaitList();
        WaitList(const WaitList& other);
        WaitList& operator = (const WaitList& other);
        
        //load a file stream 
        void load(std::istream& inF);

        //display the list 
        void display(std::ostream& outS);

        //put new node person in the list 
        void add(Appointment new_apt);

        //find apt in list 
        Appointment find(std::string name);

        //remove someone from list 
        void remove(std::string name);

        //number waiting 
        int waiting();

        //longest wait 
        unsigned longest_wait();

        //average wait 
        unsigned average_wait();

        //oldest person 
        unsigned oldest();

        //youngest person 
        unsigned youngest();

        //avg age 
        unsigned average_age();
        
    private:
        node* head;

};

#endif 