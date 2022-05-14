/*
 * pasajero.c
 *
 *  Created on: 14 may. 2022
 *      Author: Ivan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pasajero.h"

int menuPasajeros()
{
    int opcion;


    printf("     *** ABM de Aerolineas ***\n");
    printf("----------------------------------\n");
    printf("  *** TP 2 - Miceli Ivan Gonzalo ***\n");
    printf("------------------------------------\n\n");
    printf("1. Alta de pasajero\n");
    printf("2. Modificar pasajero\n");
    printf("3. Baja de pasajero\n");
    printf("4. Informar\n");
    printf("5. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int altaPasajero(ePasajero vec[], int tam,int* pProximoId)
{
    int resultado = -1;
    int indice;
    ePasajero nuevoPasajero;

    if(vec != NULL && pProximoId != NULL && tam > 0)
    {

        printf("    *** Alta de Pasajero ***\n");
        printf("------------------------------\n");

        buscarPasajeroLibre(vec, tam, &indice);

        if(indice == -1)
        {
            printf("No hay lugar para asignar al pasajero\n");
        }
        else
        {
            nuevoPasajero.id = *pProximoId;

            printf("Ingrese nombre:");
            fflush(stdin);
            gets(nuevoPasajero.nombre);

            printf("Ingrese apellido:");
            fflush(stdin);
            gets(nuevoPasajero.apellido);

            printf("Ingrese precio: ");
            scanf("%f", &nuevoPasajero.precio);

            printf("1. ESP123\n");
            printf("2. BAS456\n");
            printf("3. JPN789\n");
            printf("Ingrese codigo de vuelo:");
            fflush(stdin);
            gets(nuevoPasajero.codigoVuelo);
            //FALTA VALIDAR SI NO INGRESA ESOS 3 TIPOS

            printf("1. PRIMERA CLASE\n");
            printf("2. EJECUTIVO\n");
            printf("3. TURISTA\n");
            printf("Ingrese tipo de pasajero:");
            scanf("%d", &nuevoPasajero.tipoPasajero);

            while(nuevoPasajero.tipoPasajero != 1 && nuevoPasajero.tipoPasajero != 2 && nuevoPasajero.tipoPasajero != 3)
            {
                printf("Tipo de pasajero incorrecto. Reingrese tipo de pasajero: ");
                scanf("%d", &nuevoPasajero.tipoPasajero);
            }

            printf("10. ACTIVO\n");
            printf("20. DEMORADO\n");
            printf("30. CANCELADO\n");
            printf("Ingrese estado de vuelo:");
            scanf("%d", &nuevoPasajero.estadoVuelo);

            while(nuevoPasajero.estadoVuelo != 10 && nuevoPasajero.estadoVuelo != 20 && nuevoPasajero.estadoVuelo != 30)
            {
                printf("Tipo de pasajero incorrecto. Reingrese tipo de pasajero: ");
                scanf("%d", &nuevoPasajero.estadoVuelo);
            }

            nuevoPasajero.isEmpty = 0;

            vec[indice] = nuevoPasajero;

            printf("\nPasajero cargado con exito!!\n");

            (*pProximoId)++;

            resultado = 0;
        }
    }
    return resultado;
}

void mostrarPasajero(ePasajero pas)
{

    printf("%2d    %10s     %10s     %5.2f     %7s      %10d       %10d\n", pas.id, pas.nombre, pas.apellido, pas.precio, pas.codigoVuelo, pas.tipoPasajero,pas.estadoVuelo);

}

int listarPasajeros(ePasajero vec[],int tam)
{
    int resultado = -1;
    int flagPasajero = 1;

    if(vec != NULL && tam > 0)
    {


        printf("              ****    LISTA DE PASAJEROS   *****\n");
        printf("********************************************************************\n");
        printf("ID          NOMBRE      APELLIDO      PRECIO   COD. DE VUELO   TIPO DE PASAJERO    ESTADO DE VUELO\n");
        printf("-----------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                mostrarPasajero(vec[i]);
                flagPasajero = 0;
            }

        }
        if(flagPasajero)
        {
            printf("     No hay pasajeros en el sistema\n");
        }

        resultado = 0;
    }
    return resultado;
}

int hardcodearPasajeros(ePasajero vec[], int tam, int cantidad,int* pProximoId)
{
    int resultado = -1;
    ePasajero pasajeros[10] =
    {
        {0, "Ivan","Miceli",12000,"ESP123",1,10},
        {0, "Pedro","Martinez",15000,"BAS456",2,20},
        {0, "Maria","Gonzalez",27500,"JPN789",3,30},
        {0, "Juana","Cerroti",32500,"BAS456",2,30},
        {0, "Mario","Lopez",37500,"JPN789",1,20},
        {0, "Martin","Josele",54000,"ESP123",3,10},
        {0, "Gabriela","Luz",21000,"ESP123",1,10},
        {0, "Lucia","Esperanza",11700,"JPN789",2,30},
        {0, "Macarena","Cuiz",13500,"BAS456",3,10},
        {0, "Ivana","Terrafico",15000,"JPN789",1,20},

    };

    if(vec != NULL && tam > 0 && tam <= 10 && cantidad <= tam)
    {
        for(int i=0; i<cantidad; i++)
        {
            vec[i] = pasajeros[i];
            vec[i].id = *pProximoId;
            (*pProximoId)++;
        }

        resultado = 0;
    }

    return resultado;
}

int inicializarPasajero(ePasajero vec[],int tam)
{
    int resultado = -1;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        resultado = 0;
    }
    return resultado;
}

int buscarPasajeroLibre(ePasajero vec[], int tam,int* pIndice)
{
    int resultado = 0;

    if(vec != NULL && pIndice != NULL && tam > 0)
    {
        *pIndice = -1;

        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty == 1)
            {
                *pIndice = i;
                break;
            }
        }
        resultado = 1;
    }
    return resultado;
}

int ordenarCodigoVuelo(ePasajero vec[], int tam, int criterio)
{
    int resultado = -1;
    ePasajero auxiliar;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i<tam - 1; i++)
        {
            for(int j = i + 1; j<tam; j++)
            {
                if(vec[i].estadoVuelo == vec[j].estadoVuelo)
                {
                    if(strcmp(vec[i].codigoVuelo, vec[j].codigoVuelo) < 0 && !criterio)
                    {
                        auxiliar = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxiliar;

                    }
                    else
                    {
                        if(strcmp(vec[i].codigoVuelo, vec[j].codigoVuelo) > 0 && criterio)

                        {
                            auxiliar = vec[i];
                            vec[i] = vec[j];
                            vec[j] = auxiliar;
                        }

                    }

                }
                else
                {
                    if(vec[i].estadoVuelo > vec[j].estadoVuelo)
                    {
                        auxiliar = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxiliar;
                    }


                }

            }

        }
        resultado = 0;
    }
    return resultado;
}

int ordenarTipoPasajeroApellido(ePasajero vec[], int tam, int criterio)
{

    int resultado = -1;
    ePasajero auxiliar;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i<tam - 1; i++)
        {
            for(int j = i + 1; j<tam; j++)
            {
                if(vec[i].tipoPasajero == vec[j].tipoPasajero)
                {
                    if(strcmp(vec[i].apellido, vec[j].apellido) < 0 && !criterio)
                    {
                        auxiliar = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxiliar;

                    }
                    else
                    {
                        if(strcmp(vec[i].apellido, vec[j].apellido) > 0 && criterio)

                        {
                            auxiliar = vec[i];
                            vec[i] = vec[j];
                            vec[j] = auxiliar;
                        }

                    }

                }
                else
                {
                    if(vec[i].tipoPasajero > vec[j].tipoPasajero)
                    {
                        auxiliar = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxiliar;
                    }

                }

            }

        }
        resultado = 0;
    }
    return resultado;
}

int menuModificarPasajero()
{
    int opcion;

    printf("     *** Campo a modificar ***\n\n");
    printf("------------------------------------\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Precio\n");
    printf("4. Codigo de vuelo\n");
    printf("5. Tipo de pasajero\n");
    printf("6. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int buscarPasajero(ePasajero vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty  && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int modificarPasajero(ePasajero vec[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char auxNombre[50];
    char auxApellido[50];
    char auxCodigo[50];
    float precio;
    int tipo;

    if( vec != NULL && tam > 0)
    {
        listarPasajeros(vec,tam);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( buscarPasajero(vec, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe un pasajero con id: %d en el sistema\n", id);
            }
            else
            {

                switch(menuModificarPasajero())
                {

                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(auxNombre);
                    strcpy(vec[indice].nombre, auxNombre);
                    printf("Nombre modificado!\n");
                    break;
                case 2:
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(auxApellido);
                    strcpy(vec[indice].apellido, auxApellido);
                    printf("Apellido modificado!\n");
                    break;
                case 3:
                    printf("Ingrese nuevo precio: ");
                    scanf("%f", &precio);
                    vec[indice].precio = precio;
                    printf("Precio modificado!\n");
                    break;
                case 4:
                    printf("1. ESP123\n");
                    printf("2. BAS456\n");
                    printf("3. JPN789\n");
                    printf("Ingrese nuevo codigo de vuelo: ");
                    fflush(stdin);
                    gets(auxCodigo);
                    strcpy(vec[indice].codigoVuelo, auxCodigo);
                    printf("Codigo de vuelo modificado!\n");
                    break;

                case 5:
                    printf("1. PRIMERA CLASE\n");
                    printf("2. EJECUTIVO\n");
                    printf("3. TURISTA\n");
                    printf("Ingrese tipo de pasajero:");
                    scanf("%d", &tipo);

                    while(tipo != 1 && tipo != 2 && tipo != 3)
                    {
                        printf("Tipo de pasajero incorrecto. Reingrese tipo de pasajero: ");
                        scanf("%d", &tipo);
                    }
                    vec[indice].tipoPasajero = tipo;
                    printf("Tipo de pasajero modificado!\n");


                    break;
                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int bajaPasajero(ePasajero vec[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if( vec != NULL && tam > 0)
    {
        listarPasajeros(vec,tam);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( buscarPasajero(vec, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe un pasajero con id: %d en el sistema\n", id);
            }
            else
            {

                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja exitosa!!!\n");
                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }

            todoOk = 1;
        }
    }
    return todoOk;
}

int menuInformar()
{
    int opcion;


    printf("     *** Menu de ordenamientos ***\n");
    printf("----------------------------------\n");
    printf("  *** TP 2 - Miceli Ivan Gonzalo ***\n");
    printf("------------------------------------\n\n");
    printf("1. Listado de pasajeros por apellido y tipo de pasajero\n");
    printf("2. Total y promedio de pasajes\n");
    printf("3. Listado de pasajeros por codigo de vuelo y vuelos ACTIVO\n");
    printf("4. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int promedioPasajeros(ePasajero vec[],int tam)
{
    int salida = 0;
    float acumuladorPasajes = 0;
    float promedio;
    int contador = 0;
    int contadorMaximo = 0;

    if( vec != NULL && tam > 0 )
    {
        for(int i=0; i < tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                acumuladorPasajes += vec[i].precio;
                contador++;
            }
        }

        promedio = acumuladorPasajes / contador;

        for(int i=0; i<tam;i++)
        {
          if(vec[i].precio > promedio)
            {
                contadorMaximo++;
            }

        }


        printf("El total de pasajes es %.2f y el promedio de pasajes es %.2f\n",acumuladorPasajes,promedio);
        printf("La cantidad de pasajeros que superan el promedio es de %d\n",contadorMaximo);
        salida = 1;
    }

    return salida;
}
