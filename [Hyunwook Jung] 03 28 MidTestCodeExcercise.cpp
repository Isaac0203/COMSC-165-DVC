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
Include new versions of the stream insertion and stream extraction operators appropriate to this class (as we saw in Lab 14).
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
	void setPounds(int pds)
	{
		pounds = pds;
	}
	void setOunces(double oz)
	{
		ounces = oz;
		roundOunces();
	}
	void roundOunces()
	{
		if (ounces >= 16.0)
		{
			setPounds(getPounds() + 1);
			setOunces(getOunces() - 16.0);
		}
	}
	const int getPounds() const;
	const double getOunces() const;
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
	
	EnglishWeight operator+(const EnglishWeight &right)
	{
		double totalOuncesFromLeft = (getPounds() * 16.0) + getOunces();
		double totalOuncesFromRight = (right.getPounds() * 16.0) + right.getOunces();
		return (totalOuncesFromLeft + totalOuncesFromRight);
	}

	EnglishWeight operator-(const EnglishWeight &right)
	{
		double totalOuncesFromLeft = (getPounds() * 16.0) + getOunces();
		double totalOuncesFromRight = (right.getPounds() * 16.0) + right.getOunces();
		return (totalOuncesFromLeft - totalOuncesFromRight);
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

int main()
{
	int tempPounds;
	double tempOunces;
	cout << "Enter the value of pounds: ";
	cin >> tempPounds;
	cout << "Enter the value of Ounces: ";
	cin >> tempOunces;
	EnglishWeight weight(tempPounds, tempOunces);
	EnglishWeight rightWeight(4, 18.5);

	cout << "The weight of this object is " << weight.getPounds() << " pounds, " << weight.getOunces() << " ounces." << endl;
	cout << weight + rightWeight << endl;
	cout << weight - rightWeight << endl;

	return 0;
}