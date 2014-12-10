/*
 * WordTable.h
 *
 *  Created on: Nov 18, 2014
 *      Author: derek
 */

#ifndef WORDTABLE_H_
#define WORDTABLE_H_

#include <vector>
#include "WordNode.h"
#include "hashfunc.h"

struct HashedWord {
	std::string word;
	std::vector<WordNode> hashedItems;
	HashedWord() {word = ""; hashedItems = std::vector<WordNode>(0); }
};

class WordTable {
public:
	WordTable();
	~WordTable();
	int addWord(WordNode inserting);
	HashedWord findWord(std::string word);
	void sortAndDrop();
	void sortAndDrop(int i);

private:
	HashedWord *wordNodes;
	int nodeCount;
	int capacity;
	double loadFactor();
	void expand();
};



#endif /* WORDTABLE_H_ */
