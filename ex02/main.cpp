// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "include/Base.h"

int main ( void )
{
    Base* lBase = generate();

    identify( lBase );
    identify( &( *lBase ) );
    delete lBase; 
}
