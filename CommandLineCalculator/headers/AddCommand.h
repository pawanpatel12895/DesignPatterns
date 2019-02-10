#ifndef H_ADDCOMMAND
#define H_ADDCOMMAND

#include <string>
#include "Command.h"
using namespace std;

class AddCommand : public Command{
    public:
    AddCommand();
    virtual ~AddCommand();

    // implement abstract virtual functions of superclass
    virtual void execute(int&, int);
    virtual string getName();
};

#endif