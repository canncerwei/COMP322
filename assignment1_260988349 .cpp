#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/* -------------------------- Function Declaration -------------------------- */
bool word_diff(std::string word1, std::string word2);
bool classical_file_diff(std::string file1, std::string file2);
size_t hash_it (std::string someString);
bool enhanced_file_diff(std::string file1, std::string file2);
void list_mismatched_lines(std::string file1, std::string file2);
void list_mismatched_words(std::string file1, std::string file2);
void helper_mismatched_lines(ifstream& f1, ifstream& f2, string file1, string file2);
void helper_mismatched_words(ifstream& f1, ifstream& f2, string file1, string file2);
bool hashed_word_diff(string word1, string word2);
/* -------------------------------------------------------------------------- */

/* ----------------------------------- Q1 ----------------------------------- */
bool word_diff(string word1, string word2){
    return (word1 == word2);
}

/* ----------------------------------- Q2 ----------------------------------- */
bool classical_file_diff(string file1, string file2){
    // open file
    ifstream f1(file1);
    ifstream f2(file2);

    string word1;
    string word2;

    // checking line by line
    while (f1 >> word1 && f2 >> word2) {
        if (!word_diff(word1, word2)) return false;
    }

    return true;
}

/* ----------------------------------- Q3 ----------------------------------- */
size_t hash_it (string someString){
    return hash<string>{}(someString);
}

/* ----------------------------------- Q4 ----------------------------------- */

// Helper: word diff using hashing
bool hashed_word_diff(string word1, string word2){
    size_t hashed1 = hash_it(word1);
    size_t hashed2 = hash_it(word2);

    return (hashed1 == hashed2);
}

bool enhanced_file_diff(string file1, string file2){
    // open file
    ifstream f1(file1);
    ifstream f2(file2);

    string word1;
    string word2;

    // check line by line using hashing
    while (f1 >> word1 && f2 >> word2) {
        if (!hashed_word_diff(word1,word2)) return false;
    }

    return true;
}

 /* --------------- Q5  --------------- */

//  Recursive Helper
void helper_mismatched_lines(ifstream &f1, ifstream &f2, string file1, string file2){
    string line1;
    string line2;

    // Parsing filename to proper format
    string filename1 = file1.substr(file1.find_last_of("/\\") + 1);
    string filename2 = file2.substr(file2.find_last_of("/\\") + 1);
    
    // checking line by line 
    //Need to add both order for the line disparity edge case, must getline() the non empty file
    if((getline(f1,line1) && getline(f2,line2)) || (getline(f2,line2)&& getline(f1,line1)) ){


        if(!hashed_word_diff(line1,line2)){
            cout << filename1 << ": " << line1 << endl;
            cout << filename2 << ": " << line2 << endl;
        }

        helper_mismatched_lines(f1,f2,file1,file2);
        
    } //LINE DISPARITY EDGE CASE:
    else if (!line1.empty() || !line2.empty()) {
        if (!line1.empty()) {
            
            cout << filename1 << ": " << line1 << endl;
            cout << filename2 << ": " << endl;
            helper_mismatched_lines(f1,f2,file1,file2);
        } else if (!line2.empty()) {
            
            cout << filename1 << ": " << endl;
            cout << filename2 << ": " << line2 << endl;
            helper_mismatched_lines(f1,f2,file1,file2);
        }
    }

}


void list_mismatched_lines(string file1, string file2){

    //end program if both file same
    if (enhanced_file_diff(file1,file2)) return;

    ifstream f1(file1);
    ifstream f2(file2);
    
    // call recusive helper
    helper_mismatched_lines(f1,f2,file1,file2);
    
}


/* ----------------------------------- Q6 ----------------------------------- */

