// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef CONVERSION_H
#define CONVERSION_H

#include <iostream>

enum conversionType { None, Char, Int, Float, Double };

class Conversion
{
public:

    Conversion( void );
    Conversion( const std::string& pToConvert );
    Conversion( const Conversion& prConversion );
    ~Conversion( void );

    Conversion& operator=( const Conversion& prConversion );

    void showResult( void );

    void Convert( void );

private:

    std::string mToConvert;

    char mChar;
    int mInt;
    float mFloat;
    double mDouble;

    bool mIsPseudoLiteral;
    bool mIsImpossibleToParse;
    bool mIntOverflow;

    conversionType mConversionType;

    conversionType setConversionType( void );

    bool handlePseudoLiterals( void );
    bool handleParseErrors( void );
    bool handleOverflow( void );

    bool CheckCharExistence( char c );
    bool hasDuplicateChar( char c );
    bool IsCharPoorlyPositioned( char c, int idx );

    void displayPseudoLiterals( void );
    void displayNone( void );
    void displayValues( void );

    void convertToChar( void );
    void convertToInt( void );
    void convertToFloat( void );
    void convertToDouble( void );
};

#endif
