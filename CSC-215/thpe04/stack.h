/** *********************************************************************
 * @file
 *
 * @brief Contains prototypes for stack.cpp
 ***********************************************************************/
#pragma once
#include "thpe04.h"


 /**
	 * @brief Holds a stack of any data type, mainly cards for this program
 */
template <class TY>
class Stack
{
public:

	Stack();
	~Stack();
	void push(TY item);
	bool pop(TY& item);
	int size();
	TY top();


private:
	/**
	* @brief Holds data for a node in the stack's linked list.
	*/
	struct node
	{
		TY theItem; /**< Item of object type the stack is instantiated to hold */
		node* next; /**< Pointer to next node in stack */
	};
	node* headptr;  /**< Pointed to first node in stack */
};