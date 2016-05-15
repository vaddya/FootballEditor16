#ifndef WRONGID
#define WRONGID

#include "exception"

class WrongID: public std::exception
{
public:
    WrongID(int number): wrongID(number) {}
    int getWrongID() const { return wrongID; }
    const char * what() { return "ID is illeagal!"; }
private:
    int wrongID;
};

#endif // WRONGID

