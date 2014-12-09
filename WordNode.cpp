/*
 * WordNode.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: derek
 */

#include "WordNode.h"

using namespace std;

WordNode::WordNode(){
	songposition = -1;
	word = "";
	count = 0;
}

WordNode::WordNode(string cword, int position){
	word = cword;
	count = 1;
	songposition = position;
}

WordNode::~WordNode(){
}


