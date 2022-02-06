#include "Song.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

Song::Song(string t, string a, int m, int s) {
	title = t;
	artist = a;
	min = m;
	sec = s;
}
Song::Song() {
	title = "unknown";
	artist = "none";
	min = 0;
	sec = 0;
}
void Song::printSong() {
	cout << title <<", "<<artist<<"................"<<min<<":";
	sec < 10?cout<<"O"<<sec<<endl:cout<<sec<<endl;
}
