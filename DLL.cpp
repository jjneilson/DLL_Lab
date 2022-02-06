

#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;


	DLL::DLL(){  // constructor - initializes an empty list
		last = NULL;
		first = NULL;
		numSongs = 0;
	}
	DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
		DNode *n = new DNode (t,l,m,s);
		first = n;
		last = n;
		numSongs=1;
	}

	void DLL::push(string t, string a, int min, int sec){
		DNode *n = new DNode (t,a,min,sec);
		if(last == NULL && first == NULL){
			first = n;
			last = n;
			numSongs++;
		}
		else{
			n->prev = last;
			last->next = n;
			last = n;
			numSongs++;
		}
	}

	Song * DLL::pop(){
		Song *stemp = last->song;
		last = last->prev;
		delete last->next;
		last->next = NULL;
		return stemp;
	}

	int DLL::remove(string s){
		DNode *temp = first;
		int count = 0;
		while(temp != NULL){
			count++;
			if(temp->song->title == s){
				if(temp->prev == NULL){
					first = temp->next;
				}
				else if(temp->next == NULL){
					pop();
					break;
				}
				else{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
				}
				delete temp;
				numSongs--;
				break;
			}
			temp=temp->next;
		}
		return count;
	}

	void DLL::makeRandom(){
		for(int i = rand()%20;i>0;i--){
			moveUp(first->song->title);
			moveDown(first->song->title);
		}
	}

	void DLL::moveUp(string s){
		DNode *temp = first; //song that is being moved
		DNode *ptemp = NULL; //holders for directly adjacent songs with ptemp and ntemp being prev and next respectively
		DNode *ntemp = NULL;
		while(temp->song->title != s){
			temp=temp->next;
		}
		ntemp = temp->next;
		if(temp == first){
			ptemp = last;
			temp->next = NULL;
			temp->prev = ptemp;
			ptemp->next = temp;
			ntemp->prev = NULL;
			first = ntemp;
			last = temp;
		}
		else if (temp == last){
			ptemp = temp->prev;
			temp->prev = ptemp->prev;
			temp->next = ptemp;
			ptemp->prev = temp;
			ptemp->next = NULL;
			last = ptemp;
		}
		else{
			ptemp = temp->prev;
			temp->next = ptemp;
			temp->prev = ptemp->prev;
			temp->prev->next = temp;
			ptemp->prev = temp;
			ptemp->next = ntemp;
			ntemp->prev = ptemp;
		}

	}

	void DLL::moveDown(string s){
		DNode *temp = first; //song that is being moved
		DNode *ptemp = NULL; //holders for directly adjacent songs with ptemp and ntemp being prev and next respectively
		DNode *ntemp = NULL;
		while(temp->song->title != s){
			temp=temp->next;
		}
		ptemp = temp->prev;
		if(temp == last){
			ntemp = first;
			temp->prev = NULL;
			temp->next = ntemp;
			ptemp->next = NULL;
			ntemp->prev = temp;
			first = temp;
			last = ptemp;
		}
		else if(temp == first){
			ntemp = temp->next;
			temp->prev = ntemp;
			temp->next = ntemp->next;
			ntemp->next = temp;
			ntemp->prev = NULL;
			first = ntemp;

		}
		else{
			ntemp = temp->next;
			temp->prev = ntemp;
			temp->next = ntemp->next;
			ptemp->next = ntemp;
			ntemp->prev = ptemp;
			ntemp->next = temp;
		}

	}

	void DLL::listDuration(int * tm,int * ts){
		int min = 0;
		int sec = 0;
		for(DNode *temp = first;temp->next != NULL;temp = temp->next){
			 min += temp->song->min;
			 sec += temp->song->sec;
		}
		*tm = min;
		*ts = sec;

	}

	void DLL::printList(){
		DNode *temp = first;
		Song *songtemp;
		while (temp != NULL){
			songtemp = temp->song;
			songtemp->printSong();
			temp = temp->next;
		}
	}

	DLL::~DLL(){
		DNode *temp = first;
		DNode *destructor = temp;
		while(temp->next != NULL){
			temp = temp->next;
			destructor = temp->prev;
			delete destructor;
		}
		delete temp;
	    }



