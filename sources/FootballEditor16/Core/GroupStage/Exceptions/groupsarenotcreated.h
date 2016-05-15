#ifndef GROUPSARENOTCREATED
#define GROUPSARENOTCREATED

#include "exception"

class GroupsAreNotCreated: public std::exception
{
public:
    const char * what() { return "Groups are not created yet!"; }
};

#endif // GROUPSARENOTCREATED

