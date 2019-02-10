#include "../headers/Command.h"
#include "../headers/AddCommand.h"
#include "iostream"

//tracking vector: stores the instances of objects of subclasses.
vector<Command*> Command::commands;

// constructor of Command Class, modifies the tracking vector
Command::Command()
{
    Command::commands.push_back(this);
    cout<<"method : "<<__FUNCTION__<<"vector size changed to : "<<commands.size()<<endl;
}
// dtor added for debugging purpose
Command::~Command(){
    cout<<"method : "<<__FUNCTION__<<endl;
}
