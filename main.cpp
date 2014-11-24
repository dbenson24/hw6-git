/*
 * main.cpp
 *
 */
#include "WordList.h"
#include <iostream>

int main(int argc, char *argv[])
{
	std::string filename;
	WordList wordlist;

	/*if (argc == 2) { // if there is a filename on the command line
		wordlist.read_lyrics(argv[1],true);
	}
	else { // use a pre-defined filename*/
		filename = "/home/derek/Documents/hw6/hw6-git/rick_db.txt";
		//filename = "lyrics_fulldb.txt";
	        wordlist.read_lyrics(filename.c_str(),true);
	//}
        wordlist.search("Hi");
        wordlist.search("Cry");
        std::cout << "<END OF REPORT>";
        return 0;
}
