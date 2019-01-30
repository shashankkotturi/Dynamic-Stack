/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  vskottur @uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  Fall 2017
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    - s72rahma
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    - s72rahma (debugging, test cases)
 *    - akelsaig (debugging)
 *****************************************/


/*
 * Dynamic_Stack
 *
 * Shashank Kotturi
 * 2017-10-08
 *
 * The Dynamic_Stack class implements basic stack functionality
 * using an array of a valid size specified by the user. This
 * implementation of the stack functionality only stores integers.
 * Stack implentation is done in a "reverse order" in which the 
 * topmost integer of the stack is the last element inserted into the array.
 *
 * Member Variables:
 *      int *array          Pointer to array that implements the stack
 *		int count		    Size of the stack
 *                               Must be greater than or equal to 0.
 *		int array_size      Current capacity of the stack
 *                               Must be greater than or equal to 1.
 *		int initial_size    Capacity of the stack when initialized
 *                               Must be greater than or equal to 1.
 *                                Default initial value is 10.
 *
 * Member Functions (Accessors):
 *
 *      int top() const
 *          Return the integer at the top of the stack in O(1).
 *          May throw an underflow exception if stack is empty.
 *	
 *      int size() const
 *          Return the number of elements currently stored in O(1).
 *
 *      bool empty() const
 *           Return true if stack is empty, false otherwise in O(1).
 *
 *      int capacity() const
 *          Return the capacity of the stack in O(1).
 *
 *
 * Member Functions (Mutators):
 *
 *      void push( int const & )
 *           Insert a new item at the head of the stack in O(1). 
 *           If the array is full, create a new array with size 2n
 *           (where n is current size of the array) and copy the elements
 *           from the current array to the new array in O(n).
 *
 *		int pop()
 *           Remove the element at the top of the stack in O(1). 
 *           This may throw an underflow exception.
 *
 *		void clear()
 *          Remove all elements from the stack in O(1). If the current array
 *          size does not equal the initial size, delete the array and create
 *          a new array equal to the initial size. 
 *
 *
 * Bugs:           None detected as of October 8, 2017
 * Todo:           Nothing left as of October 8, 2017
 * References:     For commenting code: https://ece.uwaterloo.ca/~dwharder/icsrts/C/02/
 */


#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#ifndef nullptr
#define nullptr 0
#endif

#include "Exception.h"
#include <iostream>
using namespace std;


class Dynamic_stack {

	private:
		int *array;
		int count;		
		int array_size;
		int initial_size;
	
	public:
		Dynamic_stack(int = 10);
		~Dynamic_stack();

		int top() const;
		int size() const;
		bool empty() const;
		int capacity() const;
			
		void push( int const & );
		int pop();
		void clear();		
};


/*
 * Dynamic_stack::Dynamic_stack( int n )
 *
 * Constructor initialization for stack implementation
 * 
 * Initializes size of stack (count) to 0.
 * Initializes array_size and initial_size to a value of n
 * if and only if n >= 1. Else, array_size and initial_size
 * are initialized to a minimum value of 1. Default initialization
 * value for array_size and initial_size is 10 as called above.
 * An array of size array_size is initialized.
 *
 * Parameter n is the specified size of the array by user.
 *           n must be greater than or equal to 1.
 *
 */

Dynamic_stack::Dynamic_stack( int n ):
count( 0 ),
array_size( n > 0 ? n : 1 ),
initial_size( n > 0 ? n : 1 )
{
    array = new int[array_size];
}


/*
 * Dynamic_stack::~Dynamic_stack()
 *
 * Destructor implentation for class Dynamic_stack.
 *
 * Deletes all contents of array, resets values of variables
 * count, array_size, initial_size to 0.
 *
 */
 
Dynamic_stack::~Dynamic_stack() {
	delete[] array;
	count = 0;
	array_size = 0;
	initial_size = 0;
}

/*
 * int Dynamic_stack::top() const
 *
 * Returns the value of the last integer inserted into the stack, 
 * i.e., the topmost integer on the stack. May throw underflow
 * exception if stack is empty.
 *
 * Runs in O(1).
 *
 * Returns:
 *  The topmost integer on the stack. May throw underflow exception
 *  if stack is empty.
 */