//  Recursive Helper
void helper_mismatched_words(ifstream& f1, ifstream& f2, int linenum, string file1, string file2){
    string line1,line2;
    
    string word1,word2;

    // Parsing filename to proper format
    string filename1 = file1.substr(file1.find_last_of("/\\") + 1);
    string filename2 = file2.substr(file2.find_last_of("/\\") + 1);
    
    // checking line by line, and check for empty line for edge case
    if((getline(f1,line1) && getline(f2,line2)) || (getline(f2,line2)&& getline(f1,line1))){

        istringstream iss1(line1), iss2(line2);
        while (iss1 >> word1 && iss2 >> word2){
            if (!hashed_word_diff(word1,word2)){
                cout << filename1 << ": " << word1 << " (line " << linenum << ")" << endl;
                cout << filename2 << ": " << word2 << " (line " << linenum << ")" << endl;
            }  
        }

        helper_mismatched_words(f1,f2,linenum+1,file1,file2);
        
    }
    // edge case, line disparity
    else if (!line1.empty() || !line2.empty()){
        if (!line1.empty()) {
            istringstream iss1(line1);
            while (iss1 >> word1){
                cout << filename1 << ": " << word1 << " (line " << linenum << ")" << endl;
                cout << filename2 << ": " << "''" << " (line " << linenum << ")" << endl;
            }

            helper_mismatched_words(f1,f2,linenum+1,file1,file2);
        } else if (!line2.empty()) {
            istringstream iss2(line2);
            while (iss2 >> word2){
                cout << filename1 << ": " << "''" << " (line " << linenum << ")" << endl;
                cout << filename2 << ": " << word2 << " (line " << linenum << ")" << endl;
            }
            helper_mismatched_words(f1,f2,linenum+1,file1,file2);
        }
    }

}
 void list_mismatched_words(std::string file1, std::string file2){
    // open file
    ifstream f1(file1);
    ifstream f2(file2);

    // call helper
    helper_mismatched_words(f1,f2,1,file1,file2);
 }   


/* -------------------------------------------------------------------------- */
/*                                    MAIN                                    */
/* -------------------------------------------------------------------------- */
int main(int argc, char const *argv[])
{

    
    // Given main function, but contains a lot of errors, so I have commented it out
    // // Q1
    // std::string str1 = "Hello World";
    // std::string str2 = "hEllO World";
    // std::string str3 = "World";
    // std::string str4 = "Hello World";
    // bool result = word_diff(str1, str2); // False
    // result = word_diff(str1, str3); // False
    // result = word_diff(str1, str4); // True
    // // Q2
    // std::string file1 = "./txt_folder/file1.txt";
    // std::string file2 = "./txt_folder/file2.txt";
    // result = classical_file_diff(file1, file2); // False
    // // Q3
    // std::string mystr = "I love this assignment";
    // std::size_t h1 = hash_it (mystr);
    // std::cout << h1 << std::endl;
    // // Q4
    // result = enhanced_file_diff(file1, file2); // False
    // // Q5
    // list_mismatched_lines(file1, file2); // This should print to the screen the mismatched lines
    // // Q6
    // list_mismatched_words(file1, file2); // This should print to the screen the mismatched words 

    //CUSTOM MAIN FUNCTION
    
    // Q1
    std::string str1 = "Hello World";
    std::string str2 = "hEllO World";
    std::string str3 = "World";
    std::string str4 = "Hello World";
    bool result1 = word_diff(str1, str4); // true
    bool result2 = word_diff(str1, str2); // false
    std::cout << "-----------Testing Q1-----------:" << std::endl;
    std::cout << std::boolalpha << "true? " << result1 << std::endl;
    std::cout << std::boolalpha << "false? " << result2 << std::endl;

    // Q2
    std::string file1 = "./txt_folder/file1.txt";
    std::string file2 = "./txt_folder/file2.txt";
    std::string file3 = "./txt_folder/file1_copy.txt";
    bool result3 = classical_file_diff(file1, file2); //false
    bool result4 = classical_file_diff(file1, file3);   //true
    std::cout << "-----------Testing Q2-----------:" << std::endl;
    std::cout << std::boolalpha << "false? " << result3 << std::endl;
    std::cout << std::boolalpha << "true? " << result4 << std::endl;

    // Q3
    std::cout << "-----------Testing Q3-----------:" << std::endl;
    std::string mystr = "I love this assignment";
    string mystr2 = "I love this assignment";
    std::size_t h1 = std::hash<std::string>{}(mystr);
    std::cout << h1 << std::endl;

    std::size_t h2 = hash_it (mystr2);
    std::cout << h2 << std::endl;
    std::cout << h2-h1 << std::endl;
    

    // Q4
    std::cout << "-----------Testing Q4-----------:" << std::endl;
    bool result = enhanced_file_diff(file1, file2); // False
    std::cout << result << std::endl;
    result = enhanced_file_diff(file1, file3); // True
    std::cout << result << std::endl;

    // Q5
    std::cout << "-----------Testing Q5-----------:" << std::endl;
    list_mismatched_lines(file1, file2);
    
    // Q6
    std::cout << "-----------Testing Q6-----------:" << std::endl;
    list_mismatched_words(file1, file2);
}
