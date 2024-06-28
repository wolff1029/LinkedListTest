#include <iostream>
#include "myLinkedList.hpp"

using namespace std;  //introduces namespace std

int main()
{	
	//arrays for testing array assignment constructor
	char ch[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int i[] = {-9, 7, 11, 6, 7};
	float fl[] = {1.2, -9, 7};
	
	//testing default constructor
	myLinkedList<int> I;
	cout << "A list (I) of ints using default constructor.\n";
	I.print(cout);
	cout<<endl<<endl;

	//testing addFirst method
	I.addFirst(23);
	I.addFirst(12);
	I.addFirst(-8);
	cout << "After adding 23, 12, and -8 using addFirst method list L is: \n";
	I.print(cout);
	cout<<endl<<endl;

	//testing addLast method
	I.addLast(23);
	I.addLast(12);
	I.addLast(-8);
	cout << "After adding 23, 12, and -8 using addLast method list L is: \n";
	I.print(cout);
	cout<<endl<<endl;

	
	//testing array assignment constructor with floating-point numbers
	cout << "A list (F) of floats using array assignment constructor is:\n";
	myLinkedList<float> F(3, fl);
	F.print(cout);
	cout<<endl<<endl;
		
	//testting accessor methods on list (F)
	cout << "The first element of list F is " << F.getFirst() << endl;
	cout << "The last element of list F is " << F.getLast() << endl;
	cout<<endl<<endl;

	//testing copy constructor
	myLinkedList<int> I2(I);
	cout << "A copy of list (I) to list (I2) of ints is:\n";
	I2.print(cout);
	cout<<endl<<endl;

	//testing array assignment constructor with characters
	myLinkedList<char> C(6,ch);
	cout << "A list (C) of characters using array assignment constructor is:\n";
	C.print(cout);
	cout<<endl<<endl;

	//testing assignment operator
	myLinkedList<char> C2 = C;
	cout << "After assigning list C to C2 (C2=C) list (C2) is:\n";
	C2.print(cout);
	cout<<endl<<endl;
	
}

