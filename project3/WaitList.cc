/**
 * @file WaitList.cc
 * @author lainie daniel 
 * @brief definition class for waitlist.h
 * @version 0.1
 * @date 2023-03-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "WaitList.h"
#include "appointment.h"
#include "node.h"
#include <fstream>
#include <iostream>

/*

5. See the wait time for the person waiting the longest. (This person should be at the front
of the line.)
6. See the average wait time for everyone in the list.
7. Identify the oldest person in the list.
8. Identify the youngest person in the list.
9. See the average age of those waiting.
*/

/*Appointment waitlist::find(std::string n){
    node* cursor;
    cursor = head;
    while(cursor != NULL){
    if((cursor -> data()).get_name() == n){
        return cursor -> data();
    }
    }
}

unsigned waitlist::average_wait(){
    node* cursor = head;
    
}*/

//deconstructor 
WaitList::~WaitList(){
    //have to deallocate each node individually 
    //hold onto each node, move head to next, deallocate the skipped node
    node* rmptr; //remove pointer 

    while(head != NULL){
        rmptr = head;
        head = head -> next();
        delete rmptr;
    }
}

//copy constructor 
WaitList::WaitList(const WaitList& other){

}

//load the saved in stream
void WaitList::load(std::istream& inF){
    node* cursor; 
    Appointment ap;
    while(!inF.eof()){
        if(head == nullptr){
            head = new node;
            ap.input(inF);
            (head -> set_data(ap));
            (head -> set_next(nullptr));
            cursor = head;
        }
        else{
            (cursor -> set_next(new node(ap, nullptr)));
            cursor = cursor -> next();
            ap.input(inF);
            (cursor -> set_data(ap));
            (cursor -> set_next(nullptr));
        }
    }
}

//display list to chosen out stream
void WaitList::display(std::ostream& outS){
    node* cursor = head;
    while(cursor != nullptr){
        outS << (cursor -> data());
        cursor = (cursor -> next());
    }
}

//add new apt to list 
void WaitList::add(Appointment new_apt){
    if(head == nullptr){
       head = new node(new_apt, nullptr); 
    }

    node* cursor = head;
    node* prev = nullptr;
    bool added = false;

    //check if put before head of list 
    if(cursor -> data() > new_apt){
        head = new node(new_apt, head);
    }
    else{
        cursor = cursor -> next();
        while(added == false && cursor != nullptr){
            if(new_apt >= cursor -> data()){
                prev = cursor;
                cursor = cursor -> next();
            }
            else{
                added = true;
            }
        }
        prev -> set_next(new node(new_apt, cursor));
    }
}

//find appointment by name 
Appointment WaitList::find(std::string name){
    if(head == nullptr){
        std::cout << "EMPTY LIST" << std::endl;
    }

    node* cursor = head;

    while(cursor != nullptr){
        if(cursor -> data().get_name() == name){
            return cursor -> data();
        }
        else{
            cursor = cursor -> next();
        }
    }
}

//remove apt from list 
void WaitList::remove(std::string name){
    if(head == nullptr){
        return;
    }

    node* cursor = head;
    node* prev = nullptr;

    if(head -> data().get_name() == name){
        head = head -> next();
        delete cursor;
    }
    else{
        while(cursor != nullptr && cursor -> data().get_name() != name){
            prev = cursor;
            cursor = cursor -> next();
        }
        if(cursor != nullptr){
            prev -> set_next(cursor -> next());
            delete cursor;
        }
    }
}

//total waiting 
int WaitList::waiting(){
    int count = 0; 
    node* cursor = head;
    while(cursor != nullptr){
        count++;
        cursor = cursor -> next();
    }
    return count;
}

//longest wait 
unsigned WaitList::longest_wait(){
    Date today;
    today.make_today();

    return head -> data().get_callin().minutes_since_1970();
}

//avg wait time 
/*
unsigned WaitList::average_wait(){
    node* cursor = head;
    Date today, tmp;
    int day = 0, sum = 0, count = 0;

    today.make_today();
    
    while(cursor != nullptr){
        tmp = cursor -> data().get_callin();
        day = tmp.age(today);
        sum = sum + day;
        count++;
        cursor = cursor -> next();
    }
    return (sum/count);
}*/

//oldest person 
/*unsigned WaitList::oldest(){
    node* old = head;
    node* test = head -> next();
    while(test != nullptr){
        if(test -> data().get_bday().minutes_since_1970() >= old -> data().get_bday().minutes_since_1970()){
            old = test;
            test = test -> next();
        }
        else{
            test = test -> next();
        }
    }

    return old -> data().get_bday().minutes_since_1970();
}*/

//youngest person 
/*unsigned WaitList::youngest(){
    node* young = head;
    node* test = head -> next();
    while(test != nullptr){
        if(test -> data().get_bday().minutes_since_1970() <= young -> data().get_bday().minutes_since_1970()){
            young = test;
            test = test -> next();
        }
        else{
            test = test -> next();
        }
    }
    return 0;

    //return convert_minutes(young -> data().get_bday().minutes_since_1970());
}*/

//average age 
unsigned WaitList::average_age(){
    return 0;
}