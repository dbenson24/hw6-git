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
	int startingcapacity = 10000000;
	wordNodes = new HashedWord[startingcapacity];
	nodeCount = 0;
	capacity = startingcapacity;
	for (int i = 0; i < capacity; i++){
		wordNodes[i] = HashedWord();
	}
}

WordTable::~WordTable(){
	delete[] wordNodes;
}

// addWord
// This function adds the word to the hash table, it combines words that have the
// same artist and title, increasing the count and adding the location to the
// location array.
// Takes the word's artist, title, the word, and the int location.
// Returns the hashing value of the word for quick access
int WordTable::addWord(WordNode inserting) {
	//TODO: addWord function should be done
	double lf = loadFactor();
	if (lf > 0.5)
		expand();
	uint32_t x = hash_string(inserting.word);
	int hash = (int)(x % capacity);
	bool notInserted = true;
	while (notInserted){
		if (wordNodes[hash].word == inserting.word){
			if (wordNodes[hash].hashedwordNodes.size() > 0){
				if (wordNodes[hash].hashedwordNodes.back().songposition==inserting.songposition){
					wordNodes[hash].hashedwordNodes.back().count++;
					return hash;
				}
			}
			if (wordNodes[hash].hashedwordNodes.size() > 10){
				sortAndDrop(hash);
			}
			wordNodes[hash].hashedwordNodes.push_back(inserting);
			notInserted=false;
		} else if (wordNodes[hash].word == "") {
			wordNodes[hash].word = inserting.word;
			wordNodes[hash].hashedwordNodes.push_back(inserting);
			nodeCount++;
			notInserted = false;
		}
		else{
			hash = (hash+1)%capacity;
		}
	}
	return hash;
}

void WordTable::sortAndDrop(){
	for (int i = 0; i < capacity; i++){
		if (wordNodes[i].word != ""){
			sort(wordNodes[i].hashedwordNodes.begin(), wordNodes[i].hashedwordNodes.end());
			if (wordNodes[i].hashedwordNodes.size() > 10)
				wordNodes[i].hashedwordNodes.erase(wordNodes[i].hashedwordNodes.begin()+10, wordNodes[i].hashedwordNodes.end());
		}
	}
}

void WordTable::sortAndDrop(int i){
	sort(wordNodes[i].hashedwordNodes.begin(), wordNodes[i].hashedwordNodes.end());
	if (wordNodes[i].hashedwordNodes.size() > 10)
		wordNodes[i].hashedwordNodes.erase(wordNodes[i].hashedwordNodes.begin()+10, wordNodes[i].hashedwordNodes.end());

}
// atHash
// This function will retrieve the array of WordNodes at the hash value
// returns the vector<WordNode> located at the hash.
HashedWord WordTable::atHash(int hash) {
	//TODO: atHash function should be done
	return wordNodes[hash];
}

HashedWord WordTable::findWord(string word) {
	//TODO: atHash function should be done
	uint32_t x = hash_string(word);
	int hash = (int)(x % capacity);
	while (true){
		if (wordNodes[hash].word == word || wordNodes[hash].word == ""){
			return wordNodes[hash];
		}
		hash++;
	}
}

double WordTable::loadFactor() {
	double n = double(nodeCount);
	double c = double(capacity);
	return n/c;
}

int WordTable::getCapacity() {
	return capacity;
}

int WordTable::getCount(){
	return nodeCount;
}

void WordTable::expand(){
	nodeCount = 0;
	HashedWord *oldTable = wordNodes;
	int oldCapacity = capacity;
	capacity = 2 * capacity;
	wordNodes = new HashedWord[capacity];
	for (int i = 0; i < oldCapacity; i++){
		if (oldTable[i].word != ""){
			vector <WordNode>::iterator curr;
			for (curr = oldTable[i].hashedwordNodes.begin(); curr != oldTable[i].hashedwordNodes.end(); curr++){
				if (curr->word != "")
					addWord(*curr);
			}
		}
	}
	delete[] oldTable;
}
