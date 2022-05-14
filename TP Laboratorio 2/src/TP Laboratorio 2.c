/*
 ============================================================================
 Name        : TP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pasajero.h"

#define TAM 10
#define ASC 1
#define DESC 0


int main(void) {

	    char salida = 'n';
	    int siguienteId = 200;
	    int flagPasajero = 0;
	    ePasajero lista[TAM];


	    inicializarPasajero(lista,TAM);

	    hardcodearPasajeros(lista,TAM,6,&siguienteId);

	    do
	    {
	        switch(menuPasajeros())
	        {
	        case 1:
	            altaPasajero(lista,TAM,&siguienteId);
	            flagPasajero = 1;
	            break;
	        case 2:
	            if(flagPasajero == 1)
	            {
	              modificarPasajero(lista,TAM);
	            }
	            else
	                {
	                    printf("Primero se deben ingresar los pasajeros para modificarlos");
	                }
	            break;
	        case 3:
	             if(flagPasajero == 1)
	            {
	              bajaPasajero(lista,TAM);;
	            }
	            else
	                {
	                    printf("Primero se deben ingresar los pasajeros para darlos de baja");
	                }
	            break;
	        case 4:
	             if(flagPasajero == 1)
	            {
	              switch(menuInformar())
	              {
	                case 1:
	                    listarPasajeros(lista,TAM);
	                    ordenarTipoPasajeroApellido(lista,TAM,1);
	                    listarPasajeros(lista,TAM);
	                    break;
	                case 2:
	                    promedioPasajeros(lista,TAM);
	                    break;
	                case 3:
	                    listarPasajeros(lista,TAM);
	                    ordenarCodigoVuelo(lista,TAM,1);
	                    listarPasajeros(lista,TAM);
	                    break;
	              }
	            }
	                else
	                    {
	                        printf("Primero se deben ingresar los pasajeros para dar los informes");
	                    }
	            break;
	        case 5:
	            salida = 's';
	            break;
	        }

	    }
	    while(salida != 's');

	return EXIT_SUCCESS;
}
