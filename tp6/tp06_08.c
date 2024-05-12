/*
Repetir el ejercicio anterior, teniendo en cuenta que los arreglos de entrada pueden tener elementos repetidos, 
pero el de salida NO debe tener repeticiones. 
*/

void 
unirArreglos(const int v1[], const int v2[], int v3[]){
    int i=0, j=0, k=0; //i posicion v1, j posicion v2, k posicion v3
    while (v1[i]!=-1 || v2[j]!=-1){
        if (v1[i]!=-1){
            while (v1[i]==v1[i+1]){
                i++;
            }
        }
        if (v2[i]!=-1){
            while (v2[j]==vj[j+1]){
                j++;
            }
        }
        else {
            if (v1[i]!=-1 && v2[j]!=-1){ 
                if (v1[i]==v2[j]){
                    v3[k++]=v1[i++];
                    j++;
                }
                else if (v1[i]<v2[j]){
                    v3[k++]=v1[i++];
                }
                else {
                    v3[k++]=v2[j++];
                }
            }
            else if (v1[i]==-1){
                v3[k++]=v2[j++];
            }
            else{
                v3[k++]=v1[i++];
            }

        }
    }
    v3[k]=-1;      
}