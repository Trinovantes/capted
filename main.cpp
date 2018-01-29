#include <iostream>
#include <fstream>
#include "tests/json.hpp"
#include "capted/capted.h"

using namespace capted;
using std::cout;
using std::endl;
using std::string;
using json = nlohmann::json;

//------------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------------

int main(int argc, char const *argv[])
{
    std::ifstream testFile("tests/correctness_test_cases.json");
    json testCases;
    testFile >> testCases;

    StringCostModel costModel;
    AllPossibleMappings<StringNodeData> algorithm(&costModel);

    for (json test : testCases) {
        int id = test["testID"];
        float realDist = test["d"];
        string t1 = test["t1"];
        string t2 = test["t2"];

        BracketStringInputParser p1(t1);
        BracketStringInputParser p2(t2);

        Node<StringNodeData>* n1 = p1.getRoot();
        Node<StringNodeData>* n2 = p2.getRoot();

        cout << *n1 << endl;
        cout << *n2 << endl;

        float compDist = algorithm.computeEditDistance(n1, n2);
        cout << "realDist:" << realDist << " compDist:" << compDist << endl;
    }

    return 0;
}
