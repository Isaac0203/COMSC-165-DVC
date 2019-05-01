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
//========================================================================================
// Hyunwook Jung DVC
// COMSC 165
// Modified, 04 18 2019
// LAB 16

/*Use the Contact class from Lab #12 to create a ContactLinkedList class 
with all your contacts sorted in alphabetical order by name. 
The ContactLinkedList will have as functions:

insert a contact takes a Contact object as paramers and inserts in the appropriate position,
delete a contact takes a name as parameter and deletes the Contact with that name,
display all contacts.
Each Contact has stored as data a name, email, and phone. 
There should be a Contact * to the next Contact in the linked list. 
The Contact * can either be public in the Contact class, 
OR you could use a struct ListNode as shown in the slides (see below).*/
struct Contact
{
	string name = "n";
	string email = "e";
	string phone = "p";

	struct Contact *next;	// Pointing next node
}; 
class ContactLinkedList
{
private:
	
	Contact *head;	// List head pointer
public:
	// Constructor
	ContactLinkedList()
	{
		head = nullptr;
		
	}
	void appendList(string, string);
	void insertList(string, string, string);
	void deleteList(string);
	void displayList() const;
};

void ContactLinkedList::appendList(string e, string p)
{
	Contact *newContact;	// To point to a new contact
	Contact *contactPtr;	// To move through the list

	// Allocate a new contact and store string there.
	newContact = new Contact;
	newContact->email = e;
	newContact->phone = p;
	newContact->next = nullptr;

	// If there are no nodes in the list
	// make newContact the first node.
	if (!head)
	{
		head = newContact;
	}
	else
	{
		// Otherwise, insert newContact at end.

		// Initialize contactPtr to head of list
		contactPtr = head;

		// Find the last node in the list.
		while (contactPtr->next)
		{
			contactPtr = contactPtr->next;
		}

		// Insert newContact as the last node.
		contactPtr->next = newContact;
	}
	
}
void ContactLinkedList::insertList(string n, string e, string p)
{
	Contact *newContact = new Contact;
	newContact->name = n;
	newContact->email = e;
	newContact->phone = p;

	Contact *contactPtr;	//Index
	Contact *previousContact = nullptr;


	// If there are no nodes in the list
	// make newContact the first node
	if (!head)
	{
		head = newContact;
		newContact->next = nullptr;
	}
	else   // Otherwise, insert insertedContact
	{
		// Position contactPtr at the head of list
		contactPtr = head;

		while (contactPtr && (contactPtr->name) < n)
		{
			previousContact = contactPtr;
			contactPtr = contactPtr->next;
		}
		if (!previousContact)
		{
			head = newContact;
			newContact->next = contactPtr;
		}
		else {
			previousContact->next = newContact;
			newContact->next = contactPtr;
		}
	}
}

void ContactLinkedList::displayList() const
{
	Contact *contactPtr = head;
	cout << endl << endl << endl;
	cout << "=========================Displaying...==========================" << endl;

	while (contactPtr)
	{
		cout << "Name: " << contactPtr->name << endl;
		cout << "Email: " << contactPtr->email << endl;
		cout << "Phone: " << contactPtr->phone << endl;
		cout << "==============================" << endl;
		contactPtr = contactPtr->next;
	}
}
void ContactLinkedList::deleteList(string n)
{
	Contact *contactPtr;
	Contact *previousPtr;
	previousPtr = nullptr;
	bool nameFound = false;

	if (!head)
	{
		cout << "There is no contact node existing right now." << endl;
	}
	else
	{
		contactPtr = head;
		if (head->name == n) // If n name is in the first node
		{
			head = contactPtr->next;
			delete contactPtr;
		}
		else  // If n name is not in the first node
		{
			
			while (!nameFound && contactPtr->next) // While the next node is not null pointer 
			{
				// Check if the name is the same
				// If they are same, delete that node and adjust the pointers
				if (contactPtr->name == n)
				{
					// [Before] previousePtr -> contactPtr -> next
					// [Fixed] previousPtr (-> contactPtr) -> next
					previousPtr->next = contactPtr->next;
					// Delete current node
					delete contactPtr;

					nameFound = true;
				}
				// If they doesn't match, move the pointer one step forward
				previousPtr = contactPtr;
				
				contactPtr = contactPtr->next;
			}
			if (contactPtr->name == n)
			{
				previousPtr->next = nullptr;
				delete contactPtr;

			}/*
			if (contactPtr == nullptr)
			{
				cout << "You put a name that is not in this list." << endl;
				return;
			}
			else if (contactPtr->next == nullptr)
			{

			}*/
		}
	}
}
const int NUMPERSON = 10;
const int NUMBEROFYOURFRIENDSHAHA = 3;

int main()
{
	ContactLinkedList gentleman;
	gentleman.displayList();
	gentleman.appendList("AAAAASSSSSSSSSSSSSSSSSSSS", "EEEEEEEEEEEEEEEEEEEEEEE");
	gentleman.displayList();

	gentleman.appendList("BBB222", "444");
	gentleman.displayList();
	gentleman.insertList("Mynameeeee", "hello@@@@", "15151515");
	gentleman.insertList("Yournameeeeeee", "WAAAAAA@@@@.com", "0159238");
	gentleman.insertList("oyname", "hello@@@@", "15151515");
	gentleman.insertList("pyname", "hello@@@@", "15151515");
	gentleman.insertList("ryname", "hello@@@@", "15151515");

	gentleman.displayList();
	int menu;
	string tempName;
	string tempEmail;
	string tempPhone;
	do
	{
		menu = 0;
		cout << "Continue?" << endl;
		cout << "1. insertList	 2. deleteList	 3. displayList   4. Quit" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "Enter three stings for the name, email, and phone" << endl;
			cin >> tempName >> tempEmail >> tempPhone;
			gentleman.insertList(tempName, tempEmail, tempPhone);
			gentleman.displayList();
			break;
		
		case 2:
			cout << "Enter the name to delete: ";
			cin >> tempName;
			gentleman.deleteList(tempName);
			gentleman.displayList();
			break;
		
		case 3:
			gentleman.displayList();
			break;
		
		case 4:
			return 0;
			break;
		default:
			cout << "Enter a number between 1, 2, 3, or 4." << endl;
		

			
		}
	} while (1 <= menu <= 3);
	//delete[]tempEmail;
	return 0;
}
