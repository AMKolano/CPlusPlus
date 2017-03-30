#include <cstdlib>
#include <iostream>
#include "Particle.hh" // not standard library so "" and not < >
#include "Screen.hh"
#include <fstream>
#include <string>


const int Size = (maxColumn - minColumn + 1);
//using sdt::cout; using std::endl;

int main() {

      
    std::string filename("data.txt");
    std::ifstream in(filename.c_str());// a problem at compilation
    if (!in)
    std::cerr << "Could not open file" << filename<<"." <<  std::endl;
    return EXIT_FAILURE;

 
    
    size_t Np;
    in >> Np;
  
    const int npart = Np; 
    Particle* ps = new Particle[npart]; // now dynamically assigned array, before Particle ps = [npart]
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

