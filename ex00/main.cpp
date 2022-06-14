#include "include/Conversion.h"

int	main( int argc, char **argv )
{
    if ( argc != 2 )
        return 0;

    Conversion lConversion( static_cast< std::string >( argv[ 1 ] ) );

    lConversion.Convert();
    lConversion.showResult();
    return 0;
}
