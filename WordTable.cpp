/*
 * WordTable.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: derek
 */
#include <iostream>
#include <algorithm>
#include "WordTable.h"
using namespace std;

bool operator<(const WordNode &l, const WordNode &r) {
	if (l.count > r.count) return true;
	return false;
}

WordTable::WordTable(){
	int startingcapacity = 10;
	wordNodes = new HashedWord[startingcapacity];
	nodeCount = 0;
	capacity = startingcapacity;
	for (int i = 0; i < capacity; i++){
		// Initializes the hashtable with empty HashedWords.
		wordNodes[i] = HashedWord();
	}
}

WordTable::~WordTable(){
	delete[] wordNodes;
}

//
// addWord
//   purpose: to add a word to the hash table or increment
//			  the count if that word already exists for the
//			  current song.
//   arguments: a WordNode
//   returns: the int value of the hash used
//   does: hashes the word in the WordNode, inserts the WordNode
//	       associated with it. If the WordNode is already present
// 		   the count is incremented. To handle collisions this method
//		   uses linear probing.
//
int WordTable::addWord(WordNode inserting) {
	// Checks the loadfactor and expands if necessary
	double lf = loadFactor();
	if (lf > 0.5)
		expand();
	// Hashes the word
	uint32_t x = hash_string(inserting.word);
	int hash = (int)(x % capacity);
	bool notInserted = true;
	while (notInserted){
		// Linear Probing
		// Checks if there are already wordNodes for this word
		if (wordNodes[hash].word == inserting.word){
			// Checks if the last wordNode added is for this song
			if (wordNodes[hash].hashedItems.size() > 0){
				if (wordNodes[hash].hashedItems.back().songposition
						== inserting.songposition){
					// If it is, increment the count and return
					wordNodes[hash].hashedItems.back().count++;
					return hash;
				}
			}
			// If there are more than 10 wordNodes, sort them and drop the lowest
			if (wordNodes[hash].hashedItems.size() > 10){
				sortAndDrop(hash);
			}
			// Push the new WordNode into the hashtable and break the loop
			wordNodes[hash].hashedItems.push_back(inserting);
			notInserted=false;
		}
		else if (wordNodes[hash].word == "") {
			// If no WordNodes for this word had existed before, create a new entry
			// on the hashtable and increase the nodeCount of the hashtable
			wordNodes[hash].word = inserting.word;
			wordNodes[hash].hashedItems.push_back(inserting);
			nodeCount++;
			notInserted = false;
		}
		else {
			// If there is a collision, move to the next bucket and retry
			hash = (hash+1)%capacity;
		}
	}
	return hash;
}

//
// sortAndDrop
//   purpose: to sort all of the wordNodes at each hash entry
//			  by their count and then only keep the top 10.
//   arguments: none
//   returns: nothing
//   does: sorts the wordNodes at every hash value by their count
//	       and truncates the vector to a size of 10 values.
//
void WordTable::sortAndDrop(){
	// Moves through the entire hashtable
	for (int i = 0; i < capacity; i++){
		if (wordNodes[i].word != ""){
			// Calls sortAndDrop for each valid entry on the hashtable
			sortAndDrop(i);
		}
	}
}

//
// sortAndDrop
//   purpose: to sort all of the wordNodes at a single hash entry
//			  by their count and then only keep the top 10.
//   arguments: int position on the hash table
//   returns: nothing
//   does: sorts the wordNodes at the single hash value by their count
//	       and truncates the vector to a size of 10 values.
//
void WordTable::sortAndDrop(int i){
	// Uses std::sort to sort the vector from largest to smallest
	sort(wordNodes[i].hashedItems.begin(),
			wordNodes[i].hashedItems.end());
	// Truncates the newly sorted vector to 10 items
	if (wordNodes[i].hashedItems.size() > 10)
		wordNodes[i].hashedItems.erase(wordNodes[i].hashedItems.begin()+10,
				wordNodes[i].hashedItems.end());
}

//
// findWord
//   purpose: to find the HashedWord in the hashtable based
//			  on the string of the word
//   arguments: a string
//   returns: a HashedWord
//   does: a linear probe on the hash table until the HashedWord
//	       that equals the argument is found or until an empty
//		   space is found.
//
HashedWord WordTable::findWord(string word) {
	// Hash the word
	uint32_t x = hash_string(word);
	int hash = (int)(x % capacity);
	while (true){
		// Linear Probing
		if (wordNodes[hash].word == word || wordNodes[hash].word == ""){
			return wordNodes[hash];
		}
		hash++;
	}
}

//
// loadFactor
//   purpose: to calculate the loadfactor of the hashtable
//   arguments: none
//   returns: a double
//   does: divides the nodecount by the capacity to return
//		   the load factor
//
double WordTable::loadFactor() {
	double n = double(nodeCount);
	double c = double(capacity);
	return n/c;
}

//
// expand
//   purpose: to expand the hashtable to double its capacity
//   arguments: none
//   returns: nothing
//   does: makes a new hashtable twice the size, rehashes all
//	       of the old values to the new table.
//
void WordTable::expand(){
	// Create new table and double the capacity
	nodeCount = 0;
	HashedWord *oldTable = wordNodes;
	int oldCapacity = capacity;
	capacity = 2 * capacity;
	wordNodes = new HashedWord[capacity];
	// ReHash all of the values from the old table
	for (int i = 0; i < oldCapacity; i++){
		if (oldTable[i].word != ""){
			vector <WordNode>::iterator curr;
			for (curr = oldTable[i].hashedItems.begin();
					curr != oldTable[i].hashedItems.end(); curr++){
				if (curr->word != "")
					addWord(*curr);
			}
		}
	}
	// Prevent memory leaks of the old table
	delete[] oldTable;
}
