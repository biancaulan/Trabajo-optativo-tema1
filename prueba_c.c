#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
//NECESARIO?????????????
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
void funcion_XOR_y_distancia(int array1[], int array2[], int array3[], int tamano, int *distancia){

    for(int i=0; i< tamano; i++){
        if(array1[i]!= array2[i]){
            array3[i] = 1;
            (*distancia)++;
        }else{
            array3[i] = 0;
        }
    }
}

void registro_enc_XOR(int array_origen[], int XOR[], int reg_enc[], int tamano, int *distancia){

    int dist_aux = *distancia;
    int sig_array[tamano];
    int num=0;
    int z, num_origen;
    int i = tamano-1;
    reg_enc[dist_aux+1];

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
            //printf("XOR:       ");
            //imprimir_binario(XOR, tamano);
            //printf("\n");
            //printf("Siguiente: ");
            //imprimir_binario(sig_array, tamano);
            //printf("\n");
            //printf("-----------\n");
            num = binario_a_entero(sig_array, tamano);
            reg_enc[*distancia - dist_aux] = num;
            //printf("%i ->", reg_enc[i]);
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


int main(int argc, char* argv[]){

    const char* topologia_str[] = {"toro", "hipercubo", "malla"};
    int dimensiones, nodos, anillos, origen, destino, nodos_total, bits, distancia;
    bool a_anillos = false;
    int i;


    printf("Introduzca numero de dimensiones:\n");
    scanf("%i", &dimensiones);
    printf("Introduzca el número de nodos por dimension\n");
    scanf("%i", &nodos);
    printf("Tiene anillos? 0=no 1=si\n");
    scanf("%i", &anillos);

    if(anillos == 0){
        a_anillos = false;
    }else if(anillos == 1){
        a_anillos = true;
    }else{
        printf("Tiene que introducir un valor entre 0 y 1\n");
        return 1;
    }
    printf("Introduzca un nodo origen\n");
    scanf("%i", &origen);
    printf("Introduzca un nodo destino\n");
    scanf("%i", &destino);

    if(a_anillos == true){ //toro

        nodos_total = pow(nodos, dimensiones);
        printf("%i-ary %i-%s: %i nodos en total\n", nodos, dimensiones, topologia_str[0], nodos_total);

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
        funcion_XOR_y_distancia(miArray1, miArray2, miarray3, bits, &distancia);
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

    }
    //printf("El paquete va de %i a %i\n", origen, destino);

    return 0;
}
