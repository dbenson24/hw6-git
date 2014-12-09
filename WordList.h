/*
 * WordList.h
 *
 *  Created on: Nov 18, 2014
 *      Author: derek
 */

#ifndef WORDLIST_H_
#define WORDLIST_H_

#include "WordTable.h"
#include "SongTable.h"

class WordList {
public:
	WordList();
	~WordList();

	void search(std::string query);
	void read_lyrics(const char* filename, bool show_progress);
	void printAllSongs();

private:
	WordTable *wordTable;
	SongTable *songTable;

	std::string alpha_only(std::string s);
	void printWordGroup (WordNode w);
};

#endif /* WORDLIST_H_ */
