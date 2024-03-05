#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Funcion que devuelve el numero de bits de n
int numero_de_bits(int nodos_total){
    int numero = nodos_total;
    int cont = 0;

    while (numero > 1) {
        cont++;
        numero = numero / 2;
    }
    return cont;
}
//Funcion que cuenta el numero de bits y el binario del numero
void decimal_a_binario(int num, int array[], int tamano){
    int i, aux;
    //array[tamano];
    for(i = tamano-1; i>=0; i-- ){
        aux = num%2;
        array[i] = aux;
        num = num/2;
    }
}

void imprimir_binario(int array[], int tamano){
    int i;
    for(i = 0; i< tamano; i++){
        printf("%i ", array[i]);
    }
}

int binario_a_entero(int array[], int tamano){
    int resultado = 0;
    int i;

    for (i = tamano - 1; i >= 0; i--) {
        if (array[i] == 1) {
            resultado += pow(2, tamano - 1 - i);
        }
    }
    return resultado;
}
//Función que devuelve el XOR de dos arrays y su distancia
void funcion_XOR(int array1[], int array2[], int array3[], int tamano){

    for(int i=0; i< tamano; i++){
        if(array1[i]!= array2[i]){
            array3[i] = 1;
        }else{
            array3[i] = 0;
        }
    }
}

int calc_distancia_XOR(int array1[], int array2[], int tamano){
    int distancia = 0;
    for(int i=0; i< tamano; i++){
        if(array1[i]!= array2[i]){
            distancia++;
        }
    }
    return distancia;
}

//Calcula (x,y) del num
void calc_puntos(int num, int n, int k, int puntos[]){
    int aux_num = num;
    int aux_n = n;
    int i=aux_n-1;
    int j;

    while(aux_n > 0){
        puntos[i]= aux_num%k;
        aux_num = aux_num/k;
        aux_n--;
        i--;
    }
    printf(" [ ");
    for(j=0; j<n; j++){
        if(j == n-1){
            printf("%d" , puntos[j]);
        }else{
            printf("%d, " ,puntos[j]);
        }

    }
    printf(" ] ");

}
int calc_distancia(int reg_enc[], int n){
    int i;
    int distancia = 0;
    for(i=0; i<n; i++){
        distancia+= abs(reg_enc[i]);
    }
    return distancia;
}
void calc_reg_enc(int arr_origen[], int arr_destino[], int n, int reg_enc[]){
    int i;
    for(i=0; i<n; i++){
        reg_enc[i] = arr_destino[i]-arr_origen[i];
    }

}
void transformar(int reg_enc[], int k, int transformado[], int n){
    int i;
    int medio = k/2;
    for(i=0; i<n; i++){
        if(reg_enc[i] > medio){
            transformado[i] = reg_enc[i]-k;
        }else if(reg_enc[i]< -medio){
            transformado[i] = reg_enc[i]+k;
        }else{
            transformado[i] = reg_enc[i];
        }
    }

}

void registro_enc_XOR(int array_origen[], int XOR[], int reg_enc[], int tamano, int *distancia){

    int dist_aux = *distancia;
    int sig_array[tamano];
    int num=0;
    int z, num_origen;
    int i = tamano-1;

    for(z = 0; z<tamano; z++){
        sig_array[z] = array_origen[z];
    }
    num_origen = binario_a_entero(array_origen, tamano);
    printf("%i ->", num_origen);
    reg_enc[0] = num_origen;
    while(dist_aux > 0 && i>=0){
        num = 0;
        if(XOR[i] == 1 ){
            sig_array[i] = 1-sig_array[i];
            XOR[i] = 0;
            num = binario_a_entero(sig_array, tamano);
            reg_enc[*distancia - dist_aux] = num;
            dist_aux--;
        }
        i--;
    }
    dist_aux = *distancia;
    for(int j=0; j<dist_aux; j++){
        if(j==dist_aux-1){
            printf("%i ", reg_enc[j]);
        }else{
            printf("%i->", reg_enc[j]);
        }
    }
}
int coordenadas_a_num(int reg_enc[], int n, int k){
    int num=0;
    int i;
    for(i=n-1; i>=0; i--){
        num += reg_enc[i]*(pow(k, n-i-1));
    }
    return num;
}

void camino_malla(int puntos_origen[], int origen, int destino, int reg_enc[], bool aux, int k, int n, int distancia){
    int i,num;
    if(aux == false){ //malla
        for(i=n-1; i>=0; i--){
            while(reg_enc[i]!=0){
                 if(reg_enc[i]<0){
                    num = coordenadas_a_num(puntos_origen, n, k);
                    printf("%i ->", num);
                    reg_enc[i] = reg_enc[i] + 1;
                    puntos_origen[i] = puntos_origen[i]-1;

                 }else{
                    num = coordenadas_a_num(puntos_origen, n, k);
                    printf("%i->", num);
                    reg_enc[i] = reg_enc[i] - 1;
                    puntos_origen[i] = puntos_origen[i]+1;

                 }
            }
            printf("%i", destino);
        }

    }else{//toro
        for(i=n-1; i>=0; i--){
             while(reg_enc[i]!=0){
                    if(reg_enc[i]<0){//negativo
                        num = coordenadas_a_num(puntos_origen, n, k);
                        printf("%i ->", num);
                        if(puntos_origen[i]-1 <0){
                            puntos_origen[i] = k-1;
                        }else{
                            puntos_origen[i] = puntos_origen[i]-1;
                        }
                        reg_enc[i] = reg_enc[i] + 1;
                    }else{//positivo
                        num = coordenadas_a_num(puntos_origen, n, k);
                        printf("%i ->", num);
                        if(puntos_origen[i]+1 == k){
                            puntos_origen[i] = 0;
                        }else{
                            puntos_origen[i] = puntos_origen[i]+1;
                        }
                        reg_enc[i] = reg_enc[i] - 1;

                    }
                }
                printf("%i ", destino);

            }
    }
}


int main(int argc, char* argv[]){

    const char* topologia_str[] = {"toro", "hipercubo", "malla"};
    int dimensiones, nodos, anillos, origen, destino, nodos_total, bits, distancia;
    bool a_anillos = false;
    int i;

    printf("Introduzca numero de dimensiones: ");
    scanf("%i", &dimensiones);
    printf("Introduzca el número de nodos por dimension: ");
    scanf("%i", &nodos);
    printf("Tiene anillos? 0=no 1=si: ");
    scanf("%i", &anillos);

    if(anillos == 0){
        a_anillos = false;
    }else if(anillos == 1){
        a_anillos = true;
    }else{
        printf("Tiene que introducir un valor entre 0 y 1\n");
        return 1;
    }
    printf("Introduzca un nodo origen: ");
    scanf("%i", &origen);
    printf("Introduzca un nodo destino: ");
    scanf("%i", &destino);

    if(a_anillos == true){ //toro
        printf("\n");
        nodos_total = pow(nodos, dimensiones);
        printf("%i-ary %i-%s: %i nodos en total\n", nodos, dimensiones, topologia_str[0], nodos_total);

        printf("El paquete va de: %i ", origen);
        int puntos1[dimensiones];
        int puntos2[dimensiones];
        calc_puntos(origen, dimensiones, nodos, puntos1);
        printf("a %i", destino);
        calc_puntos(destino, dimensiones, nodos, puntos2);
        int reg_enc[dimensiones];
        int transformado[dimensiones];
        printf("\n");
        calc_reg_enc(puntos1, puntos2, dimensiones, reg_enc);
        transformar(reg_enc, nodos, transformado, dimensiones);
        printf("Registro de encaminamiento: [ ");
        for(i=0; i< dimensiones; i++){
            if(i == dimensiones-1){
                printf("%i ]\n", transformado[i]);
            }else{
                printf("%i, ", transformado[i]);
            }

        }
        distancia = calc_distancia(transformado, dimensiones);
        printf("Distancia: %i\n", distancia);
        camino_malla(puntos1, origen, destino, transformado, a_anillos, nodos, dimensiones, distancia);


    }else if(a_anillos == false && nodos == 2 ){ //hipercubo
        nodos_total = pow(2, dimensiones);
        printf("%i-ary %i-%s: %i nodos en total\n", nodos, dimensiones, topologia_str[1], nodos_total);
        bits = numero_de_bits(nodos_total);
        printf("Numero de bits: %i\n", bits);
        int miArray1[bits];
        int miArray2[bits];
        int miarray3[bits];

        decimal_a_binario(origen, miArray1, bits);
        decimal_a_binario(destino, miArray2, bits);
        printf("El paquete va de %i ", origen);
        printf("[ ");
        for(i = 0; i<bits; i++){
            printf("%i ", miArray1[i]);
        }
        printf("]");
        printf(" a %i ", destino);
        printf("[ ");
        for(i = 0; i<bits; i++){
            printf("%i ", miArray2[i]);
        }
        printf("]\n");
        funcion_XOR(miArray1, miArray2, miarray3, bits);
        distancia = calc_distancia_XOR(miArray1, miArray2, bits);
        printf("Distancia : %i\n", distancia);


        printf("Registro de encaminamiento: ");
        printf("[ ");

        for(i = 0; i<bits; i++){
            printf("%i ", miarray3[i]);
        }
        printf("]\n");

        int reg_enc[distancia];
        registro_enc_XOR(miArray1, miarray3, reg_enc, bits, &distancia);

    }else{ // malla
        nodos_total = pow(nodos, dimensiones);
        printf("%i-ary %i-%s: %i nodos en total\n", nodos, dimensiones, topologia_str[2], nodos_total);
        printf("El paquete va de: %i ", origen);
        int puntos1[dimensiones];
        int puntos2[dimensiones];
        calc_puntos(origen, dimensiones, nodos, puntos1);
        printf("a %i", destino);
        calc_puntos(destino, dimensiones, nodos, puntos2);
        int reg_enc[dimensiones];
        calc_reg_enc(puntos1, puntos2, dimensiones, reg_enc);
        printf("\n");
        printf("Registro de encaminamiento: [");
        for(i=0; i<dimensiones; i++)
            if(i == dimensiones-1){
                printf("%i ", reg_enc[i]);
            }else{
                printf("%i, ", reg_enc[i]);
            }

        printf(" ]\n");
        distancia = calc_distancia(reg_enc, dimensiones);
        printf("Distancia: %i\n ", distancia);
        camino_malla(puntos1, origen, destino,reg_enc, a_anillos, nodos, dimensiones, distancia);
    }
    return 0;
}
