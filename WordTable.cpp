/*
 * WordTable.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: derek
 */

#include "WordTable.h"
using namespace std;

WordTable::WordTable(){
	wordNodes = new vector< vector<WordNode> >(1, vector<WordNode>(0));
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
	vector<WordNode> temp = wordNodes->at(hash);
	if (temp.size() == 0){
		temp.push_back(WordNode(word, artist, title, location));
		return hash;
	}
	else{
		temp.at(0).count++;
		temp.at(0).locations.push_back(location);
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
	wordNodes->at(hash).push_back(w);
}

// atHash
// This function will retrieve the array of WordNodes at the hash value
// returns the vector<WordNode> located at the hash.
vector<WordNode> WordTable::atHash(int hash){
	//TODO: atHash function should be done
	return wordNodes->at(hash);
}

vector<WordNode> WordTable::findWord(string word){
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
	vector< vector<WordNode> > *oldTable = wordNodes;
	int oldSize = size();
	wordNodes = new vector< vector<WordNode> >(oldSize*2, vector<WordNode>(0));
	vector< vector<WordNode> >::iterator iter;
	for (iter = oldTable->begin(); iter != oldTable->end(); iter++){
		vector <WordNode>::iterator curr;
		for (curr = iter->begin(); curr != iter->end(); curr++){
			addWordNode(*curr);
		}
	}
	delete oldTable;
}
