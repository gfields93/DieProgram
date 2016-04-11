#include <vector>

class aHistogram{	//the declarations of aHistogram class
public:
	aHistogram();	//default constructor
	aHistogram(int);   //custom constructor
	~aHistogram();	//deconstructor
	void update(int face);	//updates histogram values
	void display(int maxLengthOfLine);	//creates and displays histogram
	int count(int face) const;	//displays face count
	void clear();	//sets histogram values to zero


private:
	int maxLengthOfLine; //value for max length of line
	int getMaxOcc();	//helpper that finds the highest occurence of number rolled
	int maxOcc; //holds highest occurance
	int scale;	//holds value of each x
	std::vector<int> dieFace;	//vector that represents the dice's faces


};

