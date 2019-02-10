
#include "../headers/CalculatorApp.h"
#include <iostream>
#include "../headers/Command.h"
using namespace std;

CalculatorApp CalculatorApp::instance;
//Singleton for now
CalculatorApp &CalculatorApp::getInstance()
{
    return instance;
}
void CalculatorApp::printdata(int data){
    cout<<data<<endl;
}
void CalculatorApp::printMenu(){

}
pair<string,int> CalculatorApp::getinput(){
    string s;
    int r;
    cin>>s>>r;
    return make_pair(s, r);
}
void CalculatorApp::run()
{   cout<<"method : "<<__FUNCTION__<<endl;
    int data = 0;
    cout<<"Size of static Command::commands vector is "<<Command::commands.size()<<endl;
    while(1)
    {
        printdata(data);
        printMenu();
        pair<string,int> input = getinput();
        
        for (Command *command : Command::commands)
        {
            if(command->getName() == input.first)
                command->execute(data, input.second);
        }
        
    }
}
