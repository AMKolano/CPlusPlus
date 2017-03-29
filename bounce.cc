#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;
const int Size = (maxColumn - minColumn + 1);
//using sdt::cout; using std::endl;

//make a struct, normally in a header file
class  Screen{
public:

    void printScreen(){
        for (size_t i =0; i < screenSize; i++)
            std::cout << this->buffer[i]; //dont clear the buffer here yet
            std::cout << std::endl; //clear buffer
    }

    void clearScreen(){
        for (size_t i = minColumn; i < screenSize; i++)
            buffer[i] = ' '; //dont clear the buffer here yet 
    }

    Screen(const Screen& origin) : screenSize(origin.screenSize), buffer(new char[this->screenSize]) {
           std::copy(origin.buffer, origin.buffer+screenSize, this->buffer);
           }
    
    Screen(const size_t screenSize) : buffer(new char[screenSize]), screenSize(screenSize){} 

   ~Screen(){
        delete [] this->buffer;
     }


    void put(const char Symbol, unsigned Position){
        buffer[Position] = Symbol;
    }

private: // good practice put privite at the bottom
    size_t const screenSize; //fixed screen for now
    char * const buffer;

};


class  Particle {
public:       // has to be public, as by default class is privite
    char Symbol;
    double Speed;
    double Position;

    void draw(Screen& screen) const{ 
        screen.put(Symbol, Position);
    }

    void move(){
        Position += Speed;

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

int main() {
    const int npart = 3;
    
    Particle ps[npart];
    ps[0].initialize('V',4, 1 );
    ps[1].initialize('X',3, 1 );
    ps[2].initialize('O',4.6, 2 );

    int timeStep = 0;
    const int stopTime = 60;
    
   //Initialize screen
    Screen screen(Size);//IMPORTANT. CONSTRUCTOR==CTOR. initialize screen, and pass these arguments to the constructor., Function"screen" that lives in the class "Screen".
   //  Screen screen = Size;
 
    while (timeStep < stopTime) { 
        screen.clearScreen();// put blank spaces before each entry
        for (int i=0; i < npart; i++) {
        
        ps[i].draw(screen);
        ps[i].move(); 
        }
        screen.printScreen();
        timeStep++;
  }
//  screen.destroy(); 

}





































