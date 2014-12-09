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
	songs = new vector<SongNode>(0);
	nodecount = 0;
}

SongTable::~SongTable(){
	songs->clear();
	delete songs;
}

// retrieveSong
// Hashes an artist and title and then finds it's vector <string>
// Returns a vector <string> containing the words of the song,
// the first two elements of the artist then the song title. Lyrics
// start at the 3rd position.
// Takes a string for the artist and a string for the title.
SongNode SongTable::retrieveSong(int i){
	//TODO: retrieveSong
	return songs->at(i);
}


