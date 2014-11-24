/*
 * WordNode.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: derek
 */

#include "WordNode.h"

using namespace std;

WordNode::WordNode(){
	locations = vector<int> (0);
	title = "";
	artist = "";
	count = 0;
}

WordNode::WordNode(string cword, string cartist, string ctitle, int clocation){
	word = cword;
	artist = cartist;
	title = ctitle;
	count = 1;
	locations.push_back(clocation);
}

WordNode::~WordNode(){
}


