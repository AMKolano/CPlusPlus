//screen functions
#include <cstdlib>
#include <iostream>
#include "Screen.hh"


extern const int minColumn;

void Screen::printScreen(){
        for (size_t i =0; i < screenSize; i++)
            std::cout << this->buffer[i]; //dont clear the buffer here yet
            std::cout << std::endl; //clear buffer
}

void Screen::clearScreen(){
    for (size_t i = minColumn; i < screenSize; i++)
        buffer[i] = ' '; //dont clear the buffer here yet 
}

Screen::Screen(const Screen& origin) : screenSize(origin.screenSize), buffer(new char[this->screenSize]) {
        std::copy(origin.buffer, origin.buffer+screenSize, this->buffer);
        }

Screen::Screen(const size_t screenSize) : screenSize(screenSize), buffer(new char[screenSize]) {}

Screen& Screen::operator = (const Screen& rhs) {
    if (this != &rhs) {
      this->screenSize = rhs.screenSize;
      delete [] this->buffer;
      this->buffer = new char[rhs.screenSize];
      std::copy(rhs.buffer, rhs.buffer+rhs.screenSize, this->buffer);
      }
    return *this;
}

Screen::~Screen(){
    delete [] this->buffer;
}

char& Screen::operator[](const unsigned Position){
    return this->buffer[Position];
}


