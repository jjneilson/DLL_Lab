

#ifndef DLL_HPP_
#define DLL_HPP_

#include "DNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

class DLL {
	DNode *first;
	DNode *last;
	int numSongs;
public:
	DLL();  // constructor - initializes an empty list
	DLL(string t, string l, int m, int s);  // constructor, initializes a list with one new node with data x
	void push(string t, string a, int m, int s);  // does what you'd think
	Song *pop();  //does what you'd think
	int remove(string t);
	void makeRandom();  // randomizes the order of the list
	void moveUp(string t);  // moves song with title s up one in the playlist.
	                        //If it is at the beginning of the list,
	                        //it will be moved to the end of the list.

	void moveDown(string t); //moves song with title s down one in the playlist.
							//If it is at the end of the list, it will move to
							//beginning of the list.
	void listDuration(int *tm, int *ts);  // gets the total list duration in minutes (passed in as pointers)
										// and seconds (again, passed in as pointers)
	void printList();
	~DLL();
};



#endif /* DLL_HPP_ */
