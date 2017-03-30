#include <cstdlib>
#include <iostream>
#include "Particle.hh" // not standard library so "" and not < >
#include "Screen.hh"




const int Size = (maxColumn - minColumn + 1);
//using sdt::cout; using std::endl;

int main() {
    const int npart = 3;
    
    Particle ps[npart];
    ps[0] = Particle('V',4, 1 );  
    ps[1] = Particle('X',3, 1 );
    ps[2] = Particle('O',4.6, 2 );

    int timeStep = 0;
    const int stopTime = 60;
    
   //Initialize screen
    Screen screen(Size);
    while (timeStep < stopTime) { 
        screen.clearScreen();
        for (int i=0; i < npart; i++) {
           ps[i].draw(screen);
           ps[i].move(); 
           }
        screen.printScreen();
        timeStep++;
  }

}

