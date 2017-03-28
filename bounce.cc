#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;
const int screenSize =  maxColumn - minColumn + 1;  //c++ runs const int array size,we want particle to run between 0 and 80, compiler does not recognize the error if only 80 is left, we start to access memory outside boundries, (where we update screen size with value 80, giving  the array 81 spaces 
char screen[screenSize];

void draw(const int, const char);//add parameters, types
void move(double&, double&);
void printScreen();
void clearScreen();


int main() {
    const int npart = 3;
    double Speed[npart] = {5, 6.3, 2};
    double Position[npart] = {0, 1, 5};
    char Symbol[npart] = {'x', 'O' ,'v'};
    int timeStep = 0;
    const int stopTime = 60;
 

    while (timeStep < stopTime) { 
        clearScreen();// put blank spaces before each entry
        for (int i=0; i < npart; i++) {
        draw(Position[i], Symbol[i]);//add arguments
        move(Position[i], Speed[i]);
        }
        printScreen();
        timeStep++;
  }
}

void draw(int const particlePosition, char const particleSymbol){ //in draw we dont change pos
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










