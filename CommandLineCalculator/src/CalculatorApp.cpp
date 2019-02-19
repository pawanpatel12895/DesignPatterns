
#include "../headers/CalculatorApp.h"
#include <iostream>
#include "../headers/Command.h"
using namespace std;
namespace commandspace{
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
        cout<<"Size of static Command::commands vector is "<<commandspace::Command::gettotalCommands()<<endl;
        while(1)
        {
            printdata(data);
            printMenu();
            pair<string,int> input = getinput();
            
            Command *command = commandspace::Command::getCommand(input.first);
            if(command != NULL)
                command->execute(data, input.second);
            else
                cout<<"command not found"<<endl;
            
        }
    }
}