#include <iostream>
#include "aDie.h"	//contains aDie declarations

aDie::aDie() : dieFaces(6){// contructor confirming object has been made
	std::cout << "The default die has been created." << std::endl;
	return;
}

aDie::aDie(int n) : dieFaces(n){
	std::cout << "A die with " << n <<" has been created." << std::endl;
	return;
}
aDie::~aDie(){	//deconstructor confirming object has been destroyed
	std::cout << "The die has been destroyed." << std::endl;
	return;
}

int aDie::roll() const{	//function that gets value of face rolled
	return (rand() % dieFaces);
}


