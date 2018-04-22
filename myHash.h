//Shuo Zhang
//Member functions and data members for 
//the hash table
//Restrictions: None

#ifndef _MY_HASH_H_
#define _MY_HASH_H_

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<list>

using namespace std;

template<typename HashedObj>
class HashTable
{
	// CONSTRUCTION: an default size of 10301
	//
	// ******************PUBLIC OPERATIONS*********************
	// bool insert( x )       --> Insert x
	// bool remove( x )       --> Remove x
	// bool contains( x )     --> Return true if x is present
	// void makeEmpty( )      --> Remove all items
public:
	explicit HashTable(int Bsize = 10301)
	{
		numBuckets = Bsize;
		currSize = 0;
		table.resize(Bsize);

		for (size_t i = 0; i < table.size(); i++)
		{
			table[i].clear();
		}
	};
	bool insert(const HashedObj& x);
	bool remove(const HashedObj& x);
	bool contains(const HashedObj& x) const;
	void makeEmpty();
	
private:
	vector<list<HashedObj>> table; //the array of buckets holding lists
	int numBuckets;
	int currSize;
	size_t hashing(const HashedObj &x) const; ////Default hash function for HashedObj 
};
template<>
class hash<string>
{
	//hash function for strings
public:
	size_t operator()(const string &key)
	{
		size_t hashVal = 0;
		for (char ch : key)
			hashVal = hashVal * 37 + ch;
		return  hashVal;
	}
};

// Insert a value into the hash table based on the location
// given by the hash function
template<typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &x)
{
	auto & whichList = table[hashing(x)];
	if (find(begin(whichList), end(whichList), x) != end(whichList))
		return false;
	whichList.push_back(x);
	return true;
}

// Checks to see if a value is in the hash table based on its location
// given by the hash function
template<typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj &x) const
{
	auto & whichList = table[hashing(x)];
	return find(begin(whichList), end(whichList), x) != end(whichList);
}

// Remove a value from the hash table based on its
// location given by the hash function
template<typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj &x)
{
	auto &whichList = table[hashing(x)];
	auto itr = find(begin(whichList), end(whichList), x) != end(whichList);
	if (itr == end(whichList))
		return false;
	whichList.erase(itr);
	--currSize;
	return true;
}

//tear it all down
template<typename HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
	for (auto & whichList : HashTable)
		whichList.clear();
}

// Call the hash class and mod it based on the size of the hash table
template<typename HashedObj>
size_t HashTable<HashedObj>::hashing(const HashedObj &x) const
{
	static hash<HashedObj> hf;
	return hf(x) % table.size();
}

#endif