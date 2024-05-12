#define MAYOR(m1,m2) (((m1)>(m2)) ? (m1):(m2))

int
main (void) {
    int a,b,r;
    a=2;
    b=5;
    int max=MAYOR(a,b);
    printf("El mayor es %d\n",MAYOR(a,b));
    return o;
}