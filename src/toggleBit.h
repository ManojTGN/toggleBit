#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef _TOGGLE_BIT_H_
#define _TOGGLE_BIT_H_

typedef struct node Node;
typedef struct number Number;

void readBinary(char* path);
void writeBinary(char* path);

bool toggleBit(uint64_t number);
char* getValue();

#endif /* _TOGGLE_BIT_H_ */
