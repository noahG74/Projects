#include "Jargon.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int main() 
{
  char choice;

  do
  {
    cout << "\33[H\33[2J";
    string temp = " ";
    Text jargon;
  
    cout << "|***********************|\n";
    cout << "|  Bargain With Jargon  |\n";
    cout << "|                       |\n";
    cout << "|  By: Sperry Studios   |\n";
    cout << "|***********************|\n";
    cout << endl;
    cout << endl;
  
    cout << "Please enter your text:\n";
    getline(cin, temp);
  
    // Makes each letter in the user's input lowercase
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp[i] != tolower(temp[i]))
          temp[i] = tolower(temp[i]);
      
        if (ispunct(temp[i]))
          temp[i] = ' ';
    }  


    // Assigns the user's input to the input member variable:
    jargon.setInput(temp);

    // Counts spaces
    jargon.spaceCount();
  
    // Stores each word as one token to compare each token (word) to each jargon:
    jargon.tokenize();

    // Compares each word in the vector of user inputted words                                                                                                                                                                           ("tokens") to 
    // each word in our list of jargon from our 4 discipline files
    jargon.compareJargons();

    jargon.txtAnatomy();

    cout << "\nWould you like to enter another piece of text (Y/N)? ";
    cin >> choice;

    while (toupper(choice) != 'Y' && toupper(choice) != 'N')
      {
        cout << "Invalid option. Please try again: ";
        cin >> choice;
      }
    cin.ignore();
  } while (toupper(choice) == 'Y');

  cout << "\33[H\33[2J";
  cout << "\nThank you, bye bye!\n";
  
  return 0;
}