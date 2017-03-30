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
    
    Screen(const size_t screenSize) : screenSize(screenSize), buffer(new char[screenSize]) {} 
  
     Screen& operator = (const Screen& rhs) {
    if (this != &rhs) {
      this->screenSize = rhs.screenSize;
      delete [] this->buffer;
      this->buffer = new char[rhs.screenSize];
      std::copy(rhs.buffer, rhs.buffer+rhs.screenSize, this->buffer);
      }
    return *this;

   }
  
/*
   //swap function
   Screen& operator = (Screen rhs){
     this->swap(rhs);
     return *this;
    }

   void swap(Screen& other){
    std::swap(this->screenSize, other.screenSize);//standard library swap
    std::swap(this->buffer, other.buffer);
    }

 */
   ~Screen(){
        delete [] this->buffer;
     }
 
   

   char& operator[](const unsigned Position){
        return this->buffer[Position];
   }

 
private: // good practice put privite at the bottom
    size_t screenSize; //fixed screen for now
    char * buffer;

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
    Particle() : Symbol('Z'), Speed(5), Position(2){}


    Particle& operator = (const Particle& rhs){
       this->Symbol = rhs.Symbol;
       this->Position = rhs.Position;
       this->Speed = rhs.Speed;
       return *this; //its particle, without pointer its a pointer   
       } 
 

private:    
    char Symbol;
    double Speed;
    double Position;

};

int main() {
    const int npart = 3;
    
    Particle ps[npart];
    ps[0] = Particle('V',4, 1 );  // type of ps[0] is Particle; signature operator = this parm
    ps[1] = Particle('X',3, 1 );
    ps[2] = Particle('O',4.6, 2 );

    int timeStep = 0;
    const int stopTime = 60;
    
   //Initialize screen
    Screen screen(Size);
    while (timeStep < stopTime) { 
        screen.clearScreen();// put blank spaces before each entry
        for (int i=0; i < npart; i++) {
           ps[i].draw(screen);
           ps[i].move(); 
           }
        screen.printScreen();
        timeStep++;
  }

}

