// Noah Gonzales, Steven Nava, Donaven Smith

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
void phoneCheck(char);
int phoneCall(char);
void miniGame(char,int,char);
int main()
{
	// Clears the screen
	cout << "\33[H\33[2J";
	// Defining the variable
	string picture;
	ifstream inputFile;
	int SIZE = 6;
	char decicion[SIZE];
	int phone;
	// Shows the menu again if user choses "About Us"(Pt1)
	do
	{
			// Displays the menu
			cout << "------------- Welcome To -------------\n";
			cout << "        ""The Cheating Scandal\n";
			cout << endl;
			cout << "  1. Start Game           2. About Us\n";
			cout << "                 3. Exit\n";
			cout << "---------------------------------------"<< endl;
			cin >> decicion[0];
			
			// Validates the user input	
			while (decicion[0]!= '1' && decicion[0]!= '2' && decicion[0]!= '3')
			{
				cout << "Invalid choice, Please try again :)"<< endl;
				cin >> decicion[0];
			}

			// Sends the user to whatever option they chose
			switch(decicion[0])
			{
				case '1': 
					  // Allows the user to start the game over(Pt1)
					  do
					  {     
						// Start of the story
					    	  cout << endl; 
						  cout << "Your name is Tom Williams\n";
						  cout << "You are a college freshman in their first semester trying to handle the stress\n";
						  cout << "of college.";
						  cout << " but the relationship you are currently in seems to be having issues of their own!\n";
						  cout << "You are currently studying (like a good boy does) when you get a notification onyour phone.\n";
						  cout << "Would you like to check it? (Y/N)\n";
						  cin  >> decicion[1];

						// Validates the user input
						  while (decicion[1]!= 'y' && decicion[1]!= 'Y' && decicion[1]!= 'n' && decicion[1]!= 'N' )
						  {
						  	cout << "Invalid choice, Please try again :)"<< endl;
						  	cin >> decicion[1];
						  }
							
						// Goes to phoneCheck function
						  phoneCheck(decicion[1]);

						// Displays another story aspect	
						  cout << "You check your phone, and you see the text from her saying,\n";
						  cout << " \"Chill bro, she is busy right now\"" << endl;
						  cout << "Would you like to call her? (Y/N)\n";
						  cin  >> decicion[2];
						
						// Validates the user input
						  while (decicion[2]!= 'y' && decicion[2]!= 'Y' && decicion[2]!= 'n' && decicion[2]!= 'N' )
						  {
						  	cout << "Invalid choice, Please try again :)"<< endl;
						  	cin >> decicion[2];
						  }
						
						// Stores the return function(phoneCall) in phone
						  phone = phoneCall(decicion[2]);
						  
						// Displays how many times you tried to call or if you didn't even try
						  if(phone > 0)
							cout << "You tried calling " << phone << " time(s) and not once did she pick up\n\n";
						  else
							cout << "Seeing that text hit you heavily so you decided not to call\n\n";
						
						// Displays a bunch of the story
						cout << "You decided to buy the last plane ticket back home to see what's going on." << endl;
						cout << "You already told your parents you are coming home for the weekend, but" << endl;
						cout << "you didn't tell them why you were coming back." << endl;
						cout << "Whenever you landed you went straight to your parents house" << endl;
						cout << "to try and prepare for what you're going to do tomorrow." << endl; 
						cout << "The big day finally arrives, you start it off like you start off every morning," << endl;
						cout << "you text her good morning and make your protein shake and head to the gym." << endl;
						cout << "While you are at the gym you decide think about how to approah her," << endl;
						cout << "because you didn't tell her you were coming down." << endl;
						cout << "After the gym you head home and freshen up." << endl;
						cout << "You decide after a lot of thinking to just show up at her house, " << endl;
						cout << "but when you show up you see the one thing you thought you " << endl;
						cout << "wouldn't see... your best friends car.\n" << endl;
						
						// opening the file
						inputFile.open("picture2.txt", ios::in);
						if(inputFile)
						{
							getline(inputFile,picture);
							while(inputFile)
							{
								// printing the file
								cout << picture << endl;
								getline(inputFile,picture);
							}
							//closing the file
							inputFile.close();
						}
						else
						cout << "Error! Cannot open file." << endl;
						
						cout << endl << endl;
						// Displaying the option to call either your friend or your girlfriend
						cout << "Would you like to call her(1) or him(2)? (1/2)" << endl;
						cin  >> decicion[3];
		
						// Validates the user input
						while (decicion[3]!= '1' && decicion[3]!= '2')
						{
							cout << "Invalid decision, Please try again :).\n";
							cin >> decicion[3];
						}

						// Sending the user to the girlfriends story line					
						if (decicion[3]== '1')
						{
							// Girlfriends story line
							cout << "You decided you call your girlfriend and let her know that you were in town\n";
							cout << "and were on your way with some flowers\n";
							cout << "but in reality you are waiting outside her house waiting for them to come out!\n";
							cout << "You tell her you love her and end the call." << endl;
							cout << "You have just approached the door right when they're about to open it." << endl;
							cout << "When they open the door, y'all make eye contact and they've act like they have " << endl;
							cout << "seen a ghost. Without a second thought you ask them what they're doing, " << endl;
							cout << "but you see a fresh hickey on her neck and put two and two together." << endl;

							// Displaying the Big Decision
							cout << "Would you like to break up with her? (Y/N)" << endl;
							cin  >> decicion[4];

							// Validates the user input
							while (decicion[4] != 'y' && decicion[4] != 'Y' && decicion[4] != 'n' && decicion[4] != 'N')
							{
								cout << "Invalid decision, Please try again :).\n";
								cin >> decicion[4];
							}

							// Sends you to your outcome based on the Big Decision
							if (decicion[4] == 'y' || decicion[4] == 'Y')
							{
								// Good Ending
								cout << "You decide to break up with her and focus on yourself and your future." << endl;
								cout << "Because of this hard decision you grow as a person through college, " << endl;
								cout << "and successfully graduated and got your dream job." << endl;
								cout << "REMINDER: ALWAYS PUT YOURSELF FIRST!" << endl;
	
							}
							else 
							{
								// Bad Ending
								cout << "You decided to forgive and forget and stay with her, " << endl;
								cout << "while the bond you and your best friend has broke." << endl;
								cout << "Due to you not breaking up with her leads to your downfall, " << endl;
								cout << "you start losing friends and dropped out of college, " << endl;
								cout << "and started working at the gas station for the rest of your life." << endl;
								cout << "You never truly got over her so you never got into another relationship." << endl;
								cout << "REMINDER: TRUST NO ONE, ESPECIALLY THOSE CLOSEST TO YOU!" << endl;
							}
						}

						// Sending the user to the friends story line					
						else if (decicion[3]== '2')
						{	
							// Calls the mini game
							miniGame(decicion[1],phone,decicion[3]);
							// Friends story line
							cout << "You decided to call your best friend to see what he was doing" << endl;
							cout << "and to see if he wanted to hang out." << endl;
							cout << "He says yes and tells you to meet him at whatburger for lunch and hangs up" << endl;
							cout << "You stay in the car but across the street to see what happens.\n";
							cout << "What you see is them kiss while he is putting his belt back on and she is" << endl;
							cout << "wrapped up in a blanket. So you realized what happened and confronted them." << endl;
					
							// Displaying the Big Decision
							cout << "Would you like to break up with her? (Y/N)" << endl;
							cin  >> decicion[4];

							// Validates the user input
							while (decicion[4]!= 'y' && decicion[4]!= 'Y' && decicion[4]!= 'n' && decicion[4] != 'N')
							{
								cout << "Invalid decision, Please try again :).\n";
								cin >> decicion[4];
							}

							// Sends you to your outcome based on the Big Decision
							if (decicion[4]== 'y' || decicion[4]== 'Y')
							{
								// Good ending
								cout << "You decided to break up with her after a long time of thinking,\n";
								cout << "but you had to know why he did it and ask him." << endl;
								cout << "He then tells you that he wanted her more than you, " << endl;
								cout << "and decided to take action.\n";
								cout << "Even though this decision was hard you grew as a person through college, " << endl;
								cout << "and successfully graduated and got your dream job." << endl;
								cout << "REMINDER: ALWAYS PUT YOURSELF FIRST!" << endl;								
	
							}
							else if (decicion[4]== 'n' || decicion[4]== 'N')

							{
								// Bad ending
								cout << "You decided to forgive and forget and stay with her, " << endl;
								cout << "while the bond you and your best friend has broke." << endl;
								cout << "Due to you not breaking up with her leads to your downfall, " << endl;
								cout << "you start losing friends and dropped out of college, " << endl;
								cout << "and started working at the gas station for the rest of your life." << endl;
								cout << "You never truly got over her so you never got into another relationship." << endl;
								cout << "REMINDER: TRUST NO ONE, ESPECIALLY THOSE CLOSEST TO YOU!" << endl;								
	
							}
						}
						// Asking the user if they want to play again
						cout << "Do you wish to play again?(Y/N)\n";
						cin >> decicion[5];

						// Validates the user input
						while (decicion[5]!= 'y' && decicion[5]!= 'Y' && decicion[5]!= 'n' && decicion[5]!= 'N')
						{
							cout << "Invalid decision, Please try again :).\n";
							cin >> decicion[5];
						}
	
						// Decides what do to based on the users decision
						if (decicion[5]== 'y'|| decicion[5]== 'Y')
						cout << "\33[H\33[2J";
						else if (decicion[5]== 'n'|| decicion[5]== 'N')
						cout << "Thank You For Playing :).\n";

						// Allows the user to start the game over(Pt2)
						}while (decicion[5]== 'y'|| decicion[5]== 'Y');  
				break;
				
				case '2': // Displays our jobs and a fun thing
					  cout << "Lead Coder - Noah Gonzales, In a relationship.\n";
					  cout << "Story Teller - Donaven Smith, With me.\n";
					  cout << "Presenter - Steven Nava, idk, I just go to school here.\n\n";
				break;
				case '3': // Displays a end screen 
					  cout << "Bye Bye :)\n"; 
			}

		// Shows the menu again if user choses "About Us"(Pt2)
		}while (decicion[0]== '2');
}

