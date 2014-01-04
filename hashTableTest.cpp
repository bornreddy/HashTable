#include "hashTable.h"
#include <iostream>

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
  return count;
}


int main( int argc, char* argv[] ) {
  if (argc < 2) {
    cout << "filename expected" << endl;
    return 0;
  }
  int m = fileSize(argv[1]);
  HashTable h = HashTable(m);
  h.insertFile(argv[1]);
  cout << "inserted file"<< endl;
  h.insert("marisa");
  if (h.find("marisa")) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
  return 0;
}
