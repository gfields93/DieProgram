class aDie{	//aDie class decarations
public:
	aDie();	//default contructor
	aDie(int); //custom constructor
	~aDie();	//deconstructor
	int roll() const; // function that returns value of face

private:
	int dieFaces;
};

