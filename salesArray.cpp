//********************************************************************
//Name: Noah Gonzales
//Class: COSC 1435 Fall-21
//Instructor: Marwa Hassan
//Assignment 9 Problem 1
//Date:11/29/2021
//Program description: This program displays the highest and lowest sales of each month, the ones above or equal to 7500, 
//		       and the average of all the months 
//*********************************************************************

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;
double mainAverage(int [], int);
void displayAverages(int [], int);
void highestSale(int [], int);
void lowestSale(int [], int);
int greaterThan(int [], int);

const string MONTHS[12] = {"January", "February", "March", "April", "May",
 			   "June", "July", "August", "September",
			   "October", "November", "December"};

const int NUMDAYS[12] = {31 ,28 ,31 ,30,31, 30, 31, 31, 30, 31, 30, 31};

int AVG[12];

int main()
{
	const int SIZE = 365;
	int sales[SIZE];
	double avg;
	int size = 12;
	int num;

	ifstream inFile;
	// opens the file
    	inFile.open("sales.dat");

	ofstream resultFile;

	// displayed if the file fails to open
   	if (inFile.fail())
	{
        	cout << "Error opening file" << endl;
        	exit(1);
    	}

   	if (inFile.is_open())
	{
        	for (int i = 0; i < 365; i++)
		{
        	    inFile >> sales[i];
        	}
    	}

   // closes the file
    inFile.close();

	displayAverages(sales, SIZE) << endl << endl;

	avg = mainAverage(AVG, size);

	cout << "The average of all the months average sales was: " << avg << endl << endl;
	
	highestSale(AVG, size) << endl << endl;
	lowestSale(AVG, size) << endl << endl;
 	num = greaterThan(AVG, size);
	cout << "The number of months that had an average equal to or higher than 7500 was: " << num << endl << endl;

}

void displayAverages(int sales[], int SIZE)
{
	int months[12][31];
	int month_sales[12];
	int month_count[12];

	 for(int i = 0; i < 12; i++)
    {
        // if i = 0,2,4,6,7,9,11 then 31 days
        // if i = 1,3,5,8,10 then 30 days
        // if i = 2 then 28 days

        if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
	{
	// for months that have 31 days
            month_count[i] = 31;
            // sum of the sales for each month
            for(int j = 0; j < 31; j++)
	  {
            months[i][j] = sales[i*31 + j];
            month_sales[i] += months[i][j];
          }
        }
	// for months that have 30 days
        else if (i == 1 || i == 3 || i == 5 || i == 8 || i == 10)
	{
            month_count[i] = 30;

            // sum of the sales for each month
            for(int j = 0; j < 30; j++)
	    {
                months[i][j] = sales[i*30 + j];
                month_sales[i] += months[i][j];
            }

        }
	// for the month febuary
        else if (i == 2){
            month_count[i] = 28;
            // sum of the sales for each month
            for(int j = 0; j < 28; j++)
	    {
                months[i][j] = sales[i*28 + j];
                month_sales[i] += months[i][j];
            }
        }

    } 
   

	for(int i = 0; i < 12; i++)
	{
		AVG[i] =  month_sales[i]/month_count[i];
	}	
	
	
	for(int i = 0; i < 12; i++)
	cout << "The average sales for " << MONTHS[i] << ": " << AVG[i] << endl;

}

double mainAverages(int AVG[], int size)
{
	int sum = 0;
	double avg = 0;

	for(int i < 0; i < size; i ++)
	sum += AVG[i];
	
	avg = sum/12.0;
	
	return avg;
}

void highestSale(int AVG[], int size)
{
	int highest = AVG[0];
	int count = 0;
	for(int i = 1; i < size; i++)
	{
		if (highest < AVG[i])
		{
			highest = AVG[i];
			count = i;
		}
		
	}

	cout << "The month with the highest sale average is " << MONTHS[count] << " with the sale average of " << highest << endl;
}
void lowestSale(int AVG[], int size)
{
	int lowest = AVG[0];
	int count = 0;
	for(int i = 1; i < size; i++)
	{
		if (lowest > AVG[i])
		{
			lowest = AVG[i];
			count = i;
		}
		
	}

	cout << "The month with the highest sale average is " << MONTHS[count] << " with the sale average of " << lowest << endl;
}

int greaterThan(int AVG[], int size)
{
	int count = 0;

	for(int i = 0; i < size; i++)
	{
		if(AVG[i] > 7500 || AVG[i] == 7500)
		count++;
	}
	
	return count;
}




