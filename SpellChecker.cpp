#include "SpellChecker.h"


ifstream& SpellCheck::getWord(ifstream& fin, string& x)
{
	char c;
	x = "";		  // clear the string of characters

	while (fin.get(c) && !isalpha(c))
		;		  // do nothing. just ignore c

				  // return on end-of-file
	if (fin.eof())
		return fin;

	// record first letter of the word
	x += tolower(c);

	// collect letters and digits
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		x += tolower(c);

	return fin;
}

void SpellCheck::checkWords(HashTable<string> x)
{
	ifstream fin;
	fstream fout;
	string infileName = "";
	set<string> misspelled;

	cout << "Enter the document name that contains the file to be spell-checked: ";
	cin >> infileName;

	fin.open(infileName, fstream::in); 
	if (fin.fail()) //check if it is a valid file
	{
		cout << "Cannot open file!" << endl;
		exit(1);
	}
	//begin spell checking
	readToSet(fin, x, misspelled);
	outputWords(misspelled);
	printToFile(fout, misspelled);
}

void SpellCheck::readToHt(ifstream &fin, HashTable<string> &x)
{

	string infileName = "dict.dat";
	string currWord;

	fin.open(infileName, fstream::in);
	if (fin.fail()) //checks if dictionary file is valid
	{
		cout << "Cannot open dictionary file!";
		exit(1);
	}

	while (!fin.eof())
	{
		getWord(fin, currWord); //reads dictionary file
		x.insert(currWord); //creates a hash table of words and inserts each word from the dictionary into each bucket
	}
	fin.close();
}
//Checks the words of the input txt file against the table of dictionary words
void SpellCheck::readToSet(ifstream &fin, HashTable<string> x, set<string> &misspelled)
{
	string currWord;
	while (!fin.eof())
	{
		getWord(fin, currWord);
		if (!x.contains(currWord)) //checks against dictionary hash table
		{
			misspelled.insert(currWord); //dunks it into the misspelled words list
		}
	}
}

// Output the set of misspelled words to the console
void SpellCheck::outputWords(set<string> misspelled)
{
	if (misspelled.empty()) {
		cout << "Nothing is misspelled!" << endl;
	}
	else{
		cout << "Misspelled Words:" << endl;
		cout << endl;
		for (set<string>::iterator iter = misspelled.begin(); iter != misspelled.end(); iter++)
		{
			cout << *iter << endl;
		}
	}
}

// Outputs the set of misspelled words to a txt file
void SpellCheck::printToFile(fstream &fout, set<string> misspelled)
{
	string outfileName = "output.txt";
	fout.open(outfileName, fstream::out);
	if (misspelled.empty())
	{
		fout.close();
	}
	else {
		fout << "Misspelled Words:" << endl;
		fout << endl;
		for (set<string>::iterator iter = misspelled.begin(); iter != misspelled.end(); iter++)
		{
			fout << *iter << endl;
		}
		fout.close();
	}	
}


