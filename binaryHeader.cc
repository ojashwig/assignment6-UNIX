/*
 * File:   binaryHeader.cc
 * Author: Ojashwi Gorkhaly
 * Email:  ojashwi.gorkhaly@utdallas.edu
 *
 *  This program will read the file and take in the inputs. Then it will print it to the matrix
 */


#include "header.h"

class BinaryHeaderFile{
public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};

const int maxRecordStringLength = 25;

class BinaryFileRecord {
public:
  uint8_t strLength;
  char    stringBuffer[maxRecordStringLength];
};

//takes in the matrix from the main file
void binaryHeader(CDKMATRIX* myMatrix){
  
  ifstream binInfile; //creating the file that will have the input

  BinaryHeaderFile* myHeader = new BinaryHeaderFile();
  BinaryFileRecord* myRecord = new BinaryFileRecord();

  //opening and reading the file
  binInfile.open("/scratch/perkins/cs3377.bin", ios::in|ios::binary);
  binInfile.read((char*) myHeader, sizeof(BinaryHeaderFile));

  stringstream convert;
  string val;

  //print out the magic number in uppercase
  convert << "Magic: 0x" << hex << uppercase <<  myHeader->magicNumber;
  val = convert.str();
  setCDKMatrixCell(myMatrix,1,1,val.c_str());
  convert.str(""); //clearning the string
  
  convert << "Version: " << dec << myHeader->versionNumber;
  val = convert.str();
  setCDKMatrixCell(myMatrix,1,2,val.c_str());
  convert.clear();
  
  //printing the number of records
  convert.str(string());
  convert << "NumRecords: " << myHeader->numRecords;
  val = convert.str();
  setCDKMatrixCell(myMatrix,1,3, val.c_str());
  convert.clear();

  //a for loop to print until it reachs the height
  for(int i = 2; i <= 5; i++){
    if(!binInfile.eof()){//keeps going until it reaches the end of the file
      binInfile.read((char*) myRecord, sizeof(BinaryFileRecord));
      convert.str("");
      convert << "strlen: " << strlen(myRecord->stringBuffer);
      val = convert.str();
      setCDKMatrixCell(myMatrix, i, 1, val.c_str());
      setCDKMatrixCell(myMatrix, i, 2, myRecord->stringBuffer);
    }
  }
  binInfile.close(); //closes the file
}
