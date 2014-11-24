/*
 * WordList.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: derek
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "WordList.h"
#include "WordTable.h"

using namespace std;

WordList::WordList(){
	wordTable = new WordTable();
	songTable = new SongTable();
}

WordList::~WordList(){
}
//
// read_lyics
//   purpose: read in song data from a disk file
//   arguments: the name of the file, bool to ask for progress status
//   returns: nothing
//   does: calls a function each time a word is found
//
void WordList::read_lyrics(const char* filename, bool show_progress){
	ifstream in(filename);			// creates an input stream
	int song_count = 0;			// for progress indicator
	string artist, title, word;
	WordList newList = WordList();

	// -- While more data to read...
	while ( ! in.eof() )
	{
		vector <string> songWords(10);

		WordTable song = WordTable();
		// -- First line is the artist
		getline(in, artist);
		if (in.fail()) break;

		// stores artist as the first entry in song vector
		songWords.push_back(artist);

		// -- Second line is the title
		getline(in, title);
		if (in.fail()) break;

		// stores title as the second entry in song vector
		songWords.push_back(title);

		if ( show_progress )
		{
			song_count++;
			if (song_count % 10000 == 0) {
				cout << "At "       << song_count <<
						" Artist: " << artist     <<
						" Title:"   << title << endl;
			}
		}
		// -- Then read all words until we hit the
		// -- special <BREAK> token
		int i = 2;
		while ( in >> word && word != "<BREAK>" ){
			//
			// -- Found a word
			//stores word in proper places on vector
			songWords.push_back(word);
			song.addWord(artist, title, alpha_only(word), i);
			i++;
		}
		// -- Important: skip the newline left behind
		in.ignore();
		// merge the temp hash table into the larger one
		for (int i = 0; i < song.size(); i++){
			vector <WordNode> temp = song.atHash(i);
			vector <WordNode>::iterator current;
			for(current = temp.begin(); current != temp.end(); current++){
				wordTable->addWordNode(*current);
			}
		}
		songTable->addSong(SongNode(songWords));
	}
}

//
// alpha_only
//   purpose: converts a string to lowercase and alphabetic characters
//            only. E.g., "Bang!" becomes "bang"
//   arguments: a string
//   returns: the alpha-only string
//   does: converts the string
//
string WordList::alpha_only(string s){
	ostringstream ss;
	for (size_t i=0;i<s.length();i++) {
		if (isalnum(s[i])){
			ss << (char)(tolower(s[i]));
		}
	}
	return ss.str();
}

void WordList::search(string query){
	//TODO: Search Function
	cout << "Searched for " << query << "\n";
	vector <WordNode> temp = wordTable->findWord(alpha_only(query));
	cout << temp.at(0).artist;
	vector <WordNode>::iterator current;
	for(current = temp.begin(); current != temp.end(); current++){
		printWordGroup(*current);
	}
	return;
}

void WordList::printWordGroup (WordNode w){
	SongNode temp = songTable->retrieveSong(w.artist, w.title);
	cout << "Artist: " << w.artist <<"\nSong Title: " << w.title <<"\n";
	vector <int>::iterator iter;
	for (iter = w.locations.begin(); iter != w.locations.end(); iter++){
		for (int i = *iter-5; i < *iter+5; i++){
			if (i > 2 && i < (int)temp.words.capacity())
				cout << temp.words[i] << " ";
		}
		cout << "\n";
	}
}
