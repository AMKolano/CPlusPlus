#include <iostream>

const int maxColumn = 80;
const int minColumn = 0;

void draw(double, char);//add parameters, types
void move(double, double);

int main() {
    char particleSymbol = 'x';
    double particlePosition = 0;
    double particleSpeed = 6.3;
    int timeStep = 0;
    int stopTime = 60;
 

    while (timeStep < stopTime) {
        draw(particlePosition, particleSymbol);//add arguments
        move(particlePosition, particleSpeed);
        timeStep++;
  }
}

void draw(double particlePosition, char particleSymbol){
    for (int i = minColumn; i < particlePosition; i++) {
         std::cout << " ";
    }
    std::cout << particleSymbol << std::endl;
   
}



void move(double particlePosition, double particleSpeed){
 particlePosition += particleSpeed;


   if (particlePosition >= maxColumn) {
      particlePosition = maxColumn;
      particleSpeed = -particleSpeed;
    } else if (particlePosition < minColumn) {
      particlePosition = minColumn;
      particleSpeed = -particleSpeed;
    }


}










