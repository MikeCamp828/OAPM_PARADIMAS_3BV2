//PARADIGMAS DE PROGRAMACIÓN 3BV2
//PROFR. ANDRES GARCIA FLORIANO
//MIGUEL ANGEL OCAMPO PORCAYO 2021301170
//PRACTICA 1


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
void genarreglo(int);
void printarr(int[],int);
void busqueda(int[], int);
void bubble(int [],int);
 
int main()
{
    double time_spent = 0.0; //tiempo inicial
    clock_t begin = clock();//cn¿ontador de reloj asignado a una variable
    
    srand(time(NULL));//semilla de numeros aleatorios
    int t;//variable de referencia
    printf("Escribe el tamanio del arreglo\n");
    scanf("%d",&t);//solicita un numero que guarda en variable referencia
    
    genarreglo(t);//manda a t como parametro de referencia a la funcion que genera un arreglo de t tamanio
    
    clock_t end = clock(); //finaliza el contador de tiempo
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;//calculo de tiempo de ejecucion
 
    printf("\nEl tiempo de ejecucion fue de %f segundos", time_spent);
    return 0; //fin de programa
}

void genarreglo(int t)//funcion llenadora de arreglo
{
    int *array; //apuntador para arreglo dinamico
    array=(int*) malloc(t * sizeof(int));//apartando espacio para erreglo dinamico
    
    for(int i=0; i<t; i++) //ciclo que se ejecutara t veces
        array[i]=rand()%100;//llenar el espacio t del arreglo con numero aleatorio
    printarr(array, t);//mandando como parametros el arreglo y la variable de referencia t
}

void printarr(int arr[],int t)//funcion que imprime el contenido de un arreglo
{
    for(int i=0; i<t; i++)//ciclo que se ejecutara t veces
        printf(" %d ",arr[i]);//imprime el contenido del arreglo en la pocision t
    busqueda(arr,t);//mandando como parametros el arreglo y la referencia t a busqueda bubble
}

void busqueda(int arr[], int t)//funcion de busqueda de un numero en u arreglo
{
    int n, bandera=0; //declarando variables de control y aviso
    printf("\n Escriba el numero a buscar \n");
    scanf("%d",&n); //guardando numero a buscar
    for(int i=0; i<t; i++)//ciclo que se ejecutara t veces
    {
        if(arr[i]==n) //si el numero a buscar es el mismo que el arreglo en la pocision n
        {
            printf("El numero se se encontro en la posicion %d\n",i);//aviso de encontrar
            bandera==1;//cambio de la bandera
            bubble(arr,t);//mandando el arreglo y t como referencia a la funcion de ordenamiento burbuja
            break; // evita ejecuciones inecesarias
        }
    }
    if(bandera==0)//si no hubocambio en el estado de la bandera
        printf("No se encontro el numero\n");
    bubble(arr,t);//mandando el arreglo y t como referencia a la funcion de ordenamiento burbuja
}

void bubble(int arr[], int t) //arreglo de ordenamiento burbuja
{
    int aux;//variable auxiliar
    for(int i=0; i<t; i++)//ciclo que se ejecutara t veces con i son las veces que se ordenara en mayor
    {
        for(int j=0; j<t; j++)//ciclo que se ejecutara t veces con j ya que son las veces que se ordenara en menor
        {
            if(j!=(t-1))//si el valor de j es diferente a el numero menos 1 ya que pueden ser iguales
            if(arr[j]>arr[j+1])//si en el arreglo el numero actual es mayor al que le sigue 
            {
                
                    aux=arr[j];//uso de la variable auxiliar para intercambiar valores del arreglo
                    arr[j]=arr[j+1];
                    arr[j+1]=aux; 
            }
        }
    }
    printf("Ordenado es : \n");
    for(int k=0; k<t; k++)//ciclo que se ejecutara t veces
        printf(" %d ",arr[k]);//mostrara el valor del arreglo t veces

}
