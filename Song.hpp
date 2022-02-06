
#ifndef SONG_HPP_
#define SONG_HPP_
#include <iostream>
#include <stdlib.h>
using namespace std;

class Song {
	friend class DNode;
	friend class DLL;
	string title;  //title
	string artist;  //song artist name
	int min;  // for the number of total minutes
	int sec;  // for the leftover number of seconds
public:
	Song(string t, string a, int m, int s);
	Song();
	void printSong();
};



#endif /* SONG_HPP_ */
