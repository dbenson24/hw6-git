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

class SongTable {
public:
	SongTable();
	~SongTable();
	SongNode  retrieveSong(int i);
	std::vector<SongNode> *songs;

private:
	int nodecount;
};



#endif /* SONGTABLE_H_ */
