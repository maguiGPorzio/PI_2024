#include <stdio.h>
#define MASK 0x03

int main() {
    unsigned char var, var1, var2, var3, var4;
    var=0xD8;
    var1=var>>6;
    var2=(var>>4) & MASK;
    var3=(var>>2) & MASK;
    var4=var & MASK;
    return 0;
}
