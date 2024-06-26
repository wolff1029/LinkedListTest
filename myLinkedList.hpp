/*************************************************************************
* Name: Austin Wolff CSC 240
* Date: 06/30/2024 Lab #3
**************************************************************************
* Statement: Create a template class that implements a linked list as per the 
* requirements outlined in lab 3.
* Specifications: This program will provide methods which do the following:

* Input - For the above methods

* Output - For the above methods

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
	first = NULL;
	last = NULL;
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
	count=n;
	for(int i = 0; i<n; i++) {
		addFirst(anArray[i]);
	}
	return *this;
	
}

template <class type>
void myLinkedList<type>::destroyList()
{
	if(first != NULL){
		for(int i = 0; i<count -1; i++) {
		linkNode<type>* temp = first;
			if(first->nextElement != NULL){
				first = first->nextElement;
			}
		}
	}
}

template <class type>
myLinkedList<type>::~myLinkedList()
{
	destroyList();
	delete first;
	delete last;
}

template <class type>
void myLinkedList<type>::copyList(const myLinkedList<type>& otherList)
{
	if(otherList->first != NULL){
		first = otherList.first;
		count = otherList.count;
			for(int i = 0; i<count; i++) {
				addFirst(otherList[i]);
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
void myLinkedList<type>::print(ostream& outStream)
{
	if(first != NULL){
		linkNode <type> *loopLink;

		for(int i = 0; i<count -1; i++) {
			if(i == 0){
				loopLink = first;
			}
			outStream << loopLink->data;
			if(loopLink->nextElement != NULL){
				 loopLink = loopLink->nextElement;
			}
		}
	}
}

template <class type>
void myLinkedList<type>::addFirst(const type& theItem)
{	
	count++;

	linkNode<type> newLink;
	newLink.data = theItem;
	 if(first != NULL){
		newLink.nextElement = first;
	}
	first = &newLink;

	if(last == NULL){
		last = &newLink;
	}
}

template <class type>
void myLinkedList<type>::addLast(const type& theItem)
{
	linkNode<type> newLink;
	newLink.data = theItem;
	newLink.next = NULL;
	last->nextElement = newLink;
	
}

#endif /* MYLINKEDLIST_H_ */



		
