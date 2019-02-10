#include "../headers/AddCommand.h"
#include <iostream>
using namespace std;

// at least one object is required to add instance in the tracking vector
AddCommand __addCommand;

//overridden function
string AddCommand::getName(){
    return "add";
}
//overridden function
void AddCommand::execute(int &operand1, int operand2){
    operand1 += operand2; 
}

// added for debug  purpose;
AddCommand::AddCommand(){
    cout<<"method : "<<__FUNCTION__<<endl;
}
AddCommand::~AddCommand(){
    cout<<"method : "<<__FUNCTION__<<endl;
}