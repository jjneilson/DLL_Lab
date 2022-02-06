
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "Playlist.hpp"
using namespace std;

Playlist::Playlist() {
	list = new DLL();
	readList("MyListOfSongs.txt");
	list->printList();
	cout << endl;
	interface();
}

Playlist::Playlist(string s) {
	list = new DLL();
	readList(s);
	list->printList();
	cout << endl;
	interface();
}

void Playlist::interface() {
	int choice=0;
	while (choice != 8) {
		cout << "What do you want to do?" <<endl<< flush;
		cout <<"Enter:" << endl<< flush;
		cout <<"\t1 for adding song"<<endl<< flush;
		cout <<"\t2 for removing a song" << endl<< flush;
		cout <<"\t3 for moving a song up in the list" << endl<< flush;
		cout <<"\t4 for moving a song down in the list" << endl<< flush;
		cout <<"\t5 for randomly shuffling the list" << endl<< flush;
		cout <<"\t6 for creating a brand new list" <<endl<< flush;
		cout <<"\t7 for getting the playlist's time duration"<< endl<<flush;
		cout <<"\t8 for exit" <<endl<< flush;

		cin >> choice;
		if (choice ==1) {
			addSong();
		}
		else if (choice == 2) {
			removeSong();
		}
		else if (choice == 3) {
			moveUp();
		}
		else if (choice == 4) {
			moveDown();
		}
		else if (choice ==5) {
			list->makeRandom();
			list->printList();
		}

		else if (choice ==6){
			makeNewList();
		}

		else if (choice ==7){
			getDuration();
		}
		else if (choice == 8) {
			ByeNow();
		}
	}
}

void Playlist::makeNewList() {
	cout << "Enter the name of the list you wish to enter:" <<endl << flush;
	string newlist = getTitle();
	delete list;
	list = new DLL();
	readList(newlist);
	list->printList();
}

void Playlist::getDuration() {
	int mintot = 0;
	int sectot = 0;
	list->listDuration(&mintot, &sectot);
	mintot += sectot/60;
	sectot = sectot%60;
	int hr = 0;
	if (mintot>=60) {
		hr = mintot/60;
		mintot %= 60;
	}
	cout << "The total playlist time is ";
	hr>0?cout<<hr<<":":cout<<" ";
	cout<< mintot<<":";
	sectot<10?cout<<"0"<<sectot:cout<<sectot;
	cout << endl<<flush;
	return;
}


void Playlist::moveUp() {
	cout<<"Moving a Song Up:" <<endl;
	cout << "Enter the title of the song you wish to move up in the list:" <<endl << flush;
	string title = getTitle();

	if (title.length() >0) {
		list->moveUp(title);
		list->printList();
	}
}
string Playlist::getTitle() {
	string song = "";
	while (song == "") {
	    getline(cin, song);
	}
	string title;
	title = strip(song);
	return title;

}
void Playlist::moveDown() {
	cout<<"Moving a Song Down:" <<endl;
	cout << "Enter the title of the song you wish to move down in the list:" <<endl << flush;
	string title = getTitle();

	if (title.length() >0) {
		list->moveDown(title);
		list->printList();
	}
}
void Playlist::removeSong() {
	cout<<"Removing a song:" <<endl;
	cout << "Enter the title of the song you wish to remove" <<endl << flush;
	string title = getTitle();

	if (title.length() >0) {
		list->remove(title);
		list->printList();
	}
}

void Playlist::addSong() {
	cout<<"Adding a song:" <<endl;
	cout << "Enter the song's info as follows: title, artist(s), min:sec" <<endl << flush;
	string song = "";
    while (song == "") {
    	getline(cin, song);
    }
	string artist;
	string title;
	string mins;
	string secs;
	title = strip(song);
	artist = strip(song);
	mins = strip(song);
	stringstream tmp(mins);
	int min = 0;
	tmp>>min;
	secs = song;
	stringstream tmp2(secs);
	int sec = 0;
	tmp2>>sec;
		//cout << title<<":::"<<artist<<":::"<<mins<<":::"<<secs<<":::"<<endl;
	if (title.length() >0) {
		list->push(title, artist, min, sec);
		list->printList();
	}

}
void Playlist::ByeNow() {
	cout << "Bye Now!" << endl;
	return;
}

string Playlist::strip(string &s) {
	const char* WhiteSpace = " \t\v\r\n";
	size_t start = s.find_first_not_of(WhiteSpace);
	const char* EndChar = ":,\n";
	size_t end = s.find_first_of(EndChar);
	string s2;
	int len = s.length();
	if (start<end){
		s2=s.substr(start,end-start);
		s = s.substr(end+1,len-end+1);
	}
	return s2;

}
void Playlist::readList(string f) {
	ifstream file(f.c_str());
	string songstr;
	string artist;
	string title;
	string mins;
	string secs;
	while (!file.eof()) {
		getline(file,songstr);
		cout << songstr<<endl;
		title = strip(songstr);
		artist = strip(songstr);
		mins = strip(songstr);
		stringstream tmp(mins);
		int min = 0;
		tmp>>min;
		secs = songstr;
		stringstream tmp2(secs);
		int sec = 0;
		tmp2>>sec;
		//cout << title<<":::"<<artist<<":::"<<mins<<":::"<<secs<<":::"<<endl;
		if (title.length() >0) {
			list->push(title, artist, min, sec);
		}
	}
	cout <<"*********DONE READING**************************"<<endl<<endl;
	return;
}



