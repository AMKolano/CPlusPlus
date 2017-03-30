//Implementation of Particle class
void Particle::draw(Screen& screen) const{
    screen[Position]=Symbol;
}

void Particle::move(){
    Position += Speed;

    if (Position >= maxColumn) {
    Position = maxColumn;
    Speed = -Speed;
    } else if (Position < minColumn) {
    Position = minColumn;
    Speed = -Speed;
    }
}

Particle::Particle(char Symbol, double Speed, double Position) : Symbol(Symbol), Speed(Speed), Position(Position){}
Particle::Particle() : Symbol('Z'), Speed(5), Position(2){}


Particle& Particle::operator = (const Particle& rhs){
    this->Symbol = rhs.Symbol;
    this->Position = rhs.Position;
    this->Speed = rhs.Speed;
    return *this; //its particle, without pointer its a pointer   
}


