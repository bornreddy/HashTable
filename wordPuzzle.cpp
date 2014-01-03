/*Marisa Reddy
 *mpr2zp
 *21 October 2013
 *Filename: wordPuzzle.cpp
 */

//Running Time: Theta(r*c*n) where r = #rows in grid, c = #columns in grid, and n = #words in dictionary.                                                                                                                       

#include <iostream>
#include "hashTable.h"
#include <fstream>
#include <string>
#include "timer.h"
#include <stdlib.h>
using namespace std;

class HashTable;


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


#define MAXROWS 500
#define MAXCOLS 500
char table[MAXROWS][MAXCOLS];


bool readInTable (string filename, int &rows, int &cols);
char* getWordInTable (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols);


int main( int argc, char* argv[] ) {
  if (argc == 3) {
    HashTable m(fileSize(argv[1]));
    m.insertFile( argv[1] );
    int r;
    int c;
    int words_total = 0;
    readInTable( argv[2], r, c );
    timer ti;    
    ti.start();
    for (int row=0; row<r; row++){
      for (int col=0; col<c; col++){
	for (int d=0; d<8; d++){
	  for (int len=3; len<24; len++) {
	    char* cs = getWordInTable(row,col,d,len,r,c);	       
	    if ((cs[0] != '\0') && (strlen(cs) == len) && (m.find(string(cs)))) {
	      string dstir = "";
	      if ( d == 0) dstir = "N " ;
	      if ( d == 1) dstir = "NE" ;
	      if ( d == 2) dstir = "E " ;
	      if ( d == 3) dstir = "SE" ;
	      if ( d == 4) dstir = "S " ;
	      if ( d == 5) dstir = "SW" ;
	      if ( d == 6) dstir = "W " ;
	      if ( d == 7) dstir = "NW" ;	      
	      cout << dstir  << "(" << row << ", " << col << "):\t" <<cs << endl;
	      words_total++;
	    }   
	  }
	}
      }
    }
    ti.stop();
    int final = ti.getTime();
    cout << "total words found was: " << words_total << endl;
    //    cout << "total time was: " << ti.getTime() << " seconds" << endl;
    cout << (int)(1000*ti.getTime())  << endl;
  }
  else {
    cout << "expected 2 command line parameters" << endl;
  }
  return 0;
}

/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global table[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columnss as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInTable (string filename, int &rows, int &cols) {
  string line;
  ifstream file(filename.c_str());
  if ( !file.is_open() )
    return false;
  file >> rows;
  getline (file,line); 
  file >> cols;
  getline (file,line); 
  getline (file,line);
  file.close();
  int pos = 0; 
  for ( int r = 0; r < rows; r++ ) {
    for ( int c = 0; c < cols; c++ ) {
      table[r][c] = line[pos++];
    }
  }
  return true;
}

/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char table[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static char[][] variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A char* containing the letters in the provided direction
 *         (NOTE: it is returned in a static char array).
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The length of the string to return (assuming the edge of
 *            the grid is not reached).
 * @param numRows The number of rows in the global char table[][]
 *                array .
 * @param numCols The number of columns in the global char table[][]
 *                array.
 */
char* getWordInTable (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
  static char output[256];
  if ( len >= 255 )
    len = 255;
  int pos = 0, r = startRow, c = startCol;
  for ( int i = 0; i < len; i++ ) {
    if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
      break;
    output[pos++] = table[r][c];
    switch (dir) { 
    case 0:
      r--;
      break;
    case 1:
      r--;
      c++;
      break;
    case 2:
      c++;
      break;
    case 3:
      r++;
      c++;
      break;
    case 4:
      r++;
      break;
    case 5:
      r++;
      c--;
      break;
    case 6:
      c--;
      break;
    case 7:
      r--;
      c--;
      break;
    }
  }
  output[pos] = 0;
  return output;
}
