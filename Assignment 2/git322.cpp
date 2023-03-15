#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <ctime>

using namespace std;

// function prototypes
void add(string content);
void remove(int versionNumber);
void load(int versionNumber);
void print();
void compare(int versionNumber1, int versionNumber2);
void search(string keyword);
string readFile(string fileName);
size_t hash_it (string someString);


// Hold info about version of file, AKA a node of linkedlist
struct Version {
    int versionNumber;
    string content;
    size_t hashValue;
    struct Version *next;
    Version(string some_content){
        content = some_content;
        hashValue = hash_it(some_content);
        next = nullptr;
    }
};

// linked list struct definition
struct LinkedList {
    int size;
    Version *head;
    LinkedList(){
        head = NULL;
    }
};

// global variables
LinkedList versionsList;
bool fileModified;
int version_Number;



// Function to readFile and add content
string readFile(string fileName){
    ifstream myfile(fileName);
    stringstream buffer;
    buffer << myfile.rdbuf();
    myfile.close();
    return buffer.str();
}

// Function stolen from Assignment 1 to get hashvalue
size_t hash_it (string someString){
    return hash<string>{}(someString);
}

// adding a file version into linked list
void add(string content){
    // if adding initial version
    if (versionsList.head == NULL){
        version_Number = 1;
        Version *firstVersion = new Version(content);
        firstVersion->versionNumber = version_Number;
        versionsList.head = firstVersion;
        cout << "Your content has been added successfully." << endl << endl;
        return;
    }

    Version *lastVersion = versionsList.head;
    while (lastVersion->next != nullptr) {
        lastVersion = lastVersion->next;
    }
    if (lastVersion->hashValue == hash_it(content)) {
        cout << "git322 did not detect any change to your file and will not create a new version." << endl << endl;
        return;
    }
    
    version_Number++;
    Version *newVersion = new Version(content);
    newVersion->versionNumber=version_Number;
    lastVersion->next = newVersion;
    // delete newVersion;

    cout << "Your content has been added successfully." << endl << endl;
    fileModified = false;    
}

// print all available versions
void print(){
    cout << "Number of versions: " << version_Number << endl;
    Version *version = versionsList.head;

    while (version != nullptr){
       cout << "Version number: " << version->versionNumber << endl;
       cout << "Hash value: " << version->hashValue << endl;
       cout << "Content: " << version->content << endl << endl; 
       version = version->next;
    }
}

// HELPER: get the pointer to a desired version
Version* getVersion(int versionNumber){
    // Traverse the linked list to find the specified version
    Version* currentVersion = versionsList.head;
    while (currentVersion != nullptr && currentVersion->versionNumber != versionNumber) {
        currentVersion = currentVersion->next;
    }

    if (currentVersion == nullptr) {
        cout << "Error: version " << versionNumber << " not found." << endl;
    }

    return currentVersion;
}

void load(int versionNumber) {
    if (versionNumber < 1 || versionNumber > version_Number) {
        cout << "Please enter a valid version number. If you are not sure please press 'p' to list all valid version numbers." << endl;
        return;
    }

    // Traverse the linked list to find the specified version
    Version* currentVersion = getVersion(versionNumber);
    
    // Load the content of the specified version
    string content = currentVersion->content;

    // Overwrite the content of the current file with the loaded content
    ofstream myfile("file.txt");
    if (myfile.is_open()) {
        myfile << content;
        myfile.close();
        cout << "Version " << versionNumber << " loaded successfully. Please refresh your text editor to see the changes." << endl;
    } else {
        cout << "Error: could not open file.txt" << endl;
    }
}

void compare(int version1, int version2){
    Version* versionNumber1 = getVersion(version1);
    Version* versionNumber2 = getVersion(version2);

    return;
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

        switch (choice) {
            case 'a': {
                string content = readFile("file.txt");
                add(content);
                break;
            }
            case 'p': {
                print();
                break;
            }

            case 'e': {
                cout << "Exiting. Good bye!" << endl;
                return 0;
            }

            case 'l':{
                int version;
                cout << "Which version would you like to load?" << endl;
                cin >> version;
                load(version);
                break;
            }

            case 'c':{
                int version1;
                int version2;
                cout << "Please enter the number of the first version to compare:";
                cin >> version1;
                cout << "Please enter the number of the second version to compare:";
                cin >> version2;
                // void compare(version1, version2);
                break;
            }
            // case 'r': {
            //     if (versionsList.size == 0) {
            //         cout << "Error: there are no versions to remove" << endl;
            //         break;
            //     }
            //     int versionNumber;
            //     cout << "Which version would you like to remove?" << endl;
            //     cin >> versionNumber;
            //     if (versionNumber < 1 || versionNumber > versionsList.size) {
            //         cout << "Error: invalid version number" << endl;
            //         break;
            //     }
            // }
        }
    } 
}         
