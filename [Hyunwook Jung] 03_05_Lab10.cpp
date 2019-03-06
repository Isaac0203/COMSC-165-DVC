#include <iostream>
#include <cmath>
#include <iomanip>
// Hyunwook Jung DVC
// 03 05 2019 COMSC 165
// LAB 10
using namespace std;
struct circle
{
	double radius;
	double circumference;
	double area;
};

const int NUMCIRCLES = 10;
const double PI = 3.14;
int main() 
{
	/*Coding question:

Define a struct for a Circle with a radius, circumference, area.

Then define an array with 10 Circles.

Input the radius for each circle from the user (and also set its circumference, area).

Then output the area of the largest circle in the array.*/

	circle circles[NUMCIRCLES];

	// radius for each element in circles input function!
	for (int count1A = 0; count1A < NUMCIRCLES; ++count1A)
	{
		do {
			cout << "Enter a positive value for the radius for the circle No." << (count1A + 1) << ": ";
			cin >> circles[count1A].radius;
		} while (circles[count1A].radius < 0);
		// Circumference = 2PI*r;
		circles[count1A].circumference = circles[count1A].radius * 2 * PI;
		// Area = pow(r, 2) * PI;
		circles[count1A].area = pow(circles[count1A].radius, 2) * PI;

	}
	double largestArea = circles[0].area;
	// radius Input Check function!
	cout << fixed << setprecision(2);
	for (int count1A = 0; count1A < NUMCIRCLES; ++count1A)
	{
		cout << "Circles[" << count1A << "]: " << endl;
		cout << circles[count1A].radius << endl;
		cout << circles[count1A].circumference << endl;
		cout << circles[count1A].area << endl;
		cout << "===========================================" << endl << endl;

		// Find largestArea here
		if (largestArea < circles[count1A].area)
		{
			largestArea = circles[count1A].area;
		}
	}

	// Output largest area of the largest circle!
	cout << endl << "The largest area of ten circles is " << largestArea;
	return 0;

}