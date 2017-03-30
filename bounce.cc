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
    
    //asignement operator, cannot be const, Screen& so we dont copy unnesessairly
    Screen& operator = (Screen& rhs){
      if (this != &rhs){                   //self asignement check, are we talking bout the same object, this and rhs
      this->screenSize = rhs.screenSize; //copy size to new
                                         //before we asign new memory for buffer, we need to remove, that one that existed
      delete [] this-> buffer;                                   //  we deleted old buffer, but the poitner is still pointing
      this->buffer = new char[rhs.screenSize];//new buffer memory, and poin to it, with this buffer
      std::copy(rhs.buffer, rhs.buffer+rhs.screenSize, this->buffer); //copy everything from original buffer to the new one, one by one
      }  
      return *this; //this , pointer, we dereference it here, coz we return value
    //self asignement
    

    }


 
   ~Screen(){
        delete [] this->buffer;
     }
   //a[b] = 'd' //
   //    //operators, return by refernece char&
   //        //really there char& operator[](Screen *const this, const unsigned position){
   

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

