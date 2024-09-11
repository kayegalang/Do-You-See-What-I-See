#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "MonoStack.h"
#include <fstream>
#include <sstream>

class SpeakerView{
    public:
        SpeakerView(); //default constructor
        SpeakerView(string inputFileName); //overloaded constructor
        ~SpeakerView(); //destructor

        //main functions
        void DetermineWhoCanSee(int column); //function to print out who is able to see in which column
        void ReadFile(string inputFileName); // function to read the file and store into a 2D array
        void DeclareAndInitializeArray(ifstream &infile);
        void SetRowsAndCols(ifstream &infile); // function to set the row and cols of 2D array based on input
        void DisplayOutput();                  // function to display descriptive output to terminal

        //aux functions
        void PrintArray(); //function to print the 2D array

    private:
        double **myArray; //2D array storing the heights

        int arrayRows;
        int arrayCols;
};

#endif