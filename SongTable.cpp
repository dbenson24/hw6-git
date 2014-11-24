/*
 * SongTable.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: derek
 */

#include "SongTable.h"
#include <iostream>

using namespace std;

SongTable::SongTable(){
	songs = new vector< vector<SongNode> >(1, vector<SongNode>(0));
	nodecount = 0;
}

SongTable::~SongTable(){
}

// addSong
// Inserts the string array into the hash table
// Takes a vector <string> s to insert
void SongTable::addSong(SongNode s){
	//TODO: Code the Hashing function to add a song to the table
	uint32_t x = hash_string(s.words[0]+s.words[1]);
	int hash = x%size();
	if (loadFactor() > .5)
			expand();
	songs->at(hash).push_back(s);

}
// retrieveSong
// Hashes an artist and title and then finds it's vector <string>
// Returns a vector <string> containing the words of the song,
// the first two elements of the artist then the song title. Lyrics
// start at the 3rd position.
// Takes a string for the artist and a string for the title.
SongNode SongTable::retrieveSong(string artist, string title){
	//TODO: retrieveSong Should be done
	uint32_t x = hash_string(artist+title);
	int hash = x%size();
	vector<SongNode> temp = songs->at(hash);/*
	vector<SongNode*>::iterator iter;
	for (iter = temp.begin(); iter != temp.end(); iter++){
		if (compareNode(*iter, artist, title)){
			return *iter;
		}
	}*/
	for (int i = 0; i < (int)temp.size(); i++){
		if (compareNode(temp[i], artist, title)){
			cout << artist <<"\n";
			cout << title << "\n";
			cout << temp[0].words[0] << "\n";
			return temp[i];
		}
	}
}

int SongTable::size(){
	return songs->capacity();
}

double SongTable::loadFactor(){
	return ((double)nodecount)/((double)size());
}

void SongTable::expand(){
	vector< vector<SongNode> > *oldTable = songs;
	int oldSize = size();
	songs = new vector< vector<SongNode> >(oldSize*2, vector<SongNode>(0));
	vector< vector<SongNode> >::iterator iter;
	for (iter = oldTable->begin(); iter != oldTable->end(); iter++){
		vector <SongNode>::iterator curr;
		for (curr = iter->begin(); curr != iter->end(); curr++){
			addSong(*curr);
		}
	}
	delete oldTable;
}

bool SongTable::compareNode(SongNode s, string artist, string title){
	if (s.words[0].compare(artist) == 0 && s.words[1].compare(title) == 0)
		return true;
}
