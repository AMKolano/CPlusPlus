//Particle class
#ifdef Particle_hh
#define Particle_hh

#include "Screen.hh"

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

