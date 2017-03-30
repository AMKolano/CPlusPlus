//Screen class
#ifndef Screen_hh
#define Screen_hh


class  Screen{
public:

    void printScreen();

    void clearScreen();

    Screen(const Screen& origin);

    Screen(const size_t screenSize);

    Screen& operator = (const Screen& rhs);
   ~Screen();
   char& operator[](const unsigned);

private: // good practice put privite at the bottom
    size_t screenSize; //fixed screen for now
    char * buffer;

};
#endif
