#include <iostream>
#include "SpeakerView.h"

int main(int argc, char* argv[]) {
  try {
        string inputFileName = argv[1];

        SpeakerView SpeakerView(inputFileName);
    }
    catch(runtime_error &excpt) {
        cerr << excpt.what() << endl;
        return -1;
    }
}