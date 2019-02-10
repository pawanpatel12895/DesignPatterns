#include <iostream>
#include <string>
using namespace std;

enum LogLevel
{
        ERROR,
        SEVERE,
        LOG,
        INFO
};
class Logger{
public:
    bool log(LogLevel loglevel, string log){
        cout<<loglevel<< " : "<< timestamp() <<" : " << log<<endl;
    }
    string timestamp(){
        return "";
    }
};