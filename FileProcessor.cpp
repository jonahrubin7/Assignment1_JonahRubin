#include "FileProcessor.h" //connect to all the other classes
#include "Translator.h"
FileProcessor::FileProcessor(){ //constructor

}
FileProcessor::~FileProcessor(){ //destructor

}

void FileProcessor::processFile(string inputFile, string outputFile){ //create method that processes files
    string fileLine = ""; //variables
    Translator *ts = new Translator();  //pointer to new translator class

    inFS.open(inputFile); // open the input file
    outFS.open(outputFile);  // open the write to file

    if(!inFS.is_open()){ //if the file cant be opened
      cout<< "Oopsies, This file could not be open, try again with a better file";
      exit(1); //exit the program
    }
    while(!inFS.eof()){ //while the file isnt the end of the line
      inFS >> fileLine; //read from the file
      if(!inFS.fail()){ //if reading from the file doesnt fail
        outFS<< ts->translateEnglishSentance(fileLine); // endl; // translate each line and print it to a new file
      }

    }
    inFS.close(); //close both files
    outFS.close();
    delete ts; //delete instance of class Translator
}
