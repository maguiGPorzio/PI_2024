void
secondsToHMS( unsigned *h, unsigned *m, unsigned *s) {
    *h= *s / 3600;
    *s= *s % 3600;
    *m= *s / 60;
    *s= *s % 60;
}

int
main(void) {
   int h, m, s = 5780;

   secondsToHMS(&h, &m, &s);
   return 0;
}
