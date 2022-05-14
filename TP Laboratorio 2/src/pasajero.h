/*
 * pasajero.h
 *
 *  Created on: 14 may. 2022
 *      Author: Ivan
 */

#ifndef PASAJERO_H_
#define PASAJERO_H_

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float precio;
    char codigoVuelo[10];
    int tipoPasajero;
    int estadoVuelo;
    int isEmpty;

} ePasajero;

#endif /* PASAJERO_H_ */

//------------------------------------OPCIONES DE MENU Y SUBMENU------------------------------------


/** \brief Menu inicial de opciones para gestionar pasajeros.
 *
 * \return int devuelve un entero como opcion la seleccionada.
 *
 */
int menuPasajeros();

/** \brief Menu para modificar cualquier dato del pasajero.
 *
 * \return int devuelve un entero como la opcion seleccionada.
 *
 */

int menuModificarPasajero();

/** \brief submenu para elegir informes
 *
 * \return int devuelve un entero como la opcion seleccionada.
 *
 */
int menuInformar();

//------------------------------------AMB DE PASAJEROS-------------------------------------

/** \brief verifica la primera posicion libre para asigar al pasajero que se ingrese
 *
 * \param vec[] ePasajero array de pasajeros donde se asignara el ingreso deseado
 * \param tam int tamaño del array de pasajeros declarado
 * \param pIndice int* puntero a indice i donde se asiganara al pasajero ingresado una vez se corrobore que este vacio
 * \return int devuelve 0 si hubo ERROR o 1 si fue exitoso
 *
 */
int buscarPasajeroLibre(ePasajero vec[], int tam,int* pIndice);

/** \brief muestra los datos del pasajero en fila
 *
 * \param pas ePasajero imprime los datos de cada campo de la estructura con un printf
 * \return void no retorna nada
 *
 */
void mostrarPasajero(ePasajero pas);

/** \brief inicializa al pasajero para saber si la posicion i del array donde se guardaran los datos esta libre
 *
 * \param vec[] ePasajero array de pasajeros donde se verifica si hay una posicion ocupada
 * \param tam int tamaño del array de pasajeros declarado
 * \return int devuelve -1 si hubo ERROR o 0 si fue exitoso
 *
 */
int inicializarPasajero(ePasajero vec[],int tam);

/** \brief permite el ingreso de datos de un pasajero
 *
 * \param vec[] ePasajero array de pasajeros donde se guardaran los datos que se solicite al usuario
 * \param tam int tamaño del array de pasajeros declarado
 * \param pProximoId int* puntero a entero donde se inicializara el primer id disponible para guardar al pasajero ingresado
 * \return int devuelve -1 si hubo ERROR o 0 si fue exitoso
 *
 */
int altaPasajero(ePasajero vec[], int tam, int* pProximoId);

/** \brief permite la busqueda del pasajero por ID
 *
 * \param vec[] ePasajero array de pasajeros donde se asignara el ingreso deseado
 * \param tam int tamaño del array de pasajeros declarado
 * \param id int compara el id buscado por el que coincida dentro del array
 * \param pIndex int* int* puntero a indice i donde se asiganara al pasajero ingresado una vez se corrobore que este vacio
 * \return int devuelve 0 si hubo ERROR o 1 si fue exitoso
 *
 */
int buscarPasajero(ePasajero vec[], int tam, int id, int* pIndex);


/** \brief permite ña baja de pasajeros hardcodeados o ingresados filtrado por ID
 *
 * \param vec[] ePasajero array de pasajeros donde se guardaron los datos solicitados
 * \param tam int tamaño del array de pasajeros
 * \return int devuelve 0 si hubo ERROR o 1 si fue exitoso
 *
 */
int bajaPasajero(ePasajero vec[], int tam); // PUNTO 2.4 HECHO

/** \brief permite el ingreso de datos de pasajeros hardcodeados
 *
 * \param vec[] ePasajero array de pasajeros donde se guardaron los datos solicitados
 * \param tam int tamaño del array de pasajeros
 * \param cantidad int cantidad de pasajeros del array que se cargan para mostrar
 * \param pProximoId int* puntero donde se inicializara el primer id disponible para guardar al pasajero hardcodeado
 * \return int devuelve -1 si hubo ERROR o 0 si fue exitoso
 *
 */

int hardcodearPasajeros(ePasajero vec[], int tam, int cantidad,int* pProximoId);

/** \brief permite modificar nombre, apellido, precio de vuelo, tipo de pasajero y codigo de vuelo
 *
 * \param vec[] ePasajero array de pasajeros donde se guardaron los datos solicitados
 * \param tam int tamaño del array de pasajeros
 * \return int devuelve 0 si hubo ERROR o 1 si fue exitoso
 *
 */
int modificarPasajero(ePasajero vec[], int tam);

//--------------------------------------INFORMES DE ORDENAMIENTO----------------------------------------

/** \brief Permite listar a los pasajeros ingresados por usuario o hardcodeados
 *
 * \param vec[] ePasajero array de pasajeros donde se guardaron los datos solicitados
 * \param tam int tamaño del array de pasajeros
 * \return int devuelve -1 si hubo ERROR o 0 si fue exitoso
 *
 */
int listarPasajeros(ePasajero vec[],int tam);  // PUNTO 2.6 - HECHO

/** \brief lista y ordena a los pasajeros por su apellido de manera alfabetica y por tipo de pasajero
 *
 * \param vec[] ePasajero array de pasajeros donde se guardaron los datos solicitados
 * \param tam int tamaño del array de pasajeros
 * \param criterio int e ordena por criterio ASC 1 o DESC 0
 * \return int int devuelve -1 si hubo ERROR o 0 si fue exitoso
 *
 */
int ordenarTipoPasajeroApellido(ePasajero vec[], int tam, int criterio);


/** \brief lista y ordena a los pasajeros por su codigo de vuelo
 *
 * \param vec[] ePasajero array de pasajeros donde se guardaron los datos solicitados
 * \param tam int tamaño del array de pasajeros
 * \param criterio int se ordena por criterio ASC 1 o DESC 0
 * \return int int devuelve -1 si hubo ERROR o 0 si fue exitoso
 *
 */
int ordenarCodigoVuelo(ePasajero vec[], int tam, int criterio);

/** \brief Calcula el promedio y el total de los pasajes y total de pasajeros que superan el promedio
 *
 * \param vec[] ePasajero array de pasajeros donde se guardaron los datos solicitados
 * \param tam int tamaño del array de pasajeros
 * \return int int devuelve 0 si hubo ERROR o 1 si fue exitoso
 *
 */
int promedioPasajeros(ePasajero vec[],int tam);