// Displays all that is needed for the phone checking part
void phoneCheck(char check)
{	
	// Only triggers if the user choses no to checking their phone the first time.
	if (check == 'n' || check =='N')
	{	
		// Allows the user to ignore their phone a total of 3 times
		for (int i = 0; i < 2; i++)
		{
			//Displays that the user didn't want to check their phone
			cout << "You decide to ignore it and keep on studying.\n";
			cout << "Your phone goes off again, would you like to check it?\n";
			cin  >> check;

			// Validates the user input
			while (check != 'y' && check != 'Y' && check != 'n' && check != 'N' )
			{
				cout << "Invalid choice, Please try again :)"<< endl;
  				cin >> check;
			}

			// Displays if the number maxes out
			if (i == 1)
			{
				cout <<"It's getting annoying so you decide to check it and see that see that your\n"; 
				cout << " best friend is trying to reach you.\n";
				cout << "He has been trying to tell you that your girlfriend has been acting different\n";
			}
			// Displays if the user wants to check their phone
			else if (check == 'y' || check == 'Y')
			{
				cout << "You open your phone to see your friend has been trying to reach you.\n";
				cout << "He is letting you know that the girl you have been dating since high school has been acting very different lately.\n";
				i = 4;
			}					 
		}
	}
	// Displays if the user wants to check their phone
	else if (check == 'y' || check == 'Y')
	{
		cout << "You open your phone to see your friend has been trying to reach you.\n";
		cout << "He is letting you know that the girl you have been dating since high school has been acting very different lately.\n";
	}
}

