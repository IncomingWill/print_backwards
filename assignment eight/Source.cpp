/*
Title: Chapter Sixteen Linked List Print Backwards Program -- Source Code
Created by William Schaeffer
CPS 362
P. 1174, Challenge 4, Linked List Print Backwards Program, Week 9
03.24.2022
*/

#include <iostream>
#include "linkedList.hpp"
#include "orderedLinkedList.hpp"

using namespace std;

void displayBackwards(orderedLinkedList<int>);					//function to display the linked list backwards

int main()
{
	orderedLinkedList<int> numberList;					//initialize list
	int number;								//initialize number to insert into list

	cout << "Please enter a list of numbers." << endl
		<< "When you like to end input, input -999." << endl << endl;

	cin >> number;

	while (number != -999)
	{
		numberList.insertLast(number);
		cin >> number;
	}
	
	if (numberList.isEmptyList())						//if list is empty, cannot print
	{
		cout << endl << "Cannot print an empty list." << endl << endl;
	}
	
	if (!numberList.isEmptyList())						//if list is not empty, print the list
	{
		cout << endl << "Here is the list you entered in order: ";

		numberList.print();

		cout << endl << "Now we will print it backwards with a class function: ";

		numberList.printListReverse();

		cout << endl << "Now we will print it backwards with a program function: ";

		displayBackwards(numberList);
	}

	return 0;
}

//Function to display the linked list backwards
	//outer for loop iterates to print each item in the list via count
	//inner for loop will iterate through the list, pointing at the last node
		//each time the outer loop finishes a single loop, (i) will decrement 
		//this causes the inner loop to iterate through the linked list by ( - 1 )

void displayBackwards(orderedLinkedList<int> list)
{

	int count = list.length();						//get number of items in list
	int data = 0;								//initialize variable to hold and print data from current node

	for (int i = count; i >= 1; i--)					//outer for loop iterates for each item in linked list
	{
		linkedListIterator<int> currentNode = list.begin();		//set currentNode to first node
		for (int j = i - 1; j >= 1; j--)				//inner for loop iterates to point currentNode at list node (i - 1)
		{
			++currentNode;						//currentNode will increment j times to find appropriate item in linked list
		}
		data = *currentNode;						//assign the node info to data and print
		cout << data << " ";
	}

}
