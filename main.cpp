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
	filename = "/home/derek/Documents/text_dbs/rick_db.txt";
	//filename = "/home/derek/Documents/text_dbs/count.txt";
	//filename = "/home/derek/Documents/text_dbs/2316Songs.txt";
	//filename = "/home/derek/Documents/text_dbs/13300Songs.txt";
	//filename = "/home/derek/Documents/text_dbs/lyrics_fulldb.txt";
	//filename = "/h/dbenso01/hw6/hw6-git/rick_db.txt";
	//filename = "lyrics_fulldb.txt";
	wordlist.read_lyrics(filename.c_str(),true);
	//}
	/*std::string query;
	while (true){
		std::cin >> query;
		if (query == "<BREAK>")
			break;
		else if (query == "")
			std::cout << "Please enter a valid word!\n";
		else{
			wordlist.search(query);
		}
	}*/
	wordlist.search("cry");
	std::cout << "<END OF REPORT>\n";
	return 0;
}
