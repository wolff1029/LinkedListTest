/*************************************************************************
* Name: Austin Wolff CSC 240
* Date: 06/30/2024 Lab #3
**************************************************************************
* Statement: Create a template class that implements a linked list as per the 
* requirements outlined in lab 3.
* Specifications: This program will provide methods which do the following:
	- Theree constructors for the linked list template class
	- One destructor for the linked list template class
	- A method to retrieve the first pointer
	- A method to retrieve the last pointer
	- A method to retrieve the count of the list
	- A method to print the contents of the list and its count
	- An overload definition for the equals operator
	- A helper method to initialize the pointers to null and count to zero
	- A helper method to delete the contents of the linked list
	- A utility method to initialize the linked list based on another linked list
* Input - For the above methods:
	- The constructors for the linked list template class require as follows:
		- A default constructor with no inputs
		- A constructor which requires an integer and array of elements as input
		- A constructor which requires another linked list as an input
	- The destructor for the linked list template class requires no inputs
	- The method to retrieve the first pointer requires no inputs
	- The method to retrieve the last pointer requires no inputs
	- The method to retrieve the count of the list requires no inputs
	- The method to print the contents of the list and its count which requires an
	  output stream variable as input
	- The overload definition for the equals operator which requires another 
	  linked list as input
	- The helper method to initialize the pointers to null and count to zero
	  requires no input
	- The helper method to delete the contents of the linked list requires no input
	- The utility method to initialize the linked list based on another linked list 
	  requires another linked list as input
* Output - For the above methods:
	- The constructors for the linked list template class intialize the linked list
	  but have no explicit output or return type.
	- The destructor for the linked list template class deintializes the linked list
	  but has no explicit output or return type.
	- The method to retrieve the first pointer returns a pointer
	- The method to retrieve the last pointer returns a pointer
	- The method to retrieve the count of the list returns an integer
	- The method to print the contents of the list and its count which has no return
	  type but logs the contents of the linked list to the output
	- The overload definition for the equals operator returns a linked list
	- The helper method to initialize the properties of the linked list has no explicit
	  return
	- The helper method to delete the contents of the linked list has no explicit
	  return
	- The utility method to initialize the linked list based on another linked list 
	  has no explicit return

*************************************************************************/

#ifndef MYLINKEDLIST_H_
#define MYLINKEDLIST_H_

#include<iostream>

using namespace std;

//PROJECT 3 STUDENT FILE

//Defintion of the node to be used in the linked list
template<class type>
struct linkNode
{
	type data;
	linkNode <type> *nextElement;
};

//template class that implements a linked list of elements
//It is assumed that the list will either be empty or completely full
template <class type>
class myLinkedList
{	
	//********
	//Optional helper method that may be useful and make 
	//implementing the class easier
	//********
	private:
		void copyList(const myLinkedList<type>& otherList);
		//Utility method to copy a list. This method can be used when implementing
		//the copy constructor as well as overloading assignment (=)
		//Postcondition: otherList is assigned to this list
	
	//Data member objects	
	protected:
		int count;   				//the number of elements in the list
		linkNode <type> *first;		//linkNode pointing to the first element
		linkNode <type> *last;		//linkNode pointing to the last element
	
	//Methods	
	public:
		~myLinkedList();  
			//destructor for memory cleanup
			//Postcondition: Deletes all nodes from the list
		
		myLinkedList(); 	
			//default constructor
			//Postcondition: initializes count to zero and pointers to NULL
		
		myLinkedList(int n, type *anArray); 	
			//assignment constructor
			//Postcondition: copies contents of anArray parameter into the list and
			//sets count to n						
								
		myLinkedList(const myLinkedList & otherLinkedList); 
			//copy constructor
		
		int getCount() {return count;}
		
		void print(ostream& outStream); 
		//prints the elements of the list to the standard output stream
		//Postcondition: The elements of the list are printed to the 
		//standard output stream
		
		type getFirst(){return first->data;}
		//returns the first element of the list
		//Postcondition: Assuming the list is not empty, the first element
		//of the list is returned
		
		type getLast(){return last->data;}
		//returns the last element of the list
		//Postcondition: Assuming the list is not empty, the last element
		//of the list is returned
		
		void addFirst(const type& theItem);
		//adds the parameter theItem to the first part of the list
		//Postcondition: first points to the new list, newItem is inserted at the 
		//beginning of the list, count is incremented by 1
		
		void addLast(const type& theItem);
		//adds the parameter theItem to the last part of the list
		//Postcondition: first points to the new list, newItem is inserted at the 
		//end of the list, count is incremented by 1
		
		//OVERLOADED OPERATORS
		myLinkedList& operator=(const myLinkedList& rhs);
		//overloading of the assignment operator to allow for list to list assignment

		
		//********Optional, but useful, helper methods********
		void setDataMembers();
		//Postcondition: initializes count to zero, pointers to NULL
		void destroyList();	
		//Postcondition: deallocates the memory occupied by each node in list		
};

template <class type>
void myLinkedList<type>::setDataMembers()
{
	first = nullptr;
	last = nullptr;
	count=0;
}

template <class type>
myLinkedList<type>::myLinkedList()
{
	setDataMembers();	
}

template <class type>
myLinkedList<type>::myLinkedList(int n, type *anArray)
{
	setDataMembers();

	for(int i = 0; i < n; i++) {
		addLast(anArray[i]);
	}
	
}

template <class type>
void myLinkedList<type>::destroyList()
{
	if(first != nullptr){
		linkNode<type>* toBeDeleted = first;
		linkNode<type>* next = nullptr;

		while(toBeDeleted != nullptr) {
			next = toBeDeleted->nextElement;
			 delete toBeDeleted;
			toBeDeleted = next;
		}
	}
}

template <class type>
myLinkedList<type>::~myLinkedList()
{
	destroyList();
}

template <class type>
void myLinkedList<type>::copyList(const myLinkedList<type>& otherList)
{
	if(otherList.first != nullptr){

		setDataMembers();

		linkNode <type> *loopLink;

		for(int i = 0; i < otherList.count; i++) {
			if(i == 0){
				loopLink = otherList.first;
			}
			addLast(loopLink->data);

			if(loopLink->nextElement != nullptr){
				 loopLink = loopLink->nextElement;
			}
		}
	}
	
}

template <class type>
myLinkedList<type>::myLinkedList(const myLinkedList & otherList)
{
	copyList(otherList);
		
}


template <class type>
myLinkedList<type>& myLinkedList<type>::operator=(const myLinkedList& rhs)
{
	copyList(rhs);
	
}


template <class type>
void myLinkedList<type>::print(ostream& outStream){
	if(first != nullptr){
		linkNode <type> *loopLink;

		for(int i = 0; i < count; i++) {
			if(i == 0){
				loopLink = first;
			}
			// cout<< "print i = " << i << endl;
			outStream<< loopLink->data << " ";

			if(loopLink->nextElement != nullptr){
				outStream<< "-> ";

				 loopLink = loopLink->nextElement;
			}
		}
	} else{
		outStream << "EMPTY LIST";
	}

	outStream<< endl << "count = " << count;

}

template <class type>
void myLinkedList<type>::addFirst(const type& theItem){	
	
	count++;

	linkNode<type> *temp = new linkNode<type>();
	temp->data = theItem;
	temp->nextElement = first;
	first = temp;

	if(last == nullptr){
		last = temp;
	}
}

template <class type>
void myLinkedList<type>::addLast(const type& theItem){	
	count++;

	linkNode<type> *temp = new linkNode<type>();
	temp->data = theItem;
	temp->nextElement = nullptr;
	

	if(first == nullptr){
		first = temp;
		last = temp;
		return;
	}

	while(last->nextElement != nullptr){
		last = last->nextElement;
	}

	last->nextElement = temp;

}

#endif /* MYLINKEDLIST_H_ */



		
