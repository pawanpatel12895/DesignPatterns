#ifndef COMMAND_H
#define COMMAND_H
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Command
{
protected:
    // protected ctor : I do not want object to Command Class, but need objects of subclasses.
    Command();
    
public:
    // tracking vector for objects of subclasses
    static vector<Command*> commands;
    
    //abstract functions to be used by subclasses
    virtual void execute(int&, int) = 0;
    virtual string getName() = 0;
    
    // added dtor for debug purpose
    virtual ~Command();
};
#endif