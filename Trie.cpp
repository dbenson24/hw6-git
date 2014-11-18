//
//  Trie.cpp
//  trie
//
//  Created by Chris Gregg on 3/29/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#include "Trie.h"

Trie::Trie()
{
	root = new Node();
}

Trie::~Trie()
{
	// Free memory
}

void Trie::addWord(string s)
{// TODO: Student writes this function
	Node *temp = root;
	for(int i=0; i<s.length(); i++){
		if(temp->findChild(s[i])==NULL){
			Node *inserting = new Node();
			inserting->setCharacter(s[i]);
			temp->appendChild(inserting);
		}
		temp = temp->findChild(s[i]);
	}
	temp->setWordMarker();
}


bool Trie::searchWord(string s)
{
	// TODO: Student writes this function
	Node *temp = root;
	for (int i=0; i<s.length(); i++){
		if(temp->findChild(s[i]) == NULL)
			return false;
		temp = temp->findChild(s[i]);
	}
	if (temp->getWordMarker())
		return true;
	return false;
}

void Trie::printTrie(){
	root->printNode(0);
}

void Trie::addPreNodes(vector<preNode> preNodes) {
	root->addPreNodes(preNodes,0,1);
}
