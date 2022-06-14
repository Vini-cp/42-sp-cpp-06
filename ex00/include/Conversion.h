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

    void setString( const std::string& pToConvert );
    std::string getString( void ) const;

    char getChar( void ) const;
    int getInt( void ) const;
    float getFloat( void ) const;
    double getDouble( void ) const;
    
    bool getIsPseudoLiteral( void ) const;
    bool getIsImpossibleToParse( void ) const;
    bool getIntOverflow( void ) const;

    conversionType getConversionType( void ) const;

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

    bool hasDuplicateChar( char c );
    bool IsCharWellPositioned( char c, int idx );

    void displayPseudoLiterals( void );
    void displayNone( void );
    void displayValues( void );

    void convertToChar( void );
    void convertToInt( void );
    void convertToFloat( void );
    void convertToDouble( void );
};

#endif
