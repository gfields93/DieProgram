#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include <stdlib.h>
#include <sstream>
#include "aDie.h"	//contains die class
#include "aHistogram.h"	//contains histogram class

int main(){
	const int ROLL_NUM = 12000;	//# of rolls
	int seedVal;	//value that seeds generator
	char answer;	//toggle that decide what seeds generator
	char tryAgain = '\0';	//toggle that runs whole experiment
	char maxLength[256];	//value that determines length of line
	bool exitToken = false;
	int dieFaces;
	aDie *dice = NULL;
	aHistogram *graph = NULL;
	
	while (tryAgain != 'q'){	//allows user to run program multiple times

		std::cout << "Do you wish the seed the number generator: Y or N.\n=>"; //seed prompt
		std::cin.get(answer);

		while(!exitToken){
			switch (answer){
			case 'Y':	//y cases allows user to seed generator
			case 'y':
				std::cout << "Please enter seed: " << std::endl;
				std::cin >> seedVal;
				srand(seedVal);
				exitToken = true;
				break;

			case 'N':	//n casses seeds generator with time function
			case'n':
				std::cout << "Using default value." << std::endl;
				srand(time(NULL));
				exitToken = true;
				break;

			default:
				std::cout << "Sorry, Invalid input. Please try again.\n=>";
				std::cin.ignore(INT_MAX,'\n');
				std::cin.get(answer);
			}
		}
		std::cout << "Enter the max length of line:\n=>"; //prompt for max length of line
		std::cin >> std::ws;
		std::cin.getline(maxLength,256,'\n');

		std::cout << "Do you want to enter the size of the die. \n=>";
		std::cin >> std::ws;
		std::cin.get(answer);
		exitToken = false;
		while(!exitToken){
			switch (answer){
			case 'Y':	//y cases allows user to number generator
			case 'y':
				std::cout << "Please enter number\n=> ";
				std::cin.ignore(INT_MAX,'\n');
				std::cin >> dieFaces;
				dice = new aDie(dieFaces);
				graph = new aHistogram(dieFaces);
				exitToken = true;
				break;

			case 'N':	
			case'n':
				std::cout << "Using default value." << std::endl;
				dice = new aDie();
				graph = new aHistogram();
				exitToken = true;
				break;

			default:
				std::cout << "Sorry, Invalid input. Please try again.\n=>";
				std::cin.ignore(INT_MAX,'\n');
				std::cin.get(answer);
			}
		}

		graph->clear();	//makes sure the histogram object is empty

		for (int i = 0; i < ROLL_NUM; ++i){	//rolls the dice and updates the histogram
			graph->update(dice->roll());
		}

		graph->display(atoi(maxLength));	//displayes histogram
		std::cout << std::endl;
		std::cout << "Do you wish to run experiment again? (Press q to quit)\n"; //prompt to run experiment agin
		std::cout << "Press any other key to continue.\n=>";
		std::cin >> tryAgain;
		std::cin.ignore(INT_MAX,'\n');
		delete dice;
		delete graph;
	}
	return 0;
}
