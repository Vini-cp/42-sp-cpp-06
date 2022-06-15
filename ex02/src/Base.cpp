// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../include/A.h"
#include "../include/B.h"
#include "../include/C.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

Base* generate( void )
{
    srand ( time(NULL) );
    int lRandomClassNumber = rand() % 3;

    if ( lRandomClassNumber == 0 )
    {
        return ( dynamic_cast< Base* >( new A() ) );
    }
    else if ( lRandomClassNumber == 1 )
    {
        return ( dynamic_cast< Base* >( new B() ) );
    }
    else
    {
        return ( dynamic_cast< Base* >( new C() ) );
    }
}

void identify( Base* p )
{
    Base* lBaseA = dynamic_cast< A* >( p );
    
    if ( lBaseA != NULL )
    {
        std::cout << "A" << std::endl;
        return;
    }

    Base* lBaseB = dynamic_cast< B* >( p );
    
    if ( lBaseB != NULL )
    {
        std::cout << "B" << std::endl;
        return;
    }

    Base* lBaseC = dynamic_cast< C* >( p );
    
    if ( lBaseC != NULL )
    {
        std::cout << "C" << std::endl;
        return;
    }
}

void identify( Base& p )
{
    bool exceptionCaught = false;

    try
    {
        dynamic_cast< A& >( p );
    }
    catch( const std::bad_cast& e )
    {
        exceptionCaught = true;
    }

    if ( !exceptionCaught )
    {
        std::cout << "A" << std::endl;
        return ;
    }
    
    exceptionCaught = false;
    
    try
    {
        dynamic_cast< B& >( p );
    }
    catch(const std::bad_cast& e )
    {
        exceptionCaught = true;
    }

    if ( !exceptionCaught )
    {
        std::cout << "B" << std::endl;
        return ;
    }

    exceptionCaught = false;
    
    try
    {
        dynamic_cast< C& >( p );
    }
    catch( const std::bad_cast& e )
    {
        exceptionCaught = true;
    }

    if ( !exceptionCaught )
    {
        std::cout << "C" << std::endl;
        return ;
    }
}
