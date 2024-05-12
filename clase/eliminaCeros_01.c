int
eliminaCeros(int v[], int n){
    int i,j;
    i=j=0;
    while (i<n){
        if (v[i]==0){
            i++;
        }
        else {
            v[j++]=v[i]
        }
    }
    return j;
}

int
eliminaCeros(int v[], int n){
    int j=0;
    for (int i=0 ; i<n ; i++){
        if (v[i]){
            v[j++]=v[i];
        }
    }
    return j;
}