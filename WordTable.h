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
	std::vector<WordNode> hashedwordNodes;
	HashedWord() {word = ""; hashedwordNodes = std::vector<WordNode>(0); }
	~HashedWord() {//hashedwordNodes->clear();
		//delete hashedwordNodes;
	}
};

class WordTable {
public:
	WordTable();
	~WordTable();
	int addWord(WordNode inserting);
	int getCapacity();
	int getCount();
	//	void addWordNode(WordNode w);
	HashedWord atHash(int hash);
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
