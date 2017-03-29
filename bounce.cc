#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;

//using sdt::cout; using std::endl;

//make a class'ish
struct Particle {
    char Symbol;
    double Speed;
    double Position;

    void draw(char screen[]) const{ // Const member function. it is not allowed to modifiy it . Pointer is const automatically.
       screen[static_cast<int>(Position)] = Symbol;
    }

    void move(){
        Position += Speed; //this-> no longer needed, compiler does it for u 

        if (Position >= maxColumn) {
        Position = maxColumn;
        Speed = -Speed;
        } else if (Position < minColumn) {
        Position = minColumn;
        Speed = -Speed;
        }
    }
    void initialize(char Symbol, double Speed, double Position ){
        this->Symbol = Symbol;//the smae names so here this-> is needed, or i change the name
        this->Speed = Speed;
        this->Position = Position;
    }
};


struct Screen{
    size_t screenSize;
    char* screen; 


    void printScreen(){ //equivalent to below 
        for (size_t i =0; i < screenSize; i++)
            std::cout << this->screen[i]; //dont clear the buffer here yet
            std::cout << std::endl; //clear buffer
    }

    void clearScreen(){
        for (size_t i = minColumn; i < screenSize; i++)
            screen[i] = ' '; //dont clear the buffer here yet 
    }


    void initializeScreen(const size_t screenSize){ //to keep it positive
        this->screen = new char [screenSize];
        this->screenSize = screenSize;


    }

};


int main() {
    const int npart = 3;
    
    Particle ps[npart];
    ps[0].initialize('V',4, 1 );
    ps[1].initialize('X',3, 1 );
    ps[2].initialize('O',4.6, 2 );

    int timeStep = 0;
    const int stopTime = 60;
    
   //Initialize screen
     Screen screen;//if anything is written here code, it will not work as screen is not initialized yet
     screen.initializeScreen(maxColumn - minColumn + 1);    
    
    while (timeStep < stopTime) { 
        screen.clearScreen();// put blank spaces before each entry
        for (int i=0; i < npart; i++) {
        //equivalent to the one below &ps[i]->draw(screen):   
        ps[i].draw(screen.screen);//magic happens and no longer need arguments here?
        ps[i].move(); 
        }
        screen.printScreen();
        timeStep++;
  }
   delete [] screen.screen; // delete memory used, delete only on buffer, second screen is in fact buffer
}





