// Counts how many times the user tried to call
int phoneCall(char call)
{
	// Initializing count at 0
	int count = 0;
	
	// Keeps going as long as the user tries to call
	while(call == 'y' || call == 'Y')
	{
		count++;
		cout << "You got sent to voicemail\n";
		cout << "Would you like to try again?\n";
		cin >> call;
		
		// Validates the user input
		while (call != 'y' && call != 'Y' && call != 'n' && call != 'N' )
		{
			cout << "Invalid choice, Please try again :)"<< endl;
			cin >> call;
		}
	}
	
	// returns the number of times the user tried to call
	return count;
}

// Activates the Toothpick game
void miniGame(char LF,int game,char BS) 
{
	char choice;

	if(LF == 'n' || LF == 'N' && game == 3 && BS == '2')
	{
		do
		{
			cout << "\33[H\33[2J";
			cout << "____________________________________\n";
			cout << " |				  |\n";
			cout << " | Welcome to the ToothPick Game  |\n";
			cout << " | 				  |\n";
			cout << " | Will you be the one?	          |\n";
			cout << " | or will you fail like the rest?|\n";
			cout << " |				  |\n";
			cout << "------------------------------------\n";
			cout << "The rules are simple:\n";
			cout << "1. There are 21 toothpicks to chose from.\n";
			cout << "2. You must either pick 1, 2, or 3\n";
			cout << "3. To win, you can't be the person who picks last.\n";
			cout << "4. Good luck, I hope you can beat me.\n" << endl;
			for (int i = 21; i > 1;)
			{
				char pick;
				cout << "There are " << i << " toothpicks remaining.\n";
				cout << "How many do you wish to pick up?\n";
				cin >> pick;
				while (pick != '1' && pick != '2' && pick != '3')
				{
					cout << "Don't forget the rules now. Try again.\n";
					cin >> pick;
				}
				if (pick == '1')
				{
					cout << "Good choice. I will pick up 3\n";
					i -= 4;
				}		
				else if (pick == '2')
				{
					cout << "Good choice. I will pick up 2\n";
					i -= 4;
				}
				else if (pick == '3')
				{
					cout << "Good choice. I will pick up 1\n";
					i -= 4;
				}
				if (i == 1)
				{
					cout << "Only one remains... and it seems it's your turn.\n";
					cout << "Looks like you couldn't defeat me... Such a shame.\n";
				}
			}
			
			cout << "Would you like to challenge again?(Y/N)\n";
			cin >> choice;
		 	while (choice!= 'y' && choice!= 'Y' && choice!= 'n' && choice!= 'N' )
			 {
				cout << "Invalid choice, Please try again"<< endl;
				cin >> choice;
			 }
		}while(choice == 'y' || choice =='Y');
		cout << "\33[H\33[2J";
		cout << "Now pick up where you left off\n" << endl;
	}
}
			
	
					

				
			

		

	


	




