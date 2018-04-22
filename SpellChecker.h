//Shuo Zhang
//Functionality of the Spell Checker
//Restrictions: When a txt file that has no spelling errors is read, the program still prints out "Misspelled Words: "


#ifndef _SPELL_CHECKER_H_
#define _SPELL_CHECKER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "myHash.h"

using namespace std;

// SPELLCHECK CLASS
//
// ******************PUBLIC OPERATIONS*********************
// ifstream& getWord()      --> read words from the file that is being spell checked
// void checkWords()        --> checks to see if input file is valid, then calls readToSet, outputWords, and printToFile
// void readToHt()          --> reads dictionary and store each word into buckets in a hash table
// void readToSet()         --> reads from an input file, if a word is not already in a bucket of the dict hash table, inserts into a list of misspelled words
// void outputWords()       --> outputs words from the misspelled words set to the console
// void printToFile()       --> outputs words from the misspelled words set to a txt file

class SpellCheck {
public:
	ifstream& getWord(ifstream& infile, string& x);
	void checkWords(HashTable<string> x);
	void readToHt(ifstream &infile, HashTable<string> &x);
	void readToSet(ifstream &infile, HashTable<string> x, set<string> &misspelled);
	void outputWords(set<string> misspelled);
	void printToFile(fstream &fout, set<string> misspelled);
};
#endif
