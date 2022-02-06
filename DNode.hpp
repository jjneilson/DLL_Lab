

#ifndef DNODE_HPP_
#define DNODE_HPP_
#include <stdlib.h>
using namespace std;

#include "Song.hpp"

class DNode {
	friend class DLL;
	Song *song;
	DNode *prev;
	DNode *next;
public:
	DNode();
	DNode(string s, string a, int lenmin, int lensec);
};



#endif /* DNODE_HPP_ */
