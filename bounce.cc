#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;



void draw(const int, const char, char[]);
void move(double&, double&);
void printScreen(const int, char[]);
void clearScreen(const int, char[]);

//one array of particle struct

struct Particle {
    char Symbol;
    double Speed;
    double Position;
};


int main() {
    const int npart = 3;
    
    Particle ps[npart] = {{'x', 5.6, 0 },{'O', 6.3, 2},{'V',4, 1 } };// make array ps of particles with symbol, speed and position, order kept as in struct

    int timeStep = 0;
    const int stopTime = 60;
    const int screenSize =  maxColumn - minColumn + 1; 
    char* screen = new char[screenSize]; // dynamically allocate the memory


 

    while (timeStep < stopTime) { 
        clearScreen(screenSize, screen);// put blank spaces before each entry
        for (int i=0; i < npart; i++) {
        draw(ps[i].Position, ps[i].Symbol, screen);//add arguments
        move(ps[i].Position, ps[i].Speed); //ps.Position[i], could not work coz ps is a pointer but struct is not, but if i access one of the particles ps, i can access stuff in there, hence ps[i].Position works, i acess particle nr i, then .Position acess its position
        }
        printScreen(screenSize, screen);
        timeStep++;
  }
    delete [] screen; // delete memory used
}

void draw(int const particlePosition, char const particleSymbol, char screen[]){ //in draw we dont change pos
     screen[static_cast<int>(particlePosition)] = particleSymbol; //position is double so we need to cast it to int
}

void printScreen(const int screenSize, char* screen){ //equivalent to below 
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










