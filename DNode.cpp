

#include "DNode.hpp"
#include <stdlib.h>
using namespace std;

DNode::DNode() {
	song = NULL;
	prev = NULL;
	next = NULL;
}

DNode::DNode(string s, string a, int lenmin, int lensec) {
	song = new Song(s, a, lenmin, lensec);
	prev = NULL;
	next = NULL;
}
