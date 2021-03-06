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
	delete wordTable;
	delete songTable;
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

	// -- While more data to read...
	while ( ! in.eof() )
	{
		SongNode newSong = SongNode();
		// -- First line is the artist
		getline(in, artist);
		if (in.fail()) break;

		// stores artist as the first entry in song vector
		newSong.words.push_back(artist);

		// -- Second line is the title
		getline(in, title);
		if (in.fail()) break;

		// stores title as the second entry in song vector
		newSong.words.push_back(title);
		song_count++;
		if ( show_progress )
		{
			if (song_count % 5000 == 0) {
				cout << "At "       << song_count <<
						" Artist: " << artist     <<
						" Title: "   << title << endl;
			}
		}
		// -- Then read all words until we hit the
		// -- special <BREAK> token
		int i = 2;
		while ( in >> word && word != "<BREAK>" ){
			//
			// -- Found a word
			//stores word in proper places on vector
			newSong.words.push_back(word);
			WordNode newnode = WordNode(alpha_only(word), song_count-1);
			wordTable->addWord(newnode);

			i++;
		}
		// -- Important: skip the newline left behind
		in.ignore();

		songTable->songs->push_back(newSong);
		/*if (song_count%1500 == 0)
		wordTable->sortAndDrop();*/
	}
	wordTable->sortAndDrop();
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

//
// search
//   purpose: to search lyrics database for a word
//			  and print out the occurrences of it for
//			  its top ten songs.
//   arguments: a string
//   returns: nothing
//   does: prints all occurrences of the string for the
//	       top ten songs associated with it.
//
void WordList::search(string query){
	HashedWord temp = wordTable->findWord(alpha_only(query));
	// If the HashedWord equals its default, the word was not found
	if (temp.word == ""){
		cout << "Word Not Found\n";
	}
	// Otherwise the word was found
	else{
		vector<WordNode>::iterator iter;
		// Prints the 10 words around each occurrence of the
		// query for the top ten songs
		for (iter = temp.hashedItems.begin();
				iter != temp.hashedItems.end(); iter++){
			printWordGroup(*iter);
		}
	}
}

//
// printWordGroup
//   purpose: print properly formatted context for a word node
//   arguments: a WordNode
//   returns: nothing
//   does: prints all occurrences of the word in the word node
//		   for the top ten songs associated with it.
//
void WordList::printWordGroup (WordNode w){
	// Moves through every word in the song
	for (int i = 2;
			i < (int)songTable->retrieveSong(w.songposition).words.size();
			i++){
		// If the current word equals the WordNode word
		if (w.word == alpha_only
				(songTable->retrieveSong(w.songposition).words.at(i))){
			// Print the Title Artist and the Context
			cout << "Title: " << songTable->retrieveSong
					(w.songposition).words.at(1) << "\nArtist: " <<
					songTable->retrieveSong(w.songposition).words.at(0)
					<< "\nContext: ";
			// Context is found by locating the 5 words on either side,
			// minus words that extend beyond the beginning and end of the
			// lyrics.
			for (int x = i-5; x <= i+5; x++){
				if (x > 1 && x < (int)songTable->retrieveSong
						(w.songposition).words.size()){
					cout << songTable->retrieveSong
							(w.songposition).words.at(x) << " ";
				}
			}
			cout << "\n\n";
		}
	}
}

