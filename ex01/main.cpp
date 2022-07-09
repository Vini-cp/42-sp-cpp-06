#include "include/Data.h"

int	main( void )
{
    std::cout << std::endl << "================ Data ================" << std::endl;

    Data lData;
    std::cout << lData;

    std::cout << "======================================" << std::endl;

    std::cout << std::endl << "============== Ser Data ==============" << std::endl;
    
    uintptr_t lSerializedData = serialize( &lData );
    std::cout << lSerializedData << std::endl;

    std::cout << "======================================" << std::endl;

    std::cout << std::endl << "============== DesrData ==============" << std::endl;

    Data* lDeserializeData = deserialize( lSerializedData );
    std::cout << *lDeserializeData;

    std::cout << "======================================" << std::endl;

    std::cout << std::endl << "============== DesrFake ==============" << std::endl;

    FakeData* lDeserializeFakeData = fakeDeserialize( lSerializedData );
    std::cout << *lDeserializeFakeData;

    std::cout << "======================================" << std::endl << std::endl;

    return 0;
}