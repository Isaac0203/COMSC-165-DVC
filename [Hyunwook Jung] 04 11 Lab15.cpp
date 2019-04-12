#include <iostream>
// Hyunwook Jung 
// Diablo Valley College COMSC 165
// 04 11 2019

using namespace std;

// This program declares a class called Inventory that has itemNumber (which
// contains the id number of a product) and numOfItem (which contains the
// quantity on hand of the corresponding product) as private data members.
// 
// The store sells just 3 products: books, DVDs, and CDs.
// Subclass the Inventory class with the classes Book, DVD, CD.
// The display function prints all values for an inventory object to the screen.

//

// The main function creates an array with 5 Inventory objects and then prints for
// each Inventory object the item number and number of items in stock. But it
// should also indicate if the item is a book, DVD or CD. For example:
// Book Item number 986 has 8 items in stock
// DVD Item number 432 has 24 items in stock
//Note: you may need to specify display as virtual.

// Write the implementations for all the member functions of the classes.



const int NUMOFPROD = 5; // This holds the number of products a store sells

class Inventory
{

private:
	int itemNumber = 1; // This is an id number of the product 
	int numOfItem = 2; // This is the number of items in stock


public:
	const int getId() const; // itemNumber of the object that calls it.

	void setId(int);

	const int getAmount() const; // numOfItem of the object that calls it.

	void setAmount(int);

	virtual void display(); // This prints to the screen
	// the value of itemNumber and numOfItem of the
	// object that calls it and whether it is "book", "dvd" or "cd".

};

const int Inventory::getId() const
{
	return itemNumber;
}
void Inventory::setId(int i)
{
	itemNumber = i;
}
const int Inventory::getAmount() const
{
	return numOfItem;
}
void Inventory::setAmount(int a)
{
	numOfItem = a;
}
void Inventory::display()
{
	cout << numOfItem << " " << itemNumber << endl;
}

class Book : public Inventory
{
private:

public:
	void display() {
		cout << "Book Item number " << getId() << " has " << getAmount() << " items in stock" << endl;
	}
};

class Dvd : public Inventory
{
private:

public:
	void display() {
		cout << "DVD Item number " << getId() << " has " << getAmount() << " items in stock" << endl;
	}
};

class Cd : public Inventory
{
private:

public:
	 void display() {
		cout << "CD Item number " << getId() << " has " << getAmount() << " items in stock" << endl;
	 }
};

int main()
{
	// Fill in the code that defines an array of objects of class Inventory
	// called products. The array should be of size NUMOFPROD

	Inventory *products[NUMOFPROD];

	int pos; // loop counter
	int id; // variable holding the id number
	int total; // variable holding the total for each id number

	

	// Fill in the code that will store inventory numbers and number of items
	// into the array of objects.

	// Fill in the code to print out the values (itemNumber and numOfItem 
	// and type) for each object in the array products.
	// This should be done by calling the member function display within a loop
	
	
	for (pos = 0; pos < NUMOFPROD; pos++)
	{
		
		int itemMenu = 0;
		do {
			cout << "What kind of item it is? (Enter 1, 2, or 3)" << endl;
			cout << "1. Book  2. CD   3. DVD" << endl;
			cin >> itemMenu;
		} while (1 > itemMenu && itemMenu > 3);

		switch (itemMenu)
		{
			case 1:
				products[pos] = &( Book());
				break;
			case 2:
				products[pos] = &( Cd());
				break;
			case 3:
				products[pos] = & ( Dvd());
				break;
			default:
				break;
		}

		do {
			cout << "Enter the ID number of item NO" << (pos + 1) << ": ";
			cin >> id;
			cout << "Enter the total amount of item NO" << (pos + 1) << ": ";
			cin >> total;
		} while (id < 0 || total < 0);
		(*products[pos]).setId(id);
		(*products[pos]).setAmount(total);
		cout << "---------------------------------------------------------" << endl;
	}
	cout << "=========================================================" << endl;
	cout << "Products' values got successfully modified" << endl;
	for (pos = 0; pos < NUMOFPROD; pos++)
	{
		(*products[pos]).display();
	}
	return 0;
}