int Dynamic_stack::top() const {
    
    // Throw stack underflow exception if stack is empty.
    if(count == 0){
       throw underflow();
    }
    
    // Return topmost integer on the stack if stack is not empty.
    return array[count - 1];
}

/*
 * int Dynamic_stack::size() const
 *
 * Returns the size of the stack.
 * Does not return a negative value as size of stack cannot negative.
 *
 * Runs in O(1).
 *
 * Returns:
 *  The size of the stack.
 */

int Dynamic_stack::size() const {
	return count;
}

/*
 * int Dynamic_stack::empty() const
 *
 * Returns true if size of stack is 0, i.e., stack is empty.
 * Returns false if size of stack is not 0, i.e., stack is not empty.
 *
 * Runs in O(1).
 * 
 * Returns:
 *  True if stack is empty, otherwise false.
 */

bool Dynamic_stack::empty() const {
	return !(count > 0);  
}

/*
 * int Dynamic_stack::capacity() const
 *
 * Returns total number of integer that can be inserted into stack,
 * i.e., the capacity of the stack (stored as array_size).
 *
 * Runs in O(1).
 *
 * Returns:
 *  The capacity of the stack.
 */

int Dynamic_stack::capacity() const {
	return array_size;
}

/*
 * void Dynamic_stack::push( int const &obj )
 *
 * Inserts an integer value to the top of the stack.
 * Array implemented in "reverse order", i.e., topmost element
 * of the stack is the last element inserted into the array.
 *
 * If capacity of stack is full, a new array of twice the size of
 * the previous array is created, stack is copied to the new array,
 * and new element is then inserted last into the new array. The
 * previous array is then deleted.
 *
 * Parameter obj is passed to the function through pass by reference.
 *
 * Runs in O(1) if stack is not full. Runs in O(n) if stack if full,
 * where n is the size of the stack.
 *
 * Returns:
 *  Control back to caller of function.
 */

void Dynamic_stack::push( int const &obj ) {
	
    // Implementing stack in reverse order within the array
	
    // When array is full with elements of stack, double the 
    // size of the array, copy elements over and delete old array.
	if(count == array_size){
       int *tempArray = new int[2 * array_size];
       for (int i = 0; i < array_size; i++){
           tempArray[i] = array[i];
       }
       array_size *= 2;
       
       delete[] array;
       array = tempArray;  
    }
    
    // When array is not full with elements of the stack
    // insert new element of the stack as the last element.
    // Increment size of stack to reflect insertion of new element.
    array[count] = obj;
    count++;
    
    return;  

}

/*
 * void Dynamic_stack::pop()
 *
 * Returns topmost element in stack. May throw an underflow exception
 * if stack is empty.
 *
 * Removes topmost element from stack and returns that elements.
 * Throws an underflow exception when stack is empty.
 *
 * Runs in O(1).
 *
 * Returns:
 *  Topmost element in stack. May throw an underflow exception if stack
 *  is empty.
 */

int Dynamic_stack::pop() {
	
	// Throw underflow exception if stack is empty
	if(count == 0){
       throw underflow();
       return 0; 
    }
    
    // Remove topmost element from stack, decrement size of stack
    int returnValue = array[count - 1];
    array[count - 1] = 0;
    count--;
    
    // Return topmost element of stack
    return returnValue;
}

/*
 * void Dynamic_stack::clear()
 *
 * Deletes contents of array if current array_size is different from
 * initial_size. "Clears" array by ensuring array is of size initial_size,
 * and stack is of size 0.
 *
 * Runs in O(1).
 *
 * Returns:
 *  Control back to caller of function.
 */

void Dynamic_stack::clear() {
    
    // Delete array and create array of size of initial_size
    // if array_size is not equal to initial_size.
    if(array_size != initial_size){
       delete[] array;
       array = new int[initial_size];
    }
    
    // array_size is equal to initial_size if array was or was not deleted.
    array_size = initial_size;
    
    // Resetting size of stack implements "clearing" of stack.
    count = 0;
	
    return; 
}

#endif
