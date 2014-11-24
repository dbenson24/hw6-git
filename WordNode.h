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
	WordNode(std::string word, std::string cartist, std::string ctitle, int clocations);
	~WordNode();

	std::vector<int> locations;
	std::string title;
	std::string artist;
	std::string word;
	int count;

private:


};


#endif /* WORDNODE_H_ */
