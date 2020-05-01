/*                                                                                                  
 * File:   example1.cc                                                                         
 * Author: Ojashwi Gorkhaly                                                                        
 * Email:  ojashwi.gorkhaly@utdallas.edu                                                           
 *                                                                                                 
 *  This program will create the matrix and call the function to print out the values    
 */
#include <iostream>
#include "cdk.h"
#include <fstream>
#include <cstring> 
#include "header.h"

#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 15
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

//function prototype
void binaryHeader(CDKMATRIX *);

int main()
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_WIDTH+1] = {"0", "a", "b", "c", "d", "e"};
  const char 		*columnTitles[MATRIX_HEIGHT+1] = {"0", "a", "b", "c"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT,
			  MATRIX_NAME_STRING, (char **) columnTitles, (char **) rowTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  /*
   * Dipslay a message
   */
  binaryHeader(myMatrix); 
  drawCDKMatrix(myMatrix, true);    /* required  */

  cin.get();


  // Cleanup screen
  endCDK();
}
