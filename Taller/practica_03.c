#include <stdio.h>

int main() {
    int num=1;
    num= (num>0 and num<15) ? (num<10 ? (num+'0'):(num+'A'-10)):num ;
}