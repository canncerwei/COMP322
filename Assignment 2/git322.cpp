#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <ctime>

using namespace std;

// version struct definition
struct Version {
    int versionNumber;
    string content;
    time_t timestamp;
    Version *next;
};

// linked list struct definition
struct LinkedList {
    int size;
    Version *head;
};

// global variables
LinkedList versionsList;
bool fileModified;

// function prototypes
void add(string content);
void removeVersion(int versionNumber);
void load(int versionNumber);
void print();
void compare(int versionNumber1, int versionNumber2);
void search(string keyword);

void add(string content){
    
}
// main function
int main() {
    // initialization
    versionsList.size = 0;
    versionsList.head = nullptr;
    fileModified = false;

    cout << "Welcome to the Comp322 file versioning system!" << endl;

    char choice;
    while (true) {
        cout << "To add the content of your file to version control press 'a'" << endl;
        cout << "To remove a version press 'r'" << endl;
        cout << "To load a version press 'l'" << endl;
        cout << "To print to the screen the detailed list of all versions press 'p'" << endl;
        cout << "To compare any 2 versions press 'c'" << endl;
        cout << "To search versions for a keyword press 's'" << endl;
        cout << "To exit press 'e'" << endl;
        cin >> choice;

        // switch (choice) {
        //     case 'a': {
        //         string content = readFile("file.txt");
        //         if (versionsList.size > 0) {
        //             Version *lastVersion = versionsList.head;
        //             while (lastVersion->next != nullptr) {
        //                 lastVersion = lastVersion->next;
        //             }
        //             if (lastVersion->content == content) {
        //                 cout << "git322 did not detect any change to your file and will not create a new version." << endl;
        //                 break;
        //             }
        //         }
        //         add(content);
        //         cout << "Your content has been added successfully." << endl;
        //         fileModified = false;
        //         break;
        //     }
        //     case 'r': {
        //         if (versionsList.size == 0) {
        //             cout << "Error: there are no versions to remove" << endl;
        //             break;
        //         }
        //         int versionNumber;
        //         cout << "Which version would you like to remove?" << endl;
        //         cin >> versionNumber;
        //         if (versionNumber < 1 || versionNumber > versionsList.size) {
        //             cout << "Error: invalid version number" << endl;
        //             break;
        //         }
        //     }
        // }
    } 
}         
