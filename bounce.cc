#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;



void draw(const int, const char, char[]);
void move(double&, double&);
void printScreen(const int, char[]);
void clearScreen(const int, char[]);


int main() {
    const int npart = 3;
    double Speed[npart] = {5, 6.3, 2};
    double Position[npart] = {0, 1, 5};
    char Symbol[npart] = {'x', 'O' ,'v'};
    int timeStep = 0;
    const int stopTime = 60;
    const int screenSize =  maxColumn - minColumn + 1; 
    char screen[screenSize];


 

    while (timeStep < stopTime) { 
        clearScreen(screenSize, screen);// put blank spaces before each entry
        for (int i=0; i < npart; i++) {
        draw(Position[i], Symbol[i], screen);//add arguments
        move(Position[i], Speed[i]);
        }
        printScreen(screenSize, screen);
        timeStep++;
  }
}

void draw(int const particlePosition, char const particleSymbol, char screen[]){ //in draw we dont change pos
     screen[static_cast<int>(particlePosition)] = particleSymbol; //position is double so we need to cast it to int
}

void printScreen(const int screenSize, char screen[]){ 
    for (int i =0; i < screenSize; i++)
        std::cout << screen[i]; //dont clear the buffer here yet
    std::cout << std::endl; //clear buffer
}

void clearScreen(const int screenSize, char screen[]){ 
    for (int i = minColumn; i < screenSize; i++)
        screen[i] = ' '; //dont clear the buffer here yet
   
}

void move(double& particlePosition, double& particleSpeed){
 particlePosition += particleSpeed;

   if (particlePosition >= maxColumn) {
      particlePosition = maxColumn;
      particleSpeed = -particleSpeed;
    } else if (particlePosition < minColumn) {
      particlePosition = minColumn;
      particleSpeed = -particleSpeed;
    }

}










