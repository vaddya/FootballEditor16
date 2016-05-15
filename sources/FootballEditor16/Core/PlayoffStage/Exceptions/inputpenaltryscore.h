#ifndef INPUTPENALTRYSCORE
#define INPUTPENALTRYSCORE

#include "exception"

class InputPenaltryScore: public std::exception
{
public:
    const char * what() { return "Input penaltry score"; }
};

#endif // INPUTPENALTRYSCORE

