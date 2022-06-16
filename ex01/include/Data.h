// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <stdint.h>

struct Data
{
    Data( void );

    int mInteger;
    char mChar;
    float mFloat;
    std::string mString;
};

std::ostream& operator<<( std::ostream& os, const Data& prData );
uintptr_t serialize( Data* ptr );
Data* deserialize( uintptr_t raw );

#endif
