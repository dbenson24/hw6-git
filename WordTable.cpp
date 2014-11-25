/*
 * WordTable.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: derek
 */

#include "WordTable.h"
using namespace std;

WordTable::WordTable(){
	wordNodes = new vector< HashedWord >(1);
	nodecount = 0;
}

WordTable::~WordTable(){
	delete wordNodes;
}

// addWord
// This function adds the word to the hash table, it combines words that have the
// same artist and title, increasing the count and adding the location to the
// location array.
// Takes the word's artist, title, the word, and the int location.
// Returns the hashing value of the word for quick access
int WordTable::addWord(string artist, string title, string word, int location){
	//TODO: addWord function should be done
	uint32_t x = hash_string(word);
	int hash = (int)x%size();
	HashedWord temp = wordNodes->at(hash);
	if (temp.hashedwordNodes->size() == 0){
		temp.hashedwordNodes->push_back(WordNode(word, artist, title, location));
		return hash;
	}
	else{
		temp.hashedwordNodes->at(0).count++;
		temp.hashedwordNodes->at(0).locations.push_back(location);
		return hash;
	}
}


// addWordNode
// This function will insert the WordNode w into the hash table using the chaining method
void WordTable::addWordNode (WordNode w){
	//TODO: addWordNode function should be done
	uint32_t x = hash_string(w.word);
	int hash = x%size();
	if (loadFactor() > .5)
		expand();
	wordNodes->at(hash).hashedwordNodes->push_back(w);
}

// atHash
// This function will retrieve the array of WordNodes at the hash value
// returns the vector<WordNode> located at the hash.
HashedWord WordTable::atHash(int hash){
	//TODO: atHash function should be done
	return wordNodes->at(hash);
}

HashedWord WordTable::findWord(string word){
	//TODO: atHash function should be done
	uint32_t x = hash_string(word);
	int hash = x%size();
	return wordNodes->at(hash);
}

int WordTable::size(){
	return wordNodes->size();
}

double WordTable::loadFactor(){
	return ((double)nodecount)/((double)size());
}

void WordTable::expand(){
	vector< HashedWord > *oldTable = wordNodes;
	int oldSize = size();
	wordNodes = new vector< HashedWord >(oldSize*2);
	vector< HashedWord >::iterator iter;
	for (iter = oldTable->begin(); iter != oldTable->end(); iter++){
		vector <WordNode>::iterator curr;
		for (curr = iter->hashedwordNodes->begin(); curr != iter->hashedwordNodes->end(); curr++){
			addWordNode(*curr);
		}
	}
	delete oldTable;
}
