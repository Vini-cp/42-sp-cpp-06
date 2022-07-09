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

struct FakeData
{
    FakeData( void );

    double mFirstDouble;
    char mChar;
    double mSedcondDouble;
    int mValue;
};

std::ostream& operator<<( std::ostream& os, const Data& prData );
std::ostream& operator<<( std::ostream& os, const FakeData& prFakeData );

uintptr_t serialize( Data* ptr );
Data* deserialize( uintptr_t raw );
FakeData* fakeDeserialize( uintptr_t raw );

#endif
