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

class WordTable {
public:
	WordTable();
	~WordTable();
	int addWord(std::string artist, std::string title, std::string word, int location);
	void addWordNode(WordNode w);
	std::vector<WordNode> atHash(int hash);
	int size();
	std::vector<WordNode> findWord(std::string word);

private:
	std::vector< std::vector<WordNode> > *wordNodes;
	int nodecount;
	double loadFactor();
	void expand();
};



#endif /* WORDTABLE_H_ */
