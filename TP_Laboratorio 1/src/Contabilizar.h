/*
 * Contabilizar.h
 *
 *  Created on: 13 abr. 2022
 *      Author: Ivan
 */

#ifndef CONTABILIZAR_H_
#define CONTABILIZAR_H_



#endif /* CONTABILIZAR_H_ */


/** \brief suma el recargo sobre una variable flotante
 *
 * \param float precio del vuelo inicial
 * \return float precio del vuelo con el recargo del 25%
 *
 */

float recargar(float);

/** \brief saca el porcentaje de un valor flotante
 *
 * \param  float precio del vuelo inicial
 * \return float devuelve el precio con el descuento del 10%
 *
 */

float descontar(float);

/** \brief convierte una variable flotante de peso arg. a moneda bit coin
 *
 * \param float precio del valor ingresado en pesos
 * \return float convierte el valor ingresado en pesos a BTC
 *
 */

float convertir(float);

/** \brief saco el valor unitario del precio por kilometro
 *
 * \param x float valor del vuelo ingresado
 * \param y float valor de la cantidad de kilometros ingresada
 * \return float devuelve el valor unitario
 *
 */

float calcular(float x, float y);

/** \brief resta de dos valores flotantes
 *
 * \param float valor del vuelo de aerolineas argentinas
 * \param float valor del vuelo de latam
 * \return float diferencia de precio entre ambas variables
 *
 */

float restar(float x, float y);

/** \brief muestra los printf con los datos hardcodeados
 *
 * \return void devuelve los datos calculados de la carga forzada
 *
 */
void cargar();


