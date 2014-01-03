//Marisa Reddy
//mpr2zp
//21 October 2013
//Filename: hashTable.h


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;

//class List;

class HashTable {

 public:
  HashTable( int x ); //Constructor, initialize table of size x
  ~HashTable(); //Destructor
  int hash( string s ); //hash function
  void insert( string word ); //insert items into HashTable
  void insertFile( string filename );
  int fileSize(string filename);
  bool find( string word ); //find a given string
  bool checkprime( int nn );
  bool checkforlargeprime( int num );
  int getNextPrimeNumber( int num );

 private:
  vector<vector<string> > * table; //HashTable is a vector of vectors 
  int size;
};

#endif
