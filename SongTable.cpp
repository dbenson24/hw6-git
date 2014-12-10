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

//
// retrieveSong
//   purpose: to return the SongNode at a given index
//   arguments: an int
//   returns: a SongNode
//   does: return the SongNode at the index given
//
SongNode SongTable::retrieveSong(int i){
	if (i < songs->size())
		return songs->at(i);
	else
		return songs->back();
}


