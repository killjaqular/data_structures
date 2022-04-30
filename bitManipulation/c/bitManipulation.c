/*
Adonay Pichardo, adonaypichardo@gmail.com

@description
Common bit manipulation in C.

*/

// STANDARD LIBRARIES
#include <stdio.h>
#include <stdbool.h>

// PROTOTYPES
int  setBit(int,  unsigned int);//Sets bit at a ith
bool getBit(int,  unsigned int);//Gets bit at a ith
int  flipBit(int, unsigned int);//Flips bit at a ith
int  countBits(int);//Counts all 1s
int  reverseByte(int);//Reverses the order of the byte

int main(int argc, char** argv){
    int  byte  = 5;
    bool isSet = 0;
    int  temp  = 0;

    printf("byte  = %dd\n", byte);

    isSet = getBit(byte, 0);
    printf("isSet = %dd\n", isSet);

    byte = setBit(byte, 0);
    printf("byte  = %dd\n", byte);

    isSet = getBit(byte, 1);
    printf("isSet = %dd\n", isSet);

    byte = flipBit(byte, 0);
    printf("byte  = %dd\n", byte);

    byte = -1;
    printf("\nbyte  = %dd\n", byte);

    isSet = getBit(byte, 31);
    printf("isSet = %dd\n", isSet);

    byte = flipBit(byte, 31);
    printf("byte  = %dd\n", byte);

    isSet = getBit(byte, 31);
    printf("isSet = %dd\n", isSet);

    byte = 0x12345678;
    printf("\nbyte  = %xh\n", byte);

    byte = reverseByte(byte);
    printf("byte  = %xh\n", byte);

    byte = 5;
    printf("byte  = %dd\n", byte);

    temp = countBits(byte);
    printf("temp  = %dd\n", temp);

    return 0;
}

// DEFINITIONS
int setBit(int givenByte, unsigned int ith){
/*
Sets bit at ith position.
Input:  givenByte - The byte to update.
        ith  - Bit to turn on.
Output: result    - The byte with the bit set at i.
Example Usage:
int byte = 5;
int temp = 0;
temp = setBit(byte, 4);
*/
    printf("Set  bit %d\n", ith);
    int temp = 1;
    int result = 0;
    temp = temp << ith;

    result = givenByte | temp;

    return result;
}
bool getBit(int givenByte, unsigned int ith){
/*
Gets bit at ith position.
Input:  givenByte - The byte to check.
        ith  - Bit to get.
Output: result    - 1 or 0.
Example Usage:
int byte = 0;
if(setBit(byte, 1)){...}
*/
    printf("Get  bit %d\n", ith);
    int  temp   = 1;
    bool result = 0;
    temp = temp << ith;

    temp = givenByte & temp;

    if(temp){
        result = 1;
    }else{
        result = 0;
    }

    return result;
}
int flipBit(int givenByte, unsigned int ith){
/*
Flips bit at a ith.
Input:  givenByte - The byte to update.
        ith  - Bit to flip.
Output: result    - The byte with the bit set at i.
Example Usage:
int byte = 5;
int temp = 0;
temp = flipBit(byte, 2);
*/
    printf("Flip bit %d\n", ith);
    int temp = 1;
    int result = 0;
    temp = temp << ith;

    result = givenByte ^ temp;

    return result;
}
int countBits(int givenByte){
/*
Counts all 1s.
Input:  givenByte - The byte to count.
Output: count     - Total count of 1s.
Example Usage:
int byte = 5;
int temp = 0;
temp = countBits(byte);
*/
    int count = 0;

    for(int iter = 0; iter < (sizeof(int) * 8) - 1; iter++){
        if(getBit(givenByte, 0)){
            count++;
        }
        givenByte = givenByte >> 1;
    }

    return count;
}
int reverseByte(int givenByte){
/*
Reverses the order of the byte.
Input:
Output:
Example Usage:
int byte = 0x12345678;
byte = reverseByte(byte);
*/
    int A = (givenByte << 24);
    int B = (((givenByte >> 16) << 24) >> 16);
    int C = (((givenByte << 16) >> 24) << 16);
    int D = (givenByte >> 24);

    int result = A | B | C | D;

    return result;
}