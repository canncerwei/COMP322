#include <iostream>

bool word_diff(std::string word1, std::string word2);
bool classical_file_diff(std::string file1, std::string file2);
bool enhanced_file_diff(std::string file1, std::string file2);
void list_mismatched_lines(std::string file1, std::string file2);
void list_mismatched_words(std::string file1, std::string file2);

bool word_diff(std::string word1, std::string word2){
    return (word1.compare(word2)==0);
}

bool classical_file_diff(std::string file1, std::string file2){
    
    return false;
}
int main(int argc, char const *argv[])
{
    /* code */

    std::string str1 = "Hello World";
    std::string str2 = "hEllO World";
    std::string str3 = "World";
    std::string str4 = "Hello World";
    bool result = word_diff(str1, str4); // true

    std::cout << std::boolalpha << result << std::endl;
    

}
