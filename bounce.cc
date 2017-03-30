#include <cstdlib>
#include <iostream>
#include "Particle.hh" // not standard library so "" and not < >
#include "Screen.hh"
#include <fstream>
#include <string>
#include <vector>

const int Size = (maxColumn - minColumn + 1);
//using sdt::cout; using std::endl;

int main() {

      
    std::string filename("data.txt");
    std::ifstream in(filename.c_str());// a problem at compilation
    if (!in){
        std::cerr << "Could not open file" << filename<<"." <<  std::endl;
    return EXIT_FAILURE;
    }
 
    
    size_t Np;
    in >> Np;
 
  
    const size_t  npart = Np;

    std::vector<Particle*> ps;//vector of type Particle  
   // Particle* ps = new Particle[npart]; // now dynamically assigned array, before Particle ps = [npart]
    
    for (size_t i=0; i < npart; ++i){

       char S;
       double v, pos;
       in >> S >> v >> pos;
     //   ps.push_back(new MagicParticle(S,v, pos));// we want to pass pointers for dynamicly allocated container
       //std::cout<<i <<std::endl;
      if(i%2)
        ps.push_back(new Particle(S,v, pos));
      else
        ps.push_back(new MagicParticle(S,v, pos));
     }
    in.close();
    
    int timeStep = 0;
    const int stopTime = 60;
    
   //Initialize screen
    Screen screen(Size);

    while (timeStep < stopTime) { 
        screen.clearScreen();
        for (size_t i=0; i < npart; i++) {
           ps[i]->draw(screen); // dots changeinto arrows coz we operate on pointers
           ps[i]->move(); 
           }
        screen.printScreen();
        timeStep++;
    }
    for (size_t i=0; i< ps.size(); ++i) //size belongs to vector class
        delete ps[i];
}

