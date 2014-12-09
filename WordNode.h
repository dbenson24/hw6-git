/*
 * WordNode.h
 *
 *  Created on: Nov 18, 2014
 *      Author: derek
 */

#ifndef WORDNODE_H_
#define WORDNODE_H_
#include <vector>
#include <string>

class WordNode {
public:
	WordNode();
	WordNode(std::string word, int position);
	~WordNode();

	int songposition;
	std::string word;
	int count;

private:


};


#endif /* WORDNODE_H_ */
