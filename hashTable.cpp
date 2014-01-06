#include "hashtable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;


/* takes in file size, and creates a prime number size hashTable composed of vectors of vectors. */
HashTable::HashTable( int x ) {
  int f = getNextPrimeNumber(2*x);
  size = f;
  table = new vector<vector<string> >(f);
  for (int i = 0; i < size; i++) {
    table->push_back(vector<string>());
  }
}

/* destructor */
HashTable::~HashTable() {
  int s = table->size();
  table->erase(table->begin(), table->begin()+s-1);
  delete table;
}

/* hashing function - java's hashCode() */
int HashTable::hash( string s ) {
  long total = 0;
  int t = s.length();
  for (int i=0; i<t; i++) {
    total = total + s[i]*pow(37,i);    
  }
  return abs((int) total % size);
}

/* inserts word into correct the vector located at the
   hash of the string */
void HashTable::insert( string s ) {
  int h = hash(s);
  (*table)[h].push_back(s);
}

/* inserts each word of a file, where each word in that
   file is represented on a unique line */
void HashTable::insertFile( string filename ) {
  string line;
  ifstream file (filename.c_str());
  if (file.is_open())
    {
      while ( getline (file,line) )
        {
          this->insert(line);
        }
      file.close();
    }
}

/* performs a linear search on the vector located at the 
   hash of string s, searching for the matching string */
bool HashTable::find( string s ) {
  int h = hash(s);
  vector<vector<string> > l = *table;
  if (std::find(l[h].begin(), l[h].end(), s) != l[h].end() ) {
    return true;
  }
  return false;
}

/* checks if a number is prime */
bool HashTable::checkprime (int nn) {
  if (nn > 100) {
    return checkforlargeprime(nn);
  } else {
    int k=2;
    while (k < nn) {
      int sd = nn%k;
      if ( sd == 0) {
        return false;
      }
      k++;
    }
  }
  return true;
}

/* checks if a large nuber is prime */
bool HashTable::checkforlargeprime (int num) {
  if (num > 100) {
    int sss = ((int)(sqrt((double)num)))+1;
    int pn = 2;

    while (pn < sss) {
      if (num%pn == 0) {
        return false;
      }
      pn = getNextPrimeNumber(pn);
    }
    return true;
  } else {
    return false;
  }
}

/* gets the next prime number up from the provided int */
int HashTable::getNextPrimeNumber (int num) {
  int nam = num+1;
  bool das = true;
  while ( das == true ) {
    if (checkprime(nam))
      das = false;
    else
      nam = nam+1;
  }
  return nam;
}
