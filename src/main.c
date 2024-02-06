#include <stdio.h>
#include <string.h>

#include "toggleBit.h"

int main(int argc, char** argv){
    if(argc <= 1) return 1;

    if( strcmp( argv[1], "reset" ) == 0 ){
        return 0;
    }else if( strcmp( argv[1], "value" ) == 0 ){
        printf("%s", getValue() );
        return 0;
    }

    char* toggle = argv[1];
    if( toggleBit(toggle) ){
        
    }

    return 0;
}