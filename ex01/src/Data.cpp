// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../include/Data.h"

Data::Data( void ) :
    mInteger( 99 ),
    mChar( 'X' ),
    mFloat( 57.3 ),
    mString( "Data structure" )
{
}

std::ostream& operator<<( std::ostream& os, const Data& prData )
{
    os << "Integer: " << prData.mInteger << std::endl
       << "Char:    " << prData.mChar << std::endl
       << "Float:   " << prData.mFloat << std::endl
       << "String:  " << prData.mString << std::endl;

    return os;
}

uintptr_t serialize( Data* ptr )
{
    return ( reinterpret_cast< uintptr_t >( ptr ) );
}

Data* deserialize( uintptr_t raw )
{
    return ( reinterpret_cast< Data* >( raw ) );
}
