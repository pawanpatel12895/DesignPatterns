#include "../headers/Command.h"
#include "../headers/AddCommand.h"
#include "iostream"

namespace commandspace{

    //tracking vector: stores the instances of objects of subclasses.
    vector<Command*> &Command::getvector(){     
        static vector<Command*> *commands = new vector<Command*>();
        return *commands;
    }
    int Command::gettotalCommands()
    {
        return Command::getvector().size();
    }

    // constructor of Command Class, modifies the tracking vector
    Command::Command()
    {
        getvector().push_back(this);
        cout<<"method : "<<__FUNCTION__<<"vector size changed to : "<<getvector().size()<<endl;
    }
    // dtor added for debugging purpose
    Command::~Command(){
        cout<<"method : "<<__FUNCTION__<<endl;
    }
    Command *Command::getCommand(const string commandname)
    {
        for (Command *command : Command::getvector())
            {
                if(command->getName() == commandname)
                    return command;
            }
        return NULL;
    }
}