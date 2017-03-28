#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;

//using sdt::cout; using std::endl;
struct Particle {
    char Symbol;
    double Speed;
    double Position;
};
void initialize(Particle* , char , double, double);
void draw(const Particle*, char[]);
void move(Particle*);
void printScreen(const int, char[]);
void clearScreen(const int, char[]);


/*
struct Particle {
    char Symbol;
    double Speed;
    double Position;
};  
*/

int main() {
    const int npart = 3;
    
    Particle ps[npart];
    initialize(&ps[0],'V',4, 1 );
    initialize(&ps[1],'X',3, 1 );
    initialize(&ps[2],'O',4.6, 2 );

    int timeStep = 0;
    const int stopTime = 60;
    const int screenSize =  maxColumn - minColumn + 1; 
    char* screen = new char[screenSize]; // dynamically allocate the memory


 

    while (timeStep < stopTime) { 
        clearScreen(screenSize, screen);// put blank spaces before each entry
        for (int i=0; i < npart; i++) {

        draw(&ps[i], screen);//add arguments
        move(&ps[i]); 
        }
        printScreen(screenSize, screen);
        timeStep++;
  }
    delete [] screen; // delete memory used
}

void initialize(Particle* ps, char Symbol, double Speed, double Position ){
    ps->Symbol = Symbol;
    ps->Speed = Speed;
    ps->Position = Position;
  
 


}


void draw(const Particle* ps, char screen[]){ //ref & here saves memory, but cant draw const particles now, const Particle does not allow to change it
     screen[static_cast<int>(ps->Position)] = ps->Symbol; 
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

void move(Particle* ps){
 ps->Position += ps->Speed;

   if (ps->Position >= maxColumn) {
      ps->Position = maxColumn;
      ps->Speed = -ps->Speed;
    } else if (ps->Position < minColumn) {
     ps->Position = minColumn;
      ps->Speed = -ps->Speed;
    }

}










