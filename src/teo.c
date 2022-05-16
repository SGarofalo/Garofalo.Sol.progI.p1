#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 4

typedef struct{
	int id;
	char procesador[20];
	char marca[20];
	float precio;

}eNotebook;

float aplicarDescuento(float precio);
int contarCaracteres(char cadena[], char a);
int ordenarPersonas(eNotebook lista[], int tam);


int main(void) {

	setbuf(stdout,NULL);

	eNotebook lista[TAM];
	char cadena[20] = "Luciana";
/*
 * 1. Crear una función llamada aplicarDescuento que reciba como parámetro
 * el precio de un producto y devuelva el valor del producto
 *  con un descuento del 5%. Realizar la llamada desde el main.
 */
	printf("El precio final con el dto es: %.2f\n",aplicarDescuento(100));


 /*
 * 2. Crear una función que se llame contarCaracteres que reciba una
 * cadena de caracteres como primer parámetro y un carácter
 * como segundo y devuelva la cantidad de veces que ese carácter aparece
 * en la cadena
 */
	printf("La cantidad de caracteres es: %d\n", contarCaracteres(cadena,'a'));
	puts(cadena);

/*
 * 3.Dada la estructura Notebook(id, procesador, marca, precio) generar una función
 *  que permita ordenar un array de dicha estructura por marca. Ante igualdad de marca
 *  deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.
 */
	ordenarPersonas(lista, TAM); // NO PUDE TERMINARLO
	return 0;
}
float aplicarDescuento(float precio){

	float dto;
	float precioFinal;


	if(precio > 0){

	dto = (float)(5 * precio) / 100;

precioFinal = precio - dto;

	}
		return precioFinal;
}

int contarCaracteres(char cadena[], char a){

	int contador = 0;
	int i=0;

	if (cadena != NULL) {

		while (cadena[i] != '\0') {
			if (cadena[i] == a) {
				contador++;
			}
		i++;
		}


	}

	return contador;


}


int ordenarPersonas(eNotebook lista[], int tam){

	int todoOk = 0;
	eNotebook auxNote;

	if(lista != NULL && tam > 0){

		for(int i=0; i<tam-1; i++){
			for(int j=i+1; j<tam; j++){

				if((lista[i].marca > lista[j].marca &&
					lista[i].precio > lista[j].precio) ||
					strcmp(lista[i].marca, lista[j].marca)){

						auxNote = lista[i];
						lista[i] = lista[j];
						lista[j] = auxNote;

				}

				}

			}

		}

				todoOk = 1;

				return todoOk;
}
