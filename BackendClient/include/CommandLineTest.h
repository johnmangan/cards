#ifndef COMMANDLINETEST_H_
#define COMMANDLINETEST_H_

#include <DescriptionInterface.h>

#include <string>
#include <vector>

namespace cards {

class CommandLineTest
{
public:
    CommandLineTest( IDescription* iDesc );
    void printMenu();
    void handleInput( unsigned int& input );
private:
    IDescription* di;
    std::vector< std::string > options;
};

}

#endif /*COMMANDLINETEST_H_*/
