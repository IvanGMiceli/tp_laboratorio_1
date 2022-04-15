/*
 * Contabilizar.c
 *
 *  Created on: 13 abr. 2022
 *      Author: Ivan
 */

#include "Contabilizar.h"
#include <stdio.h>

float calcular(float x, float y){

float resultado;

resultado = 1 * x / y;

return resultado;

}

float recargar(float x){

float precioRecargado;

precioRecargado = x + x * 25 / 100;

return precioRecargado;

}

float restar(float x, float y){

float respuesta;

respuesta = x - y;

return respuesta;

}

float descontar(float x){

float descuento;

descuento= x - x * 10 / 100;

return descuento;

}

float convertir(float x){

float precioConvertido;

precioConvertido = x * 1 / 4606954.55;

return precioConvertido;

}

void cargar()
{
    float kmBase = 7090;
    float precioAeroBase = 162965;
    float precioLatamBase = 159339;

    printf("\nKMs ingresados: %.2f km\n", kmBase);
    fflush(stdin);

    printf("\nPrecio de Aerolineas Argentinas: $ %.2f\n", precioAeroBase);
    printf("a) Precio con tarjeta de debito: $ %.2f\n", descontar(precioAeroBase));
    printf("b) Precio con tarjeta de credito: $ %.2f\n", recargar(precioAeroBase));
    printf("c) Precio pagando con bitcoin: $ %f BTC\n", convertir(precioAeroBase));
    printf("d) Mostrar precio unitario: $ %.2f\n", calcular(precioAeroBase, kmBase));


    printf("\nPrecio de Latam: $%.2f\n", precioLatamBase);
    printf("a) Precio con tarjeta de debito: $ %.2f\n", descontar(precioLatamBase));
    printf("b) Precio con tarjeta de credito: $ %.2f\n", recargar(precioLatamBase));
    printf("c) Precio pagando con bitcoin: $ %f BTC\n", convertir(precioLatamBase));
    printf("d) Mostrar precio unitario: $ %.2f\n", calcular(precioLatamBase, kmBase));

    printf("\nLa diferencia de precio es: $ %.2f\n", restar(precioAeroBase, precioLatamBase));
}
