/*
 * operaciones.c
 *
 *  Created on: 11 sep. 2021
 *      Author: Meli
 */
#include <stdio.h>
#include <stdlib.h>

void getMyFloat(float* num)
{
	int estado=0;

	printf("Ingresa un número: \n");
	estado=scanf("%f", num);

	while(estado!= 1)
	{
		printf("Error - Ingresa un número valido: \n");
		fflush(stdin);
		estado=scanf("%f", num);
	}
}
void sumar(float numUno, float numDos,float* resultadoS)
{
       *resultadoS=numUno+numDos;
}

void restar(float numUno, float numDos, float* resultadoD)
{
        *resultadoD=numUno+numDos;
}

int dividir(float dividendo,float divisor,float* pResultado)
{
        int estado;

        if(divisor!=0){
            estado=0;
            *pResultado=dividendo/divisor;
        }
        else{
            estado=1;
        }

        return estado;
}

void multiplicar(float primerNumero,float segundoNumero,float*multiplicacionR)
{
       *multiplicacionR=primerNumero*segundoNumero;

}

int factorial(int num, float* resultado)
{
		int numFact=1;
		int i;
		int estado=1;

		if(num>0){
			for(i=num; i>1; i--)
			{
				numFact = numFact * i;
			}

			*resultado=numFact;
			estado=0; //Aca devolvemos el valor del factoreo en la dirección de Resultado.
		}else{

			if(num==0)
			{
				*resultado=1;
				estado=0;
			}
		}

	return estado;
}










