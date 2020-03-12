#include <iostream> // new comment added for makefile exercise
#include <string> //new comment added for git exercise
#include <vector>
#include "version.cpp"
using namespace std;

int main (int argc, char** argv) {
    vector<string> allInputLines; // vector that will store the input lines that are piped in from previous program execution output    
    string inputLine;

    // while loop to get input line value from pipe
    while (getline(cin, inputLine)) {
        // if to check if there is a inputLine value provided
        if (!inputLine.empty()) {
            // now push value into vector
            allInputLines.push_back(inputLine);
        }    
    }

    displayVersion();
    // check which option out of the three was given as argument for this program (i.e. -d, -f, -b)
    string optionArgument = argv[1];
    if (optionArgument == "-d") {
        cout << allInputLines[0] << endl;
    }
    else if (optionArgument == "-f") {
        cout << allInputLines[1] << endl;    
    }
    else if (optionArgument == "-b") {
        cout << allInputLines[2] << endl;    
    }
    else {
        // this else statement will catch any error case which is an invalid option given as an argument to this function
        cout << "An invalid option argument was given. Please try again." << endl;    
    }

    return 0;
}
