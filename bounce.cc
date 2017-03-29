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
    
    //a[b] = 'd' //
    //operators, return by refernece char&
    //really there char& operator[](Screen *const this, const unsigned position){
   
    Screen(const Screen& origin) : screenSize(origin.screenSize), buffer(new char[this->screenSize]) {
           std::copy(origin.buffer, origin.buffer+screenSize, this->buffer);
           }
    
    Screen(const size_t screenSize) : screenSize(screenSize), buffer(new char[screenSize]) {} 

   ~Screen(){
        delete [] this->buffer;
     }

   char& operator[](const unsigned Position){
        return this->buffer[Position];
   }
    //void put(const char Symbol, unsigned Position){
    //    buffer[Position] = Symbol;
   // }

private: // good practice put privite at the bottom
    size_t const screenSize; //fixed screen for now
    char * const buffer;

};


class  Particle {
public:   
    void draw(Screen& screen) const{ 
        screen[Position]=Symbol;
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

    Particle(char Symbol, double Speed, double Position) : Symbol(Symbol), Speed(Speed), Position(Position){}
    Particle() : Symbol('Z'), Speed(5), Position(2){}   //we overload our constructor overwritten by default one, in c++98 thats the only way

private:    
    char Symbol;
    double Speed;
    double Position;

};

int main() {
    const int npart = 3;
    
    Particle ps[npart];

    ps[0] = Particle('V',4, 1 );
    ps[1] = Particle('X',3, 1 );
    ps[2] = Particle('O',4.6, 2 );

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





































