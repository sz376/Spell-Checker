//Shuo Zhang
//This program takes provided dictionary file and creates a hash table, filling each bucket with a word.
//The program then spell checks a user submitted text file by reading each word in the text file and looking each
//word up in the hash table that represents the dictionary.All words not found in the dictionary(hash table)
//are considered misspelled.
//Restrictions: None

#include "myHash.h"
#include "SpellChecker.h"

using namespace std;

int main()
{
	SpellCheck s;
	ifstream fin;
	HashTable<string> dict;

	s.readToHt(fin, dict);
	s.checkWords(dict);

	return 0;
}