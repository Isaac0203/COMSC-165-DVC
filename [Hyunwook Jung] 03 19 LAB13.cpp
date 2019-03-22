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

// ===========================================
// Hyunwook Jung DVC
// COMSC 165
// 03 19 2019
// LAB 12 -> LAB 13
/*Extend Lab #12, such that there is a separate class ContactMeans 
that contains the phone number and email as private variables, 
along with public functions:

* one default constructor that sets phone and email to empty. DONE

* 2 specialized constructors that set just the email, or both phone and email. DONE

* setter and getter functions for phone and email. DONE

Then each Contact contains an object of ContactMeans.

The purpose is to get practice with classes 
that contain other classes' objects (aggregation).*/

class ContactMeans
{
private:
	string email;
	string phoneNumber;
public:
	ContactMeans()
	{
		email = " ";
		phoneNumber = " ";
		cout << endl << "-ContactMeans.object successfully created-";
	}
	ContactMeans(string e)
	{
		email = e;
		phoneNumber = " ";
		cout << endl << "-ContactMeans.object with email successfully created-";
	}
	ContactMeans(string e, string p)
	{
		email = e;
		phoneNumber = p;
		cout << endl << "-ContactMeans.object with email and phoneNumber successfully created-";
	}
	void setEmail(string);
	void setPhoneNumber(string);

	const string getEmail() const
	{
		return email;
	}
	const string getPhoneNumber() const
	{
		return phoneNumber;
	}
	~ContactMeans()
	{
		cout << endl << "-ContactMeans.object successfully deleted-";
	}
};
void ContactMeans::setEmail(string e)
{
	email = e;
}
void ContactMeans::setPhoneNumber(string p)
{
	phoneNumber = p;
}

class Contact
{
private:
	string name;
	ContactMeans cmObjInContact;
public:
	// Constructors

	Contact()
	{
		name = " ";
		cmObjInContact = ContactMeans();
		cout << endl << "-Contact.object successfully created-";
	}
	Contact(string n)
	{
		name = n;
		cmObjInContact = ContactMeans();
		cout << endl << "-Contact.object with name successfully created-";
	}
	Contact(string n, string e)
	{
		name = n;
		cmObjInContact = ContactMeans(e);
		cout << endl << "-Contact.object with name and email successfully created-";
	}
	Contact(string n, string e, string p)
	{
		name = n;
		cmObjInContact = ContactMeans(e, p);

		cout << endl << "-Contact.object with name, email, and phoneNumber successfully created-";
	}
	void setName(string);
	void setContactMeans(string, string);
	void setContactMeans_email(string);
	void setContactMeans_phoneNumber(string);

	const string getName() const
	{
		return name;
	}
	const string getContactMeans_email() const
	{
		return cmObjInContact.getEmail();
	}
	const string getContactMeans_phoneNumber() const
	{
		return cmObjInContact.getPhoneNumber();
	}
	// Destructor
	~Contact()
	{
		cout << endl << "-Contact.object successfully deleted-";
	}
};
void Contact::setName(string n)
{
	name = n;
}

void Contact::setContactMeans(string e, string p)
{

	Contact::cmObjInContact.setEmail(e);
	Contact::cmObjInContact.setPhoneNumber(p);
}

void Contact::setContactMeans_email(string e)
{
	Contact::cmObjInContact.setEmail(e);
}

void Contact::setContactMeans_phoneNumber(string p)
{
	Contact::cmObjInContact.setPhoneNumber(p);
}

const int NUMPERSON = 10;
const int NUMBEROFYOURFRIENDSHAHA = 3;

int main()
{
	// Initialize with Constructors Test!
	Contact doctorWho("WHO?", "WhoWhat?@yahoo.co.ur", "ask-who-0101");

	cout << endl << "#? " << "******";
	cout << endl << "Doc is " << doctorWho.getName();
	cout << endl << "Doc Email: " << doctorWho.getContactMeans_email();

	cout << endl << "Doc Phone Number: " << doctorWho.getContactMeans_phoneNumber();
	cout << endl << "===================================" << endl;

	cout << endl << "===================================" << endl;

	Contact myContact[NUMPERSON];

	for (int count = 0; count < NUMBEROFYOURFRIENDSHAHA; ++count)
	{
		cout << endl << "#" << count + 1 << "******" << endl;
		string tempN;
		cout << "Enter the email of your friend: ";
		getline(cin, tempN);
		myContact[count].setName(tempN);
		string tempE;
		cout << "Enter the email of your friend: ";
		getline(cin, tempE);
		myContact[count].setContactMeans_email(tempE);
		string tempP;
		cout << "Enter the phone number of your friend(This is not a phishing): ";
		getline(cin, tempP);
		myContact[count].setContactMeans_phoneNumber(tempP);

		cout << endl << "===================================" << endl;
	}

	for (int count = 0; count < NUMPERSON; ++count)
	{
		cout << endl << "#" << count + 1 << "******";
		cout << endl << "Name: " << myContact[count].getName();
		cout << endl << "Email: " << myContact[count].getContactMeans_email();

		cout << endl << "Phone Number: " << myContact[count].getContactMeans_phoneNumber();
		cout << endl << "===================================" << endl;
	}

	// Set one person's Info!!

	myContact[3].setName("Hyunwook Jung");
	myContact[3].setContactMeans_email("hjung369@insite.4cd.edu");
	myContact[3].setContactMeans_phoneNumber("987-654-3210");
	myContact[4].setName("WHO WHAT?");
	myContact[4].setContactMeans("WhoIsThis@gmail.com", "010-2345-6789");

		for (int count = 0; count < NUMPERSON; ++count)
		{
			cout << endl << "#" << count + 1 << "******";
			cout << endl << "Name: " << myContact[count].getName();
			cout << endl << "Email: " << myContact[count].getContactMeans_email();

			cout << endl << "Phone Number: " << myContact[count].getContactMeans_phoneNumber();
			cout << endl << "===================================" << endl;
		}



	//delete[];
	return 0;
}