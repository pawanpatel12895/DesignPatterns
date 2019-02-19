#ifndef CALCULATORAPP_H
#define CALCULATORAPP_H

#include <iostream>
using namespace std;
namespace commandspace{
    class CalculatorApp{

    private:
        // single instance of the app;
        static CalculatorApp instance;
        // private constructor
        CalculatorApp(){};   
        
        void printMenu();
        void printdata(int);
        pair<string,int> getinput();
    protected:
            //nothing
    public:
        // retriving the single instance
        static CalculatorApp & getInstance();
        //
        void run();
    };
}
#endif 