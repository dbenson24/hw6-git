/*
 * SongTable.h
 *
 *  Created on: Nov 18, 2014
 *      Author: derek
 */

#ifndef SONGTABLE_H_
#define SONGTABLE_H_

#include <vector>
#include "SongNode.h"
#include "hashfunc.h"

struct HashedSong{
	std::string artisttitle;
	std::vector<SongNode> *songNodes;
};

class SongTable {
public:
	SongTable();
	~SongTable();
	void addSong(SongNode s);
	SongNode  retrieveSong(std::string artist, std::string title);

private:
	std::vector<HashedSong > *songs;
	int nodecount;
	double loadFactor();
	void expand();
	int size();
	bool compareNode(SongNode s, std::string artist, std::string title);
};



#endif /* SONGTABLE_H_ */
