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
#include "Contabilizar.h"

int main(void) {
	setbuf(stdout, NULL);

	    float kilometros;
	    float precioAerolineas;
	    float precioLatam;
	    int cant;
	    int opcion;
	    int flagKilometros = 0; // Bandera que sirve para saber si se ingresaron los kilometros.
	    int flagPrecios = 0;  // Bandera que sirve para saber si se ingresaron precios de vuelos.
	    int flagCalculos = 0;  // Bandera que sirve para saber si se realizaron los calculos.

	    do
	    {
	    	system("cls");
	        printf(" *** Bienvenido a UTN Airlanes ***\n\n");
	        printf(" *** Elaborado por: Ivan Miceli DIV 1G ***\n\n");
	        printf(" *** Menu de Opciones ***\n\n");
	        printf("1- Ingresar kilometros\n");
	        printf("2- Ingresar precio de vuelos\n");
	        printf("3- Calcular todos los costos\n");
	        printf("4- Informar resultados\n");
	        printf("5- Carga forzada de datos\n");
	        printf("6- Salir\n");
	        printf("\nIngrese opcion: ");
	        cant = scanf("%d", &opcion);

	        if(cant == 0){
	        	opcion = 6;
	        }

	        switch(opcion)
	        {
	        case 1:
	            printf("Ingrese la cantidad de kilometros (mayor a 0): ");
	            scanf("%f", &kilometros);
	            while(kilometros <= 0)
	            {
	                printf("Dato invalido.Ingrese una cantidad de kilometros correcta: ");
	                scanf("%f",&kilometros);
	            }
	            flagKilometros = 1;
	            break;
	        case 2:
	            if(flagKilometros == 1)
	            {
	                printf("Ingrese precio de vuelo de Aerolineas (mayor a 0): ");
	                scanf("%f", &precioAerolineas);
	                while(precioAerolineas <= 0)
	                {
	                    printf("Precio invalido.Ingrese un precio nuevamente: ");
	                    scanf("%f",&precioAerolineas);
	                }

	                printf("Ingrese precio de vuelo de Latam (mayor a 0): ");
	                scanf("%f", &precioLatam);
	                while(precioLatam <= 0)
	                {
	                    printf("Precio invalido.Ingrese un precio nuevamente: ");
	                    scanf("%f",&precioLatam);
	                }
	            flagPrecios = 1;
	            }
	            else
	            {
	             printf("Primero se deben ingresar los kilometros antes de ingresar los precios\n");
	            }
	            break;
	        case 3:
	            if(flagKilometros == 1 && flagPrecios == 1)
	            {
	            printf("\nLos calculos fueron realizados\n");
	            descontar(precioAerolineas);
	            recargar(precioAerolineas);
	            convertir(precioAerolineas);
	            calcular(precioAerolineas, kilometros);
	            descontar(precioLatam);
	            recargar(precioLatam);
	            convertir(precioLatam);
	            calcular(precioLatam, kilometros);
	            restar(precioAerolineas, precioLatam);
	            flagCalculos = 1;
	            }
	            else{
	                printf("Para realizar los calculos debe ingresar primero los kilometros y luego los precios\n");
	            }
	            break;
	        case 4:
	            if(flagKilometros == 1 && flagPrecios == 1 && flagCalculos == 1)
	            {
	            printf("\nKMs ingresados: %.2f km\n", kilometros);
	            fflush(stdin);

	            printf("\nPrecio de Aerolineas Argentinas: $ %.2f\n", precioAerolineas);
	            printf("a) Precio con tarjeta de debito: $ %.2f\n", descontar(precioAerolineas));
	            printf("b) Precio con tarjeta de credito: $ %.2f\n", recargar(precioAerolineas));
	            printf("c) Precio pagando con bitcoin: $ %.2f BTC\n", convertir(precioAerolineas));
	            printf("d) Mostrar precio unitario: $ %.2f\n", calcular(precioAerolineas, kilometros));


	            printf("\nPrecio de Latam: $%.2f\n", precioLatam);
	            printf("a) Precio con tarjeta de debito: $ %.2f\n", descontar(precioLatam));
	            printf("b) Precio con tarjeta de credito: $ %.2f\n", recargar(precioLatam));
	            printf("c) Precio pagando con bitcoin: $ %.f BTC\n", convertir(precioLatam));
	            printf("d) Mostrar precio unitario: $ %.2f\n", calcular(precioLatam, kilometros));

	            printf("\nLa diferencia de precio es: $ %.2f\n", restar(precioAerolineas, precioLatam));

	            flagKilometros = 0;
	            flagPrecios = 0;
	            flagCalculos = 0;
	            }
	            else{
	                printf("\nNo se puede mostrar resultados si no ingresa los datos en orden primero.\n");
	            }
	            break;
	        case 5:
	            cargar();
	            break;
	        case 6:
	            printf("\nGracias por haber utilizado el programa, pulse cualquier boton para salir.\n");
	            opcion = 's';
	            break;
	        default:
	        	printf("\nError en seleccion de opciones, intente nuevamente.\n");
	        	break;
	        }

	        system("pause");

	    }
	    while(opcion != 's');


	return EXIT_SUCCESS;
}
