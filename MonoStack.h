#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <iostream>
using namespace std;

template <typename T>
class MonoStack{
  public:
    //default constructor
    MonoStack() {
      maxSize = 64;
      top = -1;
      monoStack= new T[maxSize];
    }

    //overloaded constructor
    MonoStack(int maxSize, char o) {
      this->maxSize = maxSize;
      top = -1;
      monoStack = new T[maxSize];
      this->o = o;
    }

    //destructor
    ~MonoStack() {
      delete[] monoStack;
    }

    //core functions
    void Push(T data) {
      //check if monoStack is full and if so resize
      if(IsFull()) {
        cout << "Stack resizing to accomodate more data" << endl;
        T *temp = new T[2*maxSize];
        for (int i = 0; i < maxSize; ++i) {
          //copy data over to new array
          temp[i] = monoStack[i];
        }
        maxSize *= 2; //double the size
        delete[] monoStack; //garbage collect old array
        monoStack = temp; //copy the data from the previous stack being held in temp into the new stack
      }

      switch(o) {
        case 'i': //if char is i, use the push function for a decreasing monostack
          PushIncreasing(data);
          break;
        case 'd': //if char is d, use the push function for a increasing monostack
          PushDecreasing(data);
          break;
        default:
          cerr << "char is neither i or d, please choose between those two." << endl;
          exit(EXIT_FAILURE); //exit code with failure
      }
    }

    //push function that keeps stack in increasing order
    void PushIncreasing(T data) {
      if(IsEmpty() || Peek() < data) {
        monoStack[++top] = data;
      }
      else{
        T current = Peek(); //make current the data at the top of the stack
        //while current is more or equal to the data Pop() unless it's duplicate
        while(current >= data) {
        //if there is duplicate data, throw an error and exit code with failure
          if(current == data) {
            cerr << "Error: Duplicate values are not allowed in the stack" << endl;
            exit(EXIT_FAILURE); //exit code with failure
          }
          //pop off the top of the stack since it is more than the data
          Pop();
          //if empty, break out of the loop so Peek() is not called again
          if(IsEmpty()) {
            break;
          }
          //current is now the new top
          current = Peek();   
        }
        //we found where we need to push the data so we push
        monoStack[++top] = data;
      }
    }

    //push function that keeps stack in decreasing order
    void PushDecreasing(T data) {
      if(IsEmpty() || Peek() > data) {
        monoStack[++top] = data;
      }
      else{
        T current = Peek(); //make current the data at the top of the stack
        //while current is less or equal to the data Pop() unless it's duplicate
        while(current <= data) {
        //if there is duplicate data, throw an error and exit code with failure
          if(current == data) {
            cerr << "Error: Duplicate values are not allowed in the stack" << endl;
            exit(EXIT_FAILURE); //exit code with failure
          }
          //pop off the top of the stack since it is less than the data
          Pop();
          //if empty, break out of the loop so Peek() is not called again
          if(IsEmpty()) {
            break;
          }
          //current is now the new top
          current = Peek();   
        }
        //we found where we need to push the data so we push
        monoStack[++top] = data;
      }
    }

    //pop function that returns the top of the stack and takes it off the stack
    T Pop() {
      //if the stack is empty, throw an error
      if(IsEmpty()) {
        cerr << "Stack is empty" << endl;
      }

      //return the popped off data and then move the top to the next data
      return monoStack[top--];
    }

    //peek function that returns the top of the stack
    T Peek() {
      //if the stack is empty, throw an error
      if(IsEmpty()) {
        cerr << "Stack is empty" << endl;
      }

      return monoStack[top];
    }

    //aux functions
    bool IsFull() {
      return top == maxSize - 1;
    }

    bool IsEmpty() {
      return top == -1;
    }

    int GetSize() {
      return top + 1;
    }

    void PrintStack() {
      for(int i = 0; i < GetSize(); ++i) {
        cout << monoStack[i] << endl;
      }
    }
    
  private:
    T *monoStack; //pointer to stack
    int top; //top of stack
    int maxSize; //max size of stack
    char o; //char signifying increasing or decreasing mono stack
    
};

#endif