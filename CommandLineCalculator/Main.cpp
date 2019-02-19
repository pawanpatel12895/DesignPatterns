#include <iostream>
#include "headers/CalculatorApp.h"
#include "headers/AddCommand.h"


using namespace std;
using namespace commandspace; 
int main(){
    CalculatorApp calculatorApp = CalculatorApp::getInstance() ;
    calculatorApp.run();
    return 0;
}