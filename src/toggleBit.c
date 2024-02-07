#include "toggleBit.h"

typedef struct node {
    Number* number;
    struct node* next;
    struct node* prev;
} Node;Node* HEAD = NULL;

typedef struct number{
    uint8_t data[8];
    uint8_t multiplier;
}Number;

Node* createNode(){
    Node* tmp = calloc(1,sizeof(Node));
    tmp->number = calloc(1,sizeof(Number));
    tmp->number->multiplier = 1;

    return tmp;
}

void readBinary(char* path){
    FILE *fp = fopen( path,"r");
    uint8_t data[1] = {0};

    HEAD = createNode();
    Node* tmpHead = HEAD;
    Node* prevNode = NULL;
    if(fp == NULL) return;
    
    while( !feof(fp) ){
        if(tmpHead == NULL){
            tmpHead = createNode();
            tmpHead->next = NULL;
            tmpHead->prev = prevNode;
        }

        fread(tmpHead->number->data ,8,1,fp);
        fread(data,1,1,fp);
        tmpHead->number->multiplier = *data;

        prevNode = tmpHead;
        tmpHead = tmpHead->next;
    }

    fclose(fp);
}

void writeBinary(char* path){
    FILE* fp = fopen(path, "w+");
    Node* tmpHead = HEAD;
    while(tmpHead != NULL){
        fwrite((unsigned char*)tmpHead->number->data,8,1,fp);
        fwrite(&tmpHead->number->multiplier,1,1,fp);
        tmpHead = tmpHead->next;
    }
}

bool toggleBit(uint64_t number){
    if(number == 0) return false;

    uint8_t index = (number-1)%8;
    uint8_t dIndex = ((number-1)%64)/8;

    Node* tmpHead = HEAD;
    for(uint64_t i = 0; i < (number-1)/64; i++)
        tmpHead = HEAD->next;

    if(tmpHead != NULL)
        tmpHead->number->data[dIndex] ^= (1 << index); 

    return false;
}

char* getValue(){
    return "0";
}
