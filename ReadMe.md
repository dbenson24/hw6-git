# ReadMe for COMP 15 HW6
## Song Search 
### Derek Benson

This program is titled Song Search. It is designed to process a database
of song lyrics that is stored in a text file. Each song is seperated by
a <BREAK> marker and the first two entries of the song are its title and
artist. After processing the database the program will search for the 
alpha only version of any words typed into it. Entering <BREAK> will 
cause the program to terminate.

main.cpp 
    Defines the main class. It chooses a txt file to read in
    based on whether there is one present on the command line.
    It then creates the database and prompts the user for
    search queries.

hashfunc.cpp 
    Defines the hashfunc class. Used to hash a string.

hashfunc.h 
    This is the header file for the hashfunc class. It declares
    all of the methods and variables defined in hashfunc.cpp.

SongNode.cpp 
    Defines the SongNode class. Used to store all of the lyrics,
    the artist, and the title of a song.

SongNode.h 
    This is the header file for the SongNode class. It declares
    all of the methods and variables defined in SongNode.cpp.

SongTable.cpp 
    Defines the SongTable class. Used to store each individual
    song into a dynamic array.

SongTable.h 
    This is the header file for the SongTable class. It declares
    all of the methods and variables defined in SongTable.cpp.

WordList.cpp 
    Defines the WordList class. Used to create a WordList that
    consists of a hashtable, wordTable, and a dynamic array of
    songs, songTable.

WordList.h 
    This is the header file for the WordList class. It declares
    all of the methods and variables defined in WordList.cpp.

WordNode.cpp 
    Defines the WordNode class. Used to store all of the information
    needed for a word's appearance in a specific song.

WordNode.h 
    This is the header file for the WordNode class. It declares
    all of the methods and variables defined in WordNode.cpp.

WordTable.cpp 
    Defines the WordTable class. Used to create a hashtable
    of hashedItems that contain WordNodes to each the top ten
    songs for each word.

WordTable.h
    This is the header file for the WordTable class. It declares
    all of the methods and variables defined in WordTable.cpp.

This program will compile with the included MakeFile.


This program uses two main datastructures to complete it's tasks.

A WordTable stores all of the words in a hashtable using linear probing.
The WordTable is made of structs of HashedWords that contain vectors of 
WordNodes which hold the word and their respective songs position on the
SongTable.
A SongTable stores all of the songs into its dynamic array of SongNodes.
Each SongNode contains a dynamic array of strings that hold the lyrics,
the artist, and the title.


How reading in the file works:

A songNode is created for each song. The lyrics are added one by one to the 
vector of strings in the songNode. Each word is hashed in alpha only format
to the wordTable. When a word is added to the wordtable, the array of
WordNodes at each position is sorted so that the top 10 WordNodes are always
for the songs with the highest frequency of that word.

How searching for a word works:

The query is changed to be alpha only and is then hashed on the wordTable.
The top ten wordNodes for that song are then moved through. The locations of
songs are pulled from each word node and the lyrics of each song are linearly
searched for the alpha only word. Every time the alpha only word appears
it is printed along with the five words in front of and behind it.


