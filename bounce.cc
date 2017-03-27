#include <iostream>


char particleSymbol = 'x';
double particlePosition = 0;
double particleSpeed = 6.3;
int maxColumn = 80;
int minColumn = 0;
int timeStep = 0;
int stopTime = 60;

void draw();
void move();

int main() {

  while (timeStep < stopTime) {
        draw();
        move();
        timeStep++;
  }
}

void draw(){
    for (int i = minColumn; i < particlePosition; i++) {
         std::cout << " ";
    }
    std::cout << particleSymbol << std::endl;
   
}



void move(){
 particlePosition += particleSpeed;


   if (particlePosition >= maxColumn) {
      particlePosition = maxColumn;
      particleSpeed = -particleSpeed;
    } else if (particlePosition < minColumn) {
      particlePosition = minColumn;
      particleSpeed = -particleSpeed;
    }


}










