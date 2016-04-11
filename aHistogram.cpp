#include <iostream>
#include <vector>
#include "aHistogram.h"	//aHistogram's various declarations

aHistogram::aHistogram() : dieFace(6){ //constructor that makes vector and max length to zero
	maxLengthOfLine = 0;
	std::cout << "The histogram has been created." << std::endl;
	return;
}
aHistogram::aHistogram(int n) : dieFace(n){
	maxLengthOfLine = 0;
	std::cout << "The histogram has been created." << std::endl;
	return;
}
aHistogram::~aHistogram(){	//deconstructor that prints confirmation the object has been destroyed
	std::cout << "The histogram has been destroyed." << std::endl;
	return;
}

void aHistogram::update(int face){	//function that object vector
	dieFace.at(face) += 1;
	return;
}

int aHistogram::count(int face) const{	//returns the # of occurences for a particular face
	return dieFace.at(face);
}

void aHistogram::display(int maxLengthOfLine){	//creates the histogram
	scale = getMaxOcc() / maxLengthOfLine;	//scale how much each x represents
	for (int i = 0; i < dieFace.size(); i++){	//for loop that prints out histogram a
		std::cout << i + 1 << ": " << count(i) << " ";
		while (dieFace.at(i) > scale)
		{
			std::cout << "x";
			dieFace.at(i) -= scale;
		}
		std::cout << std::endl;
	}

	return;
}

void aHistogram::clear(){ //empties histogram vector
	for (int j = 0; j < dieFace.size(); ++j){
		dieFace.at(j) = 0;
	}
	return;
}

int aHistogram::getMaxOcc(){	//helper that finds highest occurence of the faces
	maxOcc = 0;

	for (int i = 0; i < dieFace.size(); ++i){
		if (maxOcc < dieFace.at(i)){
			maxOcc = dieFace.at(i);
		}
	}
	return maxOcc;
}

