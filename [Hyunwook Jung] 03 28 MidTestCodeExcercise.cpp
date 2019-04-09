#include <iostream>
// 03 28 2019 DVC
// Hyunwook Jung
// COMSC 165

using namespace std;

/*In the English system of weights, we have pounds and ounces, with 1 pound equal to 16 ounces.
Write a class to implement English weights. The type name of the class must be EnglishWeight.

As we saw in Lab 14, you may declare the class in a header file called EnglishWeight.h and implement the class
in separate file called EnglishWeight.cpp.

Alternatively, as we saw in the example file inherit.cpp,
you may also declare and implement everything in one file named EnglishWeight.cpp.
Include appropriate constructors.

Include new versions of the stream insertion and stream extraction operators 
appropriate to this class (as we saw in Lab 14).

Provide the following operators:
EnglishWeight + EnglishWeight

EnglishWeight - EnglishWeight

Write a small test program in a main function to allow a user to enter two weights (in pounds and ounces).
The program will output the results of the two operations described above.

You can include the main function in a separate file called EW_Driver.cpp or in the single file named EnglishWeight.cpp
Fully comment the body of your code and provide a user friendly interface
Submit your source code as attachments to the drop box. Do not compress your attachments.*/

class EnglishWeight
{
private:
	int pounds;
	double ounces;
public:
	void setPounds(int pds)		// pounds Mutator
	{
		pounds = pds;
	}
	void setOunces(double oz)	// ounces Mutator
	{
		ounces = oz;
		roundOunces();
	}

	void roundOunces()	// Convert overflowing ounces into pounds
	{
		while (ounces >= 16.0)
		{
			setPounds(getPounds() + 1);
			setOunces(getOunces() - 16.0);
		}
	}
	const int getPounds() const;	// pounds accessor
	const double getOunces() const;	// ounces accessor

	// Constructor
	EnglishWeight()
	{
		pounds = 0;
		ounces = 0.0;
	}

	EnglishWeight(int pds)
	{
		pounds = pds;
		ounces = 0.0;
	}

	EnglishWeight(int pds, double oz)
	{
		pounds = pds;
		ounces = oz;
		roundOunces();
	}

	//Override

	EnglishWeight operator+(const EnglishWeight &right)		// L + R
	{
		double totalOuncesFromLeft = (getPounds() * 16.0) + getOunces();
		double totalOuncesFromRight = (right.getPounds() * 16.0) + right.getOunces();
		double totalOunces = totalOuncesFromLeft + totalOuncesFromRight;

		EnglishWeight addedWeight(0, totalOunces);
		return addedWeight;
	}

	EnglishWeight operator-(const EnglishWeight &right)		// L - R
	{
		double totalOuncesFromLeft = (getPounds() * 16.0) + getOunces();
		double totalOuncesFromRight = (right.getPounds() * 16.0) + right.getOunces();
		double totalOunces = totalOuncesFromLeft - totalOuncesFromRight;

		EnglishWeight subtractedWeight(0, totalOunces);
		return subtractedWeight;
	}

	
};

const int EnglishWeight::getPounds() const
{
	return pounds;
}
const double EnglishWeight::getOunces() const
{
	return ounces;
}

// Override iostream
ostream& operator << (ostream& strm, const EnglishWeight &obj)
{
	strm << endl << "========================================" << endl;
	strm << "Printing the object's members' values." << endl;
	strm << "Pounds: " << obj.getPounds() << endl;
	strm << "Ounces: " << obj.getOunces() << endl;
	return strm;
}

istream& operator >> (istream& strm, EnglishWeight &obj)
{
	cout << endl << "========================================" << endl;
	cout << "Input the object's members' values." << endl;
	cout << "Pounds: ";
	int pd;
	strm >> pd;
	obj.setPounds(pd);

	cout << "Ounces: ";
	int oz;
	strm >> oz;
	obj.setOunces(oz);
	return strm;
}

int main()
{
	// Temporary variables to store user's input for pounds and ounces in EnglishWeight Object
	int tempPounds;
	double tempOunces;

	cout << "Enter the value of pounds: ";
	cin >> tempPounds;
	cout << "Enter the value of Ounces: ";
	cin >> tempOunces;
	EnglishWeight weight(tempPounds, tempOunces);	// EnglishWeight constructor with all parameters

	// EnglishWeight Class Accessor Test
	cout << "The weight of this object is " << weight.getPounds() << " pounds, " << weight.getOunces() << " ounces." << endl;

	EnglishWeight weight2;	// EnglishWeight default constructor

	// Input Output Override Test
	cin >> weight2;
	cout << weight2;

	// + - Override Test
	cout << weight + weight2;
	cout << weight - weight2;

	return 0;
}
