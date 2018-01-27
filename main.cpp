#include <iostream>
#include "stringnode.h"

using namespace capted;
using std::cout;
using std::endl;

//------------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------------

int main(int argc, char const *argv[])
{
    std::string s = "{AA{B{X}{Y}{F}}{C}}";
    BracketStringInputParser p(s);
    cout << *p.getRoot() << endl;

    return 0;
}
