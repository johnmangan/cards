#ifndef COMMANDLINETEST_H_
#define COMMANDLINETEST_H_

#include <DescriptionInterface.h>

namespace cards {

class CommandLineTest
{
public:
    CommandLineTest( IDescription* iDesc );
    void printMenu();
    void handleInput( int& input );
private:
    IDescription* di;
};

}

#endif /*COMMANDLINETEST_H_*/
