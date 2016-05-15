#ifndef GROUPSTAGEISNOTOVER
#define GROUPSTAGEISNOTOVER

#include "exception"

class GroupStageIsNotOver: public std::exception
{
public:
    const char * what() { return "Group Stage isn't over!"; }
};

#endif // GROUPSTAGEISNOTOVER

