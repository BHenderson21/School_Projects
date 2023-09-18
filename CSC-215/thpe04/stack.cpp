/** *********************************************************************
 * @file
 *
 * @brief Contains member functions for Stack class
 ***********************************************************************/
#include "stack.h"


 /** **********************************************************************
  *  @author Brandon G. Henderson
  *
  *  @par Description
  *  Stack constructor
  *
  *  @par Example
  *  @verbatim

	 Stack<cards> discardPile; // Creates a stack of cards

  *  @endverbatim
 ************************************************************************/
template <class TY>
Stack<TY>::Stack()
{
	headptr = nullptr;
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Stack destructor
 *
 *
 *  @par Example
 *  @verbatim

 *  @endverbatim
************************************************************************/

template <class TY>
Stack<TY>::~Stack()
{

}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Returns size of a stack
 * 
 *  @returns int containing size
 *
 *  @par Example
 *  @verbatim

	Stack<cards> discardPile;
	card card1;
	card card2;
	discardPile.push(card1);
	discardPile.push(card2);

	discardPile.size(); // Would equate to 2.

 *  @endverbatim
************************************************************************/

template <class TY>
int Stack<TY>::size()
{
	int i = 0;
	node* temp = headptr;
	if(headptr == nullptr)
	{
		return i;
	}
	else if (headptr->next == nullptr)
	{
		i++;
		return i;
	}
	else
	{
		while (temp->next != nullptr)
		{
			i++;
			temp = temp->next;
		}
		return i;
	}
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Adds an object to the top of a stack
 *
 *  @param[in] item Object of type TY to add to stack
 *
 *  @par Example
 *  @verbatim

	Stack<cards> discardPile;
	card card1;
	discardPile.push(card1); // Adds card1 to the top of discardPile

 *  @endverbatim
************************************************************************/

template <class TY> 
void Stack<TY>::push(TY item)
{
	node* newNode = new (nothrow) node;
	newNode->theItem = item;
	newNode->next = headptr;
	headptr = newNode;
}


/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  romoves an object from the top of a stack
 * 
 *  @param[in] item object of type TY to put the item popped into
 *
 *  @returns bool True if an item is removed, false otherwise
 *
 *  @par Example
 *  @verbatim

	Stack<cards> discardPile;
	card card1;
	discardPile.push(card1);
	discardPile.pop(card); // Would return true and put card1 into card.
	discardPile.pop(card); // Would return false and card would remain unchanged.

 *  @endverbatim
************************************************************************/

template <class TY>
bool Stack<TY>::pop(TY& item)
{
	if (size() == 0)
	{
		return false;
	}
	else
	{
		item = headptr->theItem;
		headptr = headptr->next;
		return true;
	}
}

/** **********************************************************************
 *  @author Brandon G. Henderson
 *
 *  @par Description
 *  Shows the top item of a stack.
 *
 *
 *  @returns object of type TY on top of the stack
 *
 *  @par Example
 *  @verbatim

	Stack<cards> discardPile;
	card card1;
	discardPile.push(card1);
	discardPile.top(); // Would return the top item of the stack.

 *  @endverbatim
************************************************************************/

template <class TY>
TY Stack<TY>::top()
{
	return headptr->theItem;
}