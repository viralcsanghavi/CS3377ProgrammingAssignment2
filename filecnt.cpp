#include <iostream> // new comment added for makefile exercise
#include <string> //new comment added for git exercise
#include <filesystem>
#include "version.cpp"
using namespace std;
namespace fs = std::filesystem;

int main (int argc, char** argv) {
    long directoryCounter = 0;
    long plainFilesCounter = 0;
    unsigned long long bytesAmount = 0;

    // This will iterate through the directories recursively!
    for (auto& fileObject : fs::recursive_directory_iterator(argv[1], fs::directory_options::skip_permission_denied)) { 
        // try block for errors
        try {
            if (fileObject.is_directory()) {
                // checks if file is a directory...
                ++directoryCounter;  
                // will add to counter          
            }
            else {
                // else if it's not a directory, then it a plain/regular file
                ++plainFilesCounter;
                bytesAmount += fileObject.file_size();
                // will add to counter and add to bytesAmount based on size of file
            }
        }
        catch (const exception &e) {
            // catch block will catch the errors ignoring permission errors
            continue;
        }   
    }
    cout << "The total number of directories in directory " << argv[1] << " is: " << directoryCounter << "." << endl << endl;
    cout << "The total number of files in directory " << argv[1] << " is: " << plainFilesCounter << "." << endl << endl;
    cout << "The total number of bytes occupied by all files in directory " << argv[1] << " is: " << bytesAmount << "." << endl << endl;

    return 0;
}
