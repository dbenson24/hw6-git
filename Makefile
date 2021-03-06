#
# Makefile for SongSearch, Assignment 6
#
CXX = clang++
FLAGS = -Wall -g3

songsearch: hashfunc.cpp hashfunc.h main.cpp SongNode.cpp SongNode.h SongTable.cpp SongTable.h WordList.cpp WordList.h WordNode.cpp WordNode.h WordTable.cpp WordTable.h
	${CXX} ${FLAGS} -o songsearch hashfunc.cpp main.cpp SongNode.cpp SongTable.cpp WordList.cpp WordNode.cpp WordTable.cpp
	
clean:
	rm -f songsearch

provide_design:
	provide comp15 hw6_design songsearch_design.txt

provide:
	provide comp15 hw6 hashfunc.cpp hashfunc.h main.cpp SongNode.cpp SongNode.h SongTable.cpp SongTable.h WordList.cpp WordList.h WordNode.cpp WordNode.h WordTable.cpp WordTable.h ReadMe.md Makefile

