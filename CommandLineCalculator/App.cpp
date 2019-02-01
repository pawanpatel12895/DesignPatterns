#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// headers

class Command
{
    private:
    protected:
    /// ctor is protected as we don't want objects of Commands 
    ///	and need it accessible to sub-classes to make their objects instead;
    Command();
    public:
    // traking static vector for objects
    static vector<Command*> commands;
    
    // every command needs execution;
    virtual void execute(int&, int) = 0;  // abstract function. uses '= 0'

    // every command will have a operator in string format;
    virtual string getName() = 0;  //// abstract function. uses '= 0'

    //dtor not necessary at present
    virtual ~Command();
};

class CalculatorApp{ // singleton class;
    // don't know why i made it singleton;
private:
    // single instance of the app;
    static CalculatorApp instance;
    // private constructor
     CalculatorApp(){};   
    
    void printMenu();
    void printdata(int);
    pair<string,int> getinput();

public:
    // retriving the single instance
    static CalculatorApp & getInstance();
    // running the app; 
    void run();
};


///////////////////////////////////////////////////////////////////////////
int main(){
    CalculatorApp calculatorApp = CalculatorApp::getInstance() ;
    calculatorApp.run();
    return 0;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// C++ needs static variables declared outside too. no alternatives;
CalculatorApp CalculatorApp::instance;

CalculatorApp &CalculatorApp::getInstance()
{	//return single instance
    return instance;
}
void CalculatorApp::printdata(int data){
    cout<<"######################## VALUE IS : "<<data<<endl;
}
void CalculatorApp::printMenu(){
	cout<<"Commands Available :"<<endl;
	for (Command *command : Command::commands)
	{
            cout<<"*** "<<command->getName()<<endl;
    }
}
pair<string,int> CalculatorApp::getinput(){
    string s;
    int r;
    cout<<"Enter separated by space {'Command',  'value'} : ";
    cin>>s>>r;
    return make_pair(s, r);
}
void CalculatorApp::run()
{
    int data = 0;
    while(true){
        printdata(data);
        printMenu();
        pair<string,int> input = getinput();
        for (Command *command : Command::commands){
            if(command->getName() == input.first)
                command->execute(data, input.second);
        }
        cout<<"_________________"<<endl;
    }
}

//////////////////

vector<Command*> Command::commands;
Command::Command()
{
	// 'this' is pointer to the object to its class or subclasses; 
	// in our case 'this' holds object pointer to subclass. 
	// hence add to traking vector; 
    Command::commands.push_back(this);
}
Command::~Command(){
	// nothing in dtor;
	// since there are no dynamic memory allocation, no explicit leaks will occour;
}
///////////////////


/////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////plugin style;/////////////////////////
/// 1. add new class inheriting 'Command' with no change in above code.
/// 2. implemnent the two abtract methods; 
//////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////


//////// ADD command
class AddCommand : public Command{
    public:
    virtual void execute(int&, int);
    virtual string getName();
};



AddCommand __addCommand;
string AddCommand::getName(){
    return "add";
}
void AddCommand::execute(int &operand1, int operand2){
    operand1 += operand2; 
}


////////////////////// SUBTRACT command
class SubCommand : public Command{
    public:
    virtual void execute(int&, int);
    virtual string getName();
};


SubCommand __subCommand;
string SubCommand::getName(){
    return "sub";
}
void SubCommand::execute(int &operand1, int operand2){
    operand1 -= operand2; 
}

/*  uncomment this to add mul command

			////////////////////// MULTIPLY command
			class MulCommand : public Command{
			    public:
			    virtual void execute(int&, int);
			    virtual string getName();
			};


			MulCommand __mulCommand;
			string MulCommand::getName(){
			    return "mul";
			}
			void MulCommand::execute(int &operand1, int operand2){
			    operand1 *= operand2; 
			}

*/