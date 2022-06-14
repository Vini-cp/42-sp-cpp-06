// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../include/Conversion.h"

#include <cstdlib>
#include <iomanip>

//------------------------------------------------------------------------------

Conversion::Conversion( void ):
    mToConvert( "" ),
    mChar( 0 ),
    mInt( 0 ),
    mFloat( 0 ),
    mDouble( 0 ),
    mIsPseudoLiteral( false ),
    mIsImpossibleToParse( false ),
    mIntOverflow( false ),
    mConversionType( None )
{
}

//------------------------------------------------------------------------------

Conversion::Conversion( const std::string& pToConvert ):
    mToConvert( pToConvert ),
    mChar( 0 ),
    mInt( 0 ),
    mFloat( 0 ),
    mDouble( 0 ),
    mIsPseudoLiteral( false ),
    mIsImpossibleToParse( false ),
    mIntOverflow( false ),
    mConversionType( None )
{
}

//------------------------------------------------------------------------------

Conversion::Conversion( const Conversion& prConversion )
{
    *this = prConversion;
}

//------------------------------------------------------------------------------

Conversion::~Conversion( void )
{
}

//------------------------------------------------------------------------------

Conversion& Conversion::operator=( const Conversion& prConversion )
{
    if ( this == &prConversion ) return *this;

    mToConvert = prConversion.getString(); 
    mChar = prConversion.getChar();
    mInt = prConversion.getInt();
    mFloat = prConversion.getFloat();
    mDouble = prConversion.getDouble();
    mIsPseudoLiteral = prConversion.getIsPseudoLiteral();
    mIsImpossibleToParse = prConversion.getIsImpossibleToParse();
    mConversionType = prConversion.getConversionType();
    mIntOverflow = prConversion.getIntOverflow();
    return *this;
}

//------------------------------------------------------------------------------

void Conversion::setString( const std::string& pToConvert )
{
    mToConvert = pToConvert;
}

//------------------------------------------------------------------------------

std::string Conversion::getString( void ) const
{
    return mToConvert;
}

//------------------------------------------------------------------------------

char Conversion::getChar( void ) const
{
    return mChar;
}

//------------------------------------------------------------------------------

int Conversion::getInt( void ) const
{
    return mInt;
}

//------------------------------------------------------------------------------

float Conversion::getFloat( void ) const
{
    return mFloat;
}

//------------------------------------------------------------------------------

double Conversion::getDouble( void ) const
{
    return mDouble;
}

//------------------------------------------------------------------------------

bool Conversion::getIsPseudoLiteral( void ) const
{
    return mIsPseudoLiteral;
}

//------------------------------------------------------------------------------

bool Conversion::getIsImpossibleToParse( void ) const
{
    return mIsImpossibleToParse;
}

//------------------------------------------------------------------------------

conversionType Conversion::getConversionType( void ) const
{
    return mConversionType;
}

//------------------------------------------------------------------------------

bool Conversion::getIntOverflow( void ) const
{
    return mIntOverflow;
}

//------------------------------------------------------------------------------

bool Conversion::hasDuplicateChar( char c )
{
    return ( mToConvert.find_first_of( c ) != mToConvert.find_last_of( c ) );
}

//------------------------------------------------------------------------------

bool Conversion::IsCharWellPositioned( char c, int idx )
{
    if ( mToConvert.find_first_of( c ) == std::string::npos ) return false;

    return ( mToConvert.find_first_of( c ) != static_cast< unsigned int >( idx ) );
}

//------------------------------------------------------------------------------

bool Conversion::handleParseErrors( void )
{
    if ( mToConvert.find_first_not_of( "+-0123456789.f" ) != std::string::npos ||
         hasDuplicateChar( 'f' ) || hasDuplicateChar( '.' ) || hasDuplicateChar( '+' ) || hasDuplicateChar( '-' ) ||
         IsCharWellPositioned( 'f', mToConvert.length() - 1 ) || IsCharWellPositioned( '+', 0 ) || IsCharWellPositioned( '-', 0 ) )
    {
        return true;
    }

    return false;
}

//------------------------------------------------------------------------------

bool Conversion::handlePseudoLiterals( void )
{
    if ( mToConvert == "-inf" || mToConvert == "+inf" || mToConvert == "nan" ||
         mToConvert == "-inff" || mToConvert == "+inff" || mToConvert == "nanf" )
    {
        return true;
    }

    return false;
}

//------------------------------------------------------------------------------

conversionType Conversion::setConversionType( void )
{
    if ( mToConvert.size() == 1 && mToConvert.find_first_not_of( "0123456789" ) != std::string::npos )
    {
        return Char;
    }
    else if ( mToConvert.find_first_of( 'f' ) != std::string::npos )
    {
        return Float;
    }
    else if ( mToConvert.find_first_of( '.' ) != std::string::npos || mIntOverflow )
    {
        return Double;
    }
    else
    {
        return Int;
    }
}

//------------------------------------------------------------------------------

void Conversion::convertToChar( void )
{
    mChar = static_cast< char >( mToConvert[ 0 ] );
    mInt = static_cast< int >( mChar );
    mFloat = static_cast< float >( mChar );
    mDouble = static_cast< double >( mChar );
}

//------------------------------------------------------------------------------

void Conversion::convertToInt( void )
{
    mInt = static_cast< int >( atoi( mToConvert.c_str() ) );
    mChar = static_cast< char >( mInt );
    mFloat = static_cast< float >( mInt );
    mDouble = static_cast< double >( mInt );
}

//------------------------------------------------------------------------------

void Conversion::convertToFloat( void )
{
    mFloat = static_cast< float >( strtof( mToConvert.c_str(), NULL ) );
    mChar = static_cast< char >( mFloat );
    mInt = static_cast< int >( mFloat );
    mDouble = static_cast< double >( mFloat );
}

//------------------------------------------------------------------------------

void Conversion::convertToDouble( void )
{
    mDouble = static_cast< double >( strtod( mToConvert.c_str(), NULL ) );
    mChar = static_cast< char >( mDouble );
    mInt = static_cast< int >( mDouble );
    mFloat = static_cast< float >( mDouble );
}

//------------------------------------------------------------------------------

void Conversion::Convert( void )
{
    mIsPseudoLiteral = handlePseudoLiterals();

    if ( mIsPseudoLiteral ) return ;

    mIsImpossibleToParse = handleParseErrors();

    if ( mIsImpossibleToParse ) return ;

    mIntOverflow = ( mToConvert.compare("2147483647") > 0 || mToConvert.compare("-2147483648") < 0 );

    mConversionType = setConversionType();

    if ( mConversionType == Char )
    {
        convertToChar();
    }
    else if ( mConversionType == Int )
    {
        convertToInt();
    }
    else if ( mConversionType == Float )
    {
        convertToFloat();
    }
    else if ( mConversionType == Double )
    {
        convertToDouble();
    }
}

//------------------------------------------------------------------------------

void Conversion::displayPseudoLiterals( void )
{
    std::string lToPrint = ( mToConvert == "nanf" ) ? mToConvert.substr( 0, 3 ) : mToConvert;

    std::cout << "char: impossible" << std::endl
              << "int: impossible" << std::endl
              << "float: " << lToPrint.substr( 0, 4 ) + "f" << std::endl
              << "double: " << lToPrint.substr( 0, 4 ) << std::endl;
}

//------------------------------------------------------------------------------

void Conversion::displayNone( void )
{
    std::cout << "char: impossible" << std::endl
              << "int: impossible" << std::endl
              << "float: impossible" << std::endl
              << "double: impossible" << std::endl;
}

//------------------------------------------------------------------------------

void Conversion::displayValues( void )
{
    std::string lCharToPrint = ( std::isprint( mChar ) ) ? mChar + "\0" : "Non displayable";

    std::cout << "char: " << lCharToPrint << std::endl;

    if ( mIntOverflow )
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << mInt << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << mFloat << "f" << std::endl
              << "double: " << mDouble << std::endl;
}

//------------------------------------------------------------------------------

void Conversion::showResult( void )
{
    if ( mIsPseudoLiteral )
    {
        displayPseudoLiterals();
    }
    else if ( mIsImpossibleToParse )
    {
        displayNone();
    }
    else
    {
        displayValues();
    }
}

//------------------------------------------------------------------------------
