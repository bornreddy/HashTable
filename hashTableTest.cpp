#include "hashTable.h"
#include <iostream>

int main() {
  HashTable h = HashTable(10);
  h.insert("marisa");
  if (h.find("marisa")) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
  return 0;
}
