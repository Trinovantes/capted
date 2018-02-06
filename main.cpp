#include <iostream>
#include <iomanip>
#include <fstream>
#include "includes/json.hpp"
#include "capted/capted.h"

using namespace capted;
using std::cout;
using std::endl;
using std::string;
using json = nlohmann::json;

//------------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------------

int main(int argc, char const *argv[]) {
    std::ifstream testFile("./tests/correctness_test_cases.json");
    json testCases;
    testFile >> testCases;

    StringCostModel costModel;
    AllPossibleMappings<StringNodeData> algorithm(&costModel);

    std::vector<int> testsToRun = {};
    std::vector<int> testsToSkip = {64, 71};

    for (json test : testCases) {
        int id = test["testID"];
        float realDist = test["d"];
        string t1 = test["t1"];
        string t2 = test["t2"];

        if (std::find(testsToSkip.begin(), testsToSkip.end(), id) != testsToSkip.end()) {
            // Skip slow tests
            continue;
        }

        if (testsToRun.size() > 0 && std::find(testsToRun.begin(), testsToRun.end(), id) == testsToRun.end()) {
            // Run specific tests?
            continue;
        }

        BracketStringInputParser p1(t1);
        BracketStringInputParser p2(t2);
        Node<StringNodeData>* n1 = p1.getRoot();
        Node<StringNodeData>* n2 = p2.getRoot();

        float compDist = algorithm.computeEditDistance(n1, n2);
        cout << std::setw(3) << id << " " << (realDist == compDist ? "pass" : "FAIL") << endl;
    }

    return 0;
}
