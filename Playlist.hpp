#ifndef PLAYLIST_HPP_
#define PLAYLIST_HPP_
#include "DLL.hpp"
#include <stdlib.h>
using namespace std;

class Playlist {
	DLL *list;  // the doubly linked list of playsongs
public:
	Playlist();//constructor that defaults filename to be read in to MyListOfSongs.txt
	Playlist(string fname);  // constructor that lets you enter your own text file.
	void interface(); //the ridiculously simple playlist interface
	void addSong();  //the method for adding a song to the end of the list  (this calls the DLL push method)
	void removeSong();  //the method called for removing a song (this calls the DLL Remove(string s) method)
	void ByeNow();  //quick goodbye message letting you know the program has ended
	void moveUp(); //moves a song up one in the playlist (so the song above it moves down one)-
					//calls the DLL's moveUp(string s) method
	void moveDown(); //Does the opposite of moveUP.  Calls the DLL's moveDown(string s) method
	void readList(string name);  //Reads in a list of songs from a text file.  name holds the name of the text file
	void printList();  //prints out the list of songs (calls the DLL's printList() method
	string strip(string &s);  //I used this to strip special characters and tokenize my string.
	string getTitle(); //I used to read in a title of a song from console
	void getDuration(); // used to find out and print out the playlist's total duration
	void makeNewList(); //for reading in the name of a new list file and creating a new list,
						//destroying the old one first.

};



#endif /* PLAYLIST_HPP_ */
