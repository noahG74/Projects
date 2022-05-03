#include "Jargon.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//used to make each word the user inputs into a variable, works essentially like a counter
void Text::tokenize()
{   
    int tokenStart = 0;
    int delim = input.find(' ');

    while (delim != string::npos)
    {
        string tok = input.substr(tokenStart, delim-  tokenStart);
        
        if(tok != " ") 
            tokens.push_back(tok);
        delim++;

        tokenStart = delim;

        delim = input.find(' ', delim);
    }
  
    if (delim == string::npos)
    {
        string tok = input.substr(tokenStart, (input.length()) -                       tokenStart); 
        tokens.push_back(tok);
    }
}
//used to compare the words the user inputs to text files made from us
void Text::compareJargons()
{
  ifstream myFile1, myFile2, myFile3, myFile4;
  string currentWord;

  //opening each file we made for 4 disciplines
  myFile1.open("CompSci.txt");
  myFile2.open("English.txt");
  myFile3.open("History.txt");
  myFile4.open("Math.txt");

  //vector fills up and counts how many times a word gets spotted as a jargon for computer science, also inputs the word into a vector to display later
  while (myFile1 >> currentWord)
    {
      for (int i = 0; i < tokens.size(); i++) 
      {
         if (tokens[i] == currentWord)
         {
           countCS++;
           wordHit(0, currentWord);
         }
            
      }
    }
  
  //vector fills up and counts how many times a word gets spotted as a jargon for english, also inputs the word into a vector to display later
  while(myFile2 >> currentWord)
    {
      for (int i = 0; i < tokens.size(); i++) 
      {
         if (tokens[i] == currentWord)
         {
           countE++;
           wordHit(1, currentWord);
         }
            
      }
    }

  //vector fills up and counts how many times a word gets spotted as a jargon for history, also inputs the word into a vector to display later
   while(myFile3 >> currentWord)
    {
      for (int i = 0; i < tokens.size(); i++) 
      {
         if (tokens[i] == currentWord)
         {
            countH++;
            wordHit(2, currentWord);
         }
      }
    }

  //vector fills up and counts how many times a word gets spotted as a jargon for math, also inputs the word into a vector to display later
  while(myFile4 >> currentWord)
    {
      for (int i = 0; i < tokens.size(); i++) 
      {
         if (tokens[i] == currentWord)
         {
           countM++;
           wordHit(3, currentWord);
         }
            
      }
    }
           
}

//displays how many times a word is hit and the percentage compared to how much text is input
void Text::txtAnatomy()
{
  double totalCount = countCS + countE + countH + countM;

  double percentage = ((countCS / totalCount) + (countE / 
                      totalCount) +  (countH / totalCount) + 
                      (countM / totalCount)) * 100;

  if (totalCount == 0)
    cout << "\nThere were no jargon detected in the text";
  else
  {
    cout << "\n===================Text Anatomy================\n";
    cout << setprecision(2) << fixed;
    cout << " | This text/file is " << (countCS / totalCount) * 
            100.0 << "% Computer Science.  |\n";
    
    cout << " | This text/file is " << (countE / totalCount) * 100.0         << "% English.          |\n";
  
    cout << " | This text/file is " << (countH / totalCount) * 100.0         << "% History.          |\n";
  
    cout << " | This text/file is " << (countM / totalCount) * 100.0         << "% Math.              |\n";
    cout << "===============================================\n";
    cout << "\nThe percentages you see are an average of all\n"; 
    cout << "the jargon detected in the text\n\n";

    cout << "\n===================Disciplines================\n";
    if (words[0].size() != 0)
    {
      cout << "Computer Science Jargon:\n";
      displayWordHit(0);
      cout << endl;
    }
    
    if (words[1].size() != 0)
    {
      cout << "English Jargon:\n";
      displayWordHit(1);
      cout << endl;
    }

    if (words[2].size() != 0)
    {
      cout << "History Jargon:\n";
      displayWordHit(2);
      cout << endl;
    }
    
    if (words[3].size() != 0)
    {
      cout << "Math Jargon:\n";
      displayWordHit(3);
      cout << endl;
    }
    cout << "==============================================\n";
    cout << "Note: if there are multiple of the same word across different disciplines, it is overlapping jargon.\n";
  }
}
  
void Text::spaceCount()
{
    double spaceCounter = 0.0;
    
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
          spaceCounter++;
    }

    spaces = spaceCounter + 1;
}