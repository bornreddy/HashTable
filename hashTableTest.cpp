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
  int m = fileSize(argv[1]);
  HashTable h = HashTable(m);
  h.insertFile(argv[1]);
  cout << "inserted file"<< endl;
  //  h.insert("marisa");
  /* if (h.find("marisa")) {
    cout << "true" << endl;
    } 
  else {
    cout << "false" << endl;
    } */
  /* bool go = true;
  while (go == true) {
    cout << "enter word to check: " << endl;
    string m;
    cin << m << endl;
    if (h.find(m)) {
      cout << m " is in the hashTable." << endl;
    }
    else {
      cout << m " is not in the hashTable." << endl;
    }
    
    }*/

  if (  h.find("10th") ) {
    cout << "true" << endl;
  }



  return 0;
}
