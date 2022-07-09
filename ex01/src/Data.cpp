// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../include/Data.h"

//------------------------------------------------------------------------------

Data::Data( void ) :
    mInteger( 99 ),
    mChar( 'X' ),
    mFloat( 57.3 ),
    mString( "Data structure" )
{
}

//------------------------------------------------------------------------------

std::ostream& operator<<( std::ostream& os, const Data& prData )
{
    os << "Integer: " << prData.mInteger << std::endl
       << "Char:    " << prData.mChar << std::endl
       << "Float:   " << prData.mFloat << std::endl
       << "String:  " << prData.mString << std::endl;

    return os;
}

//------------------------------------------------------------------------------

FakeData::FakeData( void ) :
    mFirstDouble( 55.1 ),
    mChar( 'Z' ),
    mSedcondDouble( 9872.0217 ),
    mValue( 100 )
{
}

//------------------------------------------------------------------------------

std::ostream& operator<<( std::ostream& os, const FakeData& prFakeData )
{
    os << "Value:  " << prFakeData.mValue << std::endl
       << "Char:   " << prFakeData.mChar << std::endl
       << "First:  " << prFakeData.mFirstDouble << std::endl
       << "Second: " << prFakeData.mSedcondDouble << std::endl;

    return os;
}

//------------------------------------------------------------------------------

uintptr_t serialize( Data* ptr )
{
    return ( reinterpret_cast< uintptr_t >( ptr ) );
}

//------------------------------------------------------------------------------

Data* deserialize( uintptr_t raw )
{
    return ( reinterpret_cast< Data* >( raw ) );
}

//------------------------------------------------------------------------------

FakeData* fakeDeserialize( uintptr_t raw )
{
    return ( reinterpret_cast< FakeData* >( raw ) );
}

//------------------------------------------------------------------------------
