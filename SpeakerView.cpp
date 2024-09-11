#include "SpeakerView.h"

//default constructor
SpeakerView::SpeakerView() {
    myArray = nullptr;
    arrayCols = 0;
    arrayRows = 0;
}
//overloaded constructor that takes in a file name string
SpeakerView::SpeakerView(string inputFileName) {
    arrayCols = 0;
    arrayRows = 0;
    ReadFile(inputFileName);
    DisplayOutput();
}

//default destructor that deletes the array
SpeakerView::~SpeakerView() {
    for(int i = 0; i < arrayRows; ++i) {
        delete[] myArray[i];
    }
    delete[] myArray;
}

//function that reads the file that sets the rows and cols of the array and initializes the array
void SpeakerView::ReadFile(string inputFileName) {
    ifstream infile(inputFileName);
    //check if does not exist and if so, throw error
    if (!infile.good()) {
        throw runtime_error("file does not exist");
    }

    SetRowsAndCols(infile);
    //now we know the rows and cols of our array and we can declare and initialize it
    DeclareAndInitializeArray(infile);
}

void SpeakerView::DeclareAndInitializeArray(ifstream &infile)
{
    myArray = new double *[arrayRows];
    // allocate memory for the 2D array
    for (int i = 0; i < arrayRows; ++i)
    {
        myArray[i] = new double[arrayCols];
    }

    int row = 0;
    string line;
    // read each line
    while (getline(infile, line))
    {
        int col = 0;
        istringstream iss(line); // put the line into a string
        double num;
        // goes through the string and puts the num into the array
        while (iss >> num)
        {
            myArray[row][col++] = num;
        }
        ++row;
    }
}

//std::__1::
void SpeakerView::SetRowsAndCols(ifstream &infile)
{
    string line;
    //read each line
    while (getline(infile, line)) {
        istringstream iss(line); //put the line into a string
        double num;
        int elementsInRow = 0;
        //goes through the string and counts how many elements there are
        while(iss >> num)
        {
            ++elementsInRow; //increment the number of elements in the line/row
        }

        //if we read the first row, the number of cols will be set to how many elements were in that row
        if(arrayCols == 0)
        {
            arrayCols = elementsInRow; ///set the arraycols to be the elements in the row
        }
        //if we're not in the first row, we will check if the other rows have the same number of elements, if not we throw an error
        else
        {
            if(elementsInRow != arrayCols)
            { //check if each line has the same number of elements
                cerr << "Error: Not all lines have the same number of elements." << endl;
                exit(EXIT_FAILURE); //exit with failure
            }
        }
        ++arrayRows; //increment the array's rows by 1
    }

    //reset file pointer to the beginning
    infile.clear();
    infile.seekg(0);
}

//aux function that prints out array to terminal
void SpeakerView::PrintArray() {
    for(int i = 0; i < arrayRows; ++i) {
        cout << endl;
        for(int j = 0; j < arrayCols; ++j) {
            cout << myArray[i][j] << " ";
        }
    }

    cout << endl;
}

//function that determines who can see given the column index
void SpeakerView::DetermineWhoCanSee(int column) {
    MonoStack<double> decreasingStack(64, 'd'); //create a decreasing monostack

    //go through each row of the column we are looking at and push the data into the decreasing stack
    for(int i = arrayRows - 1; i >= 0; --i) {
        decreasingStack.Push(myArray[i][column]);
    }

    //the number of people that can see is the same as the size of the stack
    int numThatCanSee = decreasingStack.GetSize();
    
    //if there is none that can see, we don't print the heights
    if(numThatCanSee <= 0) {
        cout << "In column " << column << " there are " << numThatCanSee << " that can see." << endl;
    }
    //if there is one that can see, we don't have to loop through the stack
    else if(numThatCanSee == 1) {
        cout << "In column " << column << " there are " << numThatCanSee << " that can see. Their heights are: " << decreasingStack.Pop() << " inches." << endl;
    }
    //if there's more than 1, we have to loop through the stack and Pop each one
    else {
        cout << "In column " << column << " there are " << numThatCanSee << " that can see. Their heights are: ";
        //while the stack is NOT empty we pop
        while(!decreasingStack.IsEmpty()) {
            cout << decreasingStack.Pop();
            //if we're not at the last element, we print a comma
            if(decreasingStack.GetSize() > 0) {
                cout << ", ";
            }
        }
        cout << " inches." << endl;
    }
}

//displays the 2D array and who can see in each column
void SpeakerView::DisplayOutput() {
    PrintArray();
    cout << endl;
    for(int i = 0; i < arrayCols; ++i) {
        DetermineWhoCanSee(i);
    }
}

