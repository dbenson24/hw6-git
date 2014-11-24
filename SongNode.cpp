/*
 * SongNode.cp
 *
 *  Created on: Nov 18, 2014
 *      Author: derek
 */
#include "SongNode.h"
using namespace std;

SongNode::SongNode(){
	words = vector<string> (0);
}

SongNode::~SongNode(){
}

SongNode::SongNode(vector<string> s){
	words = s;
}

