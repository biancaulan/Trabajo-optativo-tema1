#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Funcion que devuelve el numero de bits de n
int numero_de_bits(int nodos_total){
    int numero = nodos_total;
    int cont = 0;
    int aux = 10000;

    while (aux > 1){
        aux = numero/2;
        cont++;
        numero = aux;
        if( aux == 1){
            cont++;
        }
    }
    return cont;
}
//Funcion que cuenta el numero de bits y el binario del numero
void decimal_a_binario(int num, int array[], int tamano){
    int i, aux;
    array[tamano];
    for(i = tamano-1; i>=0; i-- ){
        aux = num%2;
        array[i] = aux;
        num = num/2;
    }
}
//NECESARIO?????????????
int binario_a_entero(int array[], int tamano){
    int resultado = 0;
    for(int i=0; i< tamano; i++){
        resultado = (resultado << 1) | array[i];
    }
    return resultado;
}

void funcion_XOR(int array1[], int array2[], int array3[], int tamano){

    for(int i=0; i< tamano; i++){
        if(array1[i]!= array2[i]){
            array3[i] = 1;
        }else{
            array3[i] = 0;
        }
    }
}
void registro_enc_XOR(int array_origen[], int XOR[], int camino[], int tamano){
    int i,j, aux;
    int num = 0;
    for(i = tamano-1; i<=0; i--){
        if(XOR[i] == 1){
            array_origen[i] = 1:
            XOR[i] = 0;
            for(j=tamano-1; j<=0; j--){
                aux =
                num += pow(2, j-)
            }
        }else{
            i--;
        }
    }
}


int main(int argc, char* argv[]){

    const char* topologia_str[] = {"toro", "hipercubo", "malla"};
    int dimensiones, nodos, anillos, origen, destino, nodos_total, bits;
    int distancia = 0;
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
        printf("Numero de bits: %i", bits);
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
        printf("Registro de encaminamiento: ");
        printf("[ ");
        funcion_XOR(miArray1, miArray2, miarray3, bits);

        for(i = 0; i<bits; i++){
            printf("%i ", miarray3[i]);
        }
        printf("]\n");

    }else{ // malla
        nodos_total = pow(nodos, dimensiones);
        printf("%i-ary %i-%s: %i nodos en total\n", nodos, dimensiones, topologia_str[2], nodos_total);

    }
    //printf("El paquete va de %i a %i\n", origen, destino);
    printf("Distancia: %i\n", distancia);
    printf("Registro de encaminamiento\n");
    return 0;
}
