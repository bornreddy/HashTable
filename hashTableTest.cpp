#include "hashTable.h"
#include <iostream>
#include <string>

int fileSize( string filename) {
  int count = 0;
  string line;
  ifstream file (filename.c_str());
  if (file.is_open())
    {
      while ( getline (file,line) )
        {
          count++;
        }
      file.close();
    }
  else {
    cout << "could not open file" << endl;
  }
  return count;
  
}



int main( int argc, char* argv[] ) {
  if (argc < 3) {
    cout << "filename expected" << endl;
    return 0;
  }
  int count = 0;
  string line;
  ifstream file (filename.c_str());
  if (file.is_open())
    {
      while ( getline (file,line) )
        {
          count++;
	}
      file.close();
    }
  else {
    cout << "could not open file" << endl;
    return 0;
  }
  int m = count;
  HashTable h = HashTable(m);
  h.insertFile(argv[1]);
  cout << "inserted contents of file into hashTable" << endl;
  string target;
  cout << "enter target word: " << endl;
  cin >> target;
  if (  h.find(target) ) {
    cout << "true" << endl;
  }
  else {
    cout << "could not find " + target + " in hashTable" << endl;
  }
  return 0;
}
