//Particle class
#ifndef Particle_hh
#define Particle_hh

#include "Screen.hh"// no need to inlcude whole hader here, enough to say


class Screen;
extern const int maxColumn;
extern const int minColumn;

class  Particle {
public:
    void draw(Screen& screen) const;
    void move();
    Particle(char Symbol, double Speed, double Position);
    Particle();
    Particle& operator = (const Particle& rhs);


private:
    char Symbol;
    double Speed;
    double Position;

};

#endif

