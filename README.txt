Name: Kaye Galang
ID: 2429149
Course: CPSC 350
Assignment: Do You See What I See
Files: "input.txt", "main.cpp", "MonoStack.h", "SpeakerView.cpp", "SpeakerView.h"
How to Run: 
- g++ *.cpp
- ./a.out input.txt
Sources:
- istringstream: https://cplusplus.com/reference/sstream/istringstream/
Description: This project involves developing a C++ program that simulates a seating arrangement at an event where shorter audience members may have obstructed views of a celebrity speaker. The seating is arranged in an N x P grid, and the program must determine how many people in each column have an unobstructed view based on their height.

The solution uses a monotonic stack (a stack where elements appear in strictly increasing or decreasing order) to evaluate the heights of people seated in each column. A class called MonoStack is implemented to manage the stack, which ensures efficient height comparisons as the program processes each column of the seating arrangement.

The input is provided through a text file containing the heights of audience members in each seat, along with start and end markers. The program reads this file, processes the heights using the monotonic stack, and outputs the number of people in each column who have a clear view, along with their heights.

The class SpeakerView is responsible for reading the input file and generating the output. The output is displayed in a clear format, showing how many people in each column can see the speaker and their respective heights.
