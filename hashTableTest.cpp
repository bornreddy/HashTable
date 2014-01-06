#include "hashTable.h"
#include <iostream>
#include <string>

/* Program Description: This program takes in a file of words on unique lines as a command line parameter, inserts each word into a hashTable, and then prompts the user for a target word. It then checks to see if the target word is contained in the file. 
 */

int main( int argc, char* argv[] ) {
  //verify that a filename was provided
  if (argc < 2) {
    cout << "filename expected" << endl;
    return 0;
  }
  //get file size
  int count = 0;
  string line;
  cout << argv[1] << endl;
  string filename = argv[1];
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
  //create hashTable with adequate number of buckets (see constructor)
  HashTable h = HashTable(m);
  //insert file contents
  h.insertFile(argv[1]);
  cout << "inserted contents of file into hashTable" << endl;
  //get target word to check for in hashTable
  string target;
  cout << "enter target word: " << endl;
  cin >> target;
  if (  h.find(target) ) {
    cout << target + " is in file." << endl;
  }
  else {
    cout << "could not find " + target + " in file." << endl;
  }
  return 0;
}
