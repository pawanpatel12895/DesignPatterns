#include <iostream>
#include "headers/CalculatorApp.h"
#include "headers/AddCommand.h"


using namespace std;

int main(){
    CalculatorApp calculatorApp = CalculatorApp::getInstance() ;
    calculatorApp.run();
    return 0;
}