/*
 * SongNode.h
 *
 *  Created on: Nov 18, 2014
 *      Author: derek
 */

#ifndef SONGNODE_H_
#define SONGNODE_H_
#include <vector>
#include <string>

class SongNode {
public:
	SongNode();
	~SongNode();
	SongNode(std::vector<std::string>);

	std::vector <std::string> words;
};



#endif /* SONGNODE_H_ */
