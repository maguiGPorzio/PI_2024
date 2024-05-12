
void 
printUpper(const char vector[]){
    int i=0;
    while (vector[i]){
        putchar(toupper(vector[i]));
        i++;
    }
}