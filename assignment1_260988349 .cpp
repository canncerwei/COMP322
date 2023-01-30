#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool word_diff(std::string word1, std::string word2);
bool classical_file_diff(std::string file1, std::string file2);
bool enhanced_file_diff(std::string file1, std::string file2);
void list_mismatched_lines(std::string file1, std::string file2);
void list_mismatched_words(std::string file1, std::string file2);

bool word_diff(string word1, string word2){
    return (word1 == word2);
}

bool classical_file_diff(string file1, string file2){
    ifstream f1(file1);
    ifstream f2(file2);
    string word1, word2;

    while (f1 >> word1 && f2 >> word2) {
        if (!word_diff(word1, word2)) return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    /* code */

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

    return 0;

}
