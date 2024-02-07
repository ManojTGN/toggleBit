#include "toggleBit.h"

int main(int argc, char** argv){
    if(argc <= 1) return 1;
    readBinary(argv[0]);

    if( strcmp( argv[1], "reset" ) == 0 ){
        return 0;
    }else if( strcmp( argv[1], "show" ) == 0 ||  strcmp( argv[1], "value" ) == 0  ){
        printf("%s", getValue() );
        return 0;
    }
    
    uint64_t toggle = strtoull( argv[1],NULL,10 );

    if( toggleBit(toggle) );
    writeBinary(argv[0]);

    return EXIT_SUCCESS;
}