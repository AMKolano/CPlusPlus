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
    virtual void move(); //for dynamic dispatch
    Particle(char Symbol, double Speed, double Position);
    Particle();
    Particle& operator = (const Particle& rhs);


protected: //coz using subclasses
    char Symbol;
    double Speed;
    double Position;

};



class  MagicParticle: public Particle {
public:
    MagicParticle() : Particle() {}
    MagicParticle(char Symbol, double Speed, double Position) : Particle(Symbol, Speed, Position){}

    virtual void move();//only move will change so we need to say it, for dynamic dispatch we need to have the virtual
};


#endif

