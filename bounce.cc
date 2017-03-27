#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;
const int screenSize =  maxColumn - minColumn;  //c++ runs const int array size
char screen[screenSize];

void draw(const double, const char);//add parameters, types
void move(double&, double&);
void printScreen();
void clearScreen();


int main() {
    const char particleSymbol = 'x';
    double particlePosition = 0;
    double particleSpeed = 6.3;
    int timeStep = 0;
    const int stopTime = 60;
 

    while (timeStep < stopTime) { 
        clearScreen();// put blank spaces before each entry
        draw(particlePosition, particleSymbol);//add arguments
        move(particlePosition, particleSpeed);
        printScreen();
        timeStep++;
  }
}

void draw(double const particlePosition, char const particleSymbol){ //in draw we dont change pos
     screen[static_cast<int>(particlePosition)] = particleSymbol; //position is double so we need to cast it to int
}

void printScreen(){
    for (int i =0; i < screenSize; i++)
        std::cout << screen[i]; //dont clear the buffer here yet
    std::cout << std::endl; //clear buffer
}

void clearScreen(){
    for (int i = minColumn; i < screenSize; i++)
        screen[i]= ' '; //dont clear the buffer here yet
   
}

void move(double& particlePosition, double& particleSpeed){
 particlePosition += particleSpeed;

//we want to change the position, so we want to retrieve it by reference "&"n from the original and not copy, characters yes if large
//speed changes when we go back
   if (particlePosition >= maxColumn) {
      particlePosition = maxColumn;
      particleSpeed = -particleSpeed;
    } else if (particlePosition < minColumn) {
      particlePosition = minColumn;
      particleSpeed = -particleSpeed;
    }


}










