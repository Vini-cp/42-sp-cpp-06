// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef BASE_H
#define BASE_H

class Base
{

public:
    virtual ~Base() {};
};

Base* generate( void );
void identify(Base* p);
void identify(Base& p);

#endif
