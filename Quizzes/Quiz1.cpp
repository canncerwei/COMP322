#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int* double_the_size(int arr[], int size){
    int* doubled = new int[2*size];
    for (int i = 0 ; i < (2*size); i++){
        if (i< size) doubled[i] = arr[i];
        else doubled[i] = 0;
    } 

    return doubled;
}

int main()
{
    int randomNumber = 3; //getRandomNumber();
    cout << "Enter your guess:";
    int guessedNumber;
    cin >> guessedNumber;
    while (guessedNumber != randomNumber){
        cout<< "Incorrect Number!" << endl;
        if (guessedNumber > randomNumber){
            cout << "Hint: Input a number SMALLER than previous guess" << endl;
        }else {
            cout << "Hint: Input a number BIGGER than previous guess" << endl;
        }
        cout << "Enter your guess:";
        cin >> guessedNumber;
    }

    cout << "You have guessed the correct number!";

}