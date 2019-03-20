#include <iostream>
#include <string>
using namespace std;

// Hyunwook Jung DVC
// COMSC 165
// 03 17 2019
// LAB 12

/*Design a class Contact with the data and functionality for one contact person on your phone.
As data it should store a name, email, and phone.

The functions should include getter (accessor)
and setter (modifier) functions for each of these data items.

Write a small main function that initializes an array of size 10 with:

3 Contact objects for your friends, and
7 Contact objects with default data (blank).
Show how you would change the phone for one contact.*/

class Contact
{
private:
	string name;
	string email;
	string phoneNumber;
public:
	// Constructors

	Contact()
	{
		name = " ";
		email = " ";
		phoneNumber = " ";

		cout << endl << "-object successfully created-";
	}
	Contact(string  n)
	{
		name = n;
		email = " ";
		phoneNumber = " ";
		cout << endl << "-object successfully created-";
	}

	Contact(string n, string e, string p)
	{
		name = n;
		email = e;
		phoneNumber = p;

		cout << endl << "-object successfully created-";
	}
	void setName(string);
	void setEmail(string);
	void setPhoneNumber(string);

	const string getName() const
	{
		return name;
	}
	const string getEmail() const
	{
		return email;
	}
	const string getPhoneNumber() const
	{
		return phoneNumber;
	}

	// Destructor
	~Contact()
	{
		
		cout << endl << "-memory successfully deleted-";
	}
};
void Contact::setName(string n)
{
	name = n;
}
void Contact::setEmail(string e)
{
	email = e;
}
void Contact::setPhoneNumber(string p)
{
	phoneNumber = p;
}

const int NUMPERSON = 10;
const int NUMBEROFYOURFRIENDSHAHA = 3;

int main()
{
	Contact myContact[NUMPERSON];
	
	for (int count = 0; count < NUMBEROFYOURFRIENDSHAHA; ++count)
	{
		cout << endl << "#" << count + 1 << "******" << endl;
		string tempN;
		cout << "Enter the name of your friend: ";
			getline(cin, tempN);
		myContact[count].setName(tempN);
		string tempE;
		cout << "Enter the email of your friend: ";
			getline(cin, tempE);
		myContact[count].setEmail(tempE);
		string tempP;
		cout << "Enter the phone number of your friend(This is not a phishing): ";
			getline(cin, tempP);
		myContact[count].setPhoneNumber(tempP);

		cout << endl << "===================================" << endl;
	}

	for (int count = 0; count < NUMPERSON; ++count)
	{
		cout << endl << "#" << count + 1 << "******";
		cout << endl << "Name: " << myContact[count].getName();
		
		cout << endl << "Email: " << myContact[count].getEmail();

		cout << endl << "Phone Number: " << myContact[count].getPhoneNumber();
		cout << endl << "===================================" << endl;
	}

	// Set one person's Info!! It's me
	myContact[3].setName("Hyunwook Jung");
	myContact[3].setEmail("hjung369@insite.4cd.edu");
	myContact[3].setPhoneNumber("987-654-3210");

	for (int count = 0; count < NUMPERSON; ++count)
	{
		cout << endl << "#" << count + 1 << "******";
		cout << endl << "Name: " << myContact[count].getName();

		cout << endl << "Email: " << myContact[count].getEmail();

		cout << endl << "Phone Number: " << myContact[count].getPhoneNumber();
		cout << endl << "===================================" << endl;
	}


	//delete[]tempEmail;
	return 0;
}