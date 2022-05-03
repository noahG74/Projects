 #ifndef JARGON_H
#define JARGON_H
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

class Text
{
  private:
    string input; // from user
    int spaces; // Number of words
    vector<string> tokens; // words from user
    vector<vector<string>> words // words detected in disciplines
    {
        {},
        {},
        {},
        {}
    };
    int countCS = 0.0; //counter for CS jargons
    int countH = 0.0; //counter for History jargons
    int countE = 0.0; //counter for English jargons
    int countM = 0.0; //counter for Math jargons 

  public:

  // Default constructor:
    Text() 
    { input = " ";
      spaces = 0.0; }

  // Assign value to member data: 
    void setInput(string temp) 
        { input = temp; }

  // Returns size of vector of words from user
    int getTokensSize() const
    { return tokens.size(); }
  // Counts amount of spaces in string (amount of words = +1)
    void spaceCount(); //gets the total number of words
    void compareJargons(); 
    void txtAnatomy(); // Calculates and displays the percentages
    void tokenize(); 
    void wordHit(int index, string currentWord)
       {words[index].push_back(currentWord);}
    void displayWordHit(int index)
    {for (int i = 0; i < words[index].size(); i++)
         cout << words[index][i] << endl;}
};
#endif
