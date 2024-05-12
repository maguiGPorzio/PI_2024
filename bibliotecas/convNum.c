int //convierte numero hexadecimal a binario
hexaABin (int hexa){
    int bin=0,i=1;
    while (hexa>0){
        bin+=(hexa%2)*i;
        i*=10;
        hexa/=2;
    }
    return bin;
}

int //convierte numero binario a decimal
binAdec (int bin){
    int i=1, dec=0;
    while (bin>0){
        dec+=(bin%10)*i;
        i*=2;
        bin/=10;
    }
    return dec;
}
