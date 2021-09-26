/*
 ============================================================================
 Name        : trabajoPracticoUno.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir*/

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int subOpcion = 0;

	float primerNumero;
	float segundoNumero;

	float sumaR;
	float restaR;
	float divisionR;
	float multiplicacionR;
	float factUnoR;
	float factDosR;

	int estadoUno=1;
	int estadoDos=1;
	int estadoR=1;
	int estadoDivision=1;
	int estadoFactUno=1;
	int estadoFactDos=1;



	do{


		printf("\nM e n u : \n\t  1)Ingresar 1er operando: (A=x)\n\t 2) Ingresar 2do operando: (B=y)\n\t 3) Calcular todas las operaciones \n\t 4) Informar resultados \n\t 5) Salir\n");

		scanf("%d", &opcion);

		switch(opcion){

			case 1: getMyFloat(&primerNumero);

						if(estadoDos==1){

							printf("Es necesario que ingrese el segundo número para seguir operando\n ¿Desea agregar el segundo operando?\n\t 1) Si - 2) No\n");
							scanf("%d",&subOpcion);

								while(subOpcion!=1&&subOpcion!=2){

									printf("Es necesario que ingrese el segundo número para seguir operando\n Ingrese: \n1)Si - 2) No\n");
									fflush(stdin);
									scanf("%d",&subOpcion);

								}

								if(subOpcion == 1){

									getMyFloat(&segundoNumero);
									estadoDos=0;

								}
						}


					estadoR=1;

					subOpcion=0;

					estadoUno=0;

					break;

			case 2: getMyFloat(&segundoNumero);

							if(estadoUno==1){

								printf("Es necesario que ingrese el primer número para seguir operando\n ¿Desea agregar el primer operando?\n\t 1) Si - 2) No\n");
								scanf("%d",&subOpcion);

									while(subOpcion!=1&&subOpcion!=2){

										printf("Es necesario que ingrese el primer número para seguir operando\n Ingrese: \n1)Si - 2) No\n");
										fflush(stdin);
										scanf("%d",&subOpcion);

									}

									if(subOpcion == 1){

										getMyFloat(&primerNumero);
										estadoUno=0;

									}
							}

						estadoR=1;

						subOpcion=0;

						estadoDos=0;
						break;
			case 3:
					if(estadoUno!=1&&estadoDos!=1){

						sumar(primerNumero,segundoNumero,&sumaR);

						restar(primerNumero,segundoNumero,&restaR);

						multiplicar(primerNumero,segundoNumero,&multiplicacionR);

						estadoDivision = dividir(primerNumero,segundoNumero,&divisionR);

						estadoFactUno = factorial(primerNumero,&factUnoR);

						estadoFactDos = factorial(segundoNumero,&factDosR);

						printf("\n Calculo de operaciones exitosa ! \n");

						estadoR=0;
					}else{
							if(estadoUno==1&&estadoDos==1){

								printf("\nNo ingreso ningun número, Es necesario que ingrese números para seguir operando\n ");

							}else{
								if(estadoUno==1){

									printf("\n Es necesario que ingrese el primer número para seguir operando.\n");

								}else{

									printf("\nEs necesario que ingrese el segundo número para seguir operando\n");

								}
							}
					}
					break;

			case 4:
					if(estadoR==0){

						printf("\nA continuación informaremos los resultados: \n ");

						printf("\nEl resultado de %.2f + %.2f es : %.2f \n",primerNumero,segundoNumero,sumaR);

						printf("\nEl resultado de %.2f - %.2f es : %.2f \n",primerNumero,segundoNumero,restaR);

						if(estadoDivision==0){

							printf("\nEl resultado de %.2f / %.2f es : %.2f \n",primerNumero,segundoNumero,divisionR);

							}else{

								printf("\nNo es posible dividir por cero\n");

							}

						printf("\nEl resultado de %.2f * %.2f es : %.2f \n",primerNumero,segundoNumero,multiplicacionR);


						if(estadoFactUno==0){

							printf("\nEl factorial de %fes:%f\n",primerNumero,factUnoR);

							}else{

								printf("\nNo es posible obtener el factorial del primer operando\n");

							}

						if(estadoFactDos==0){

							printf("\nEl factorial de %f es : %f\n",segundoNumero,factDosR);

							}else{

								printf("\nNo es posible obtener el factorial del segundo operando\n");

							}

						}else{


							if(estadoUno==1&&estadoDos==1){

								printf("\nNo ingreso ningun número, Es necesario que ingrese números para seguir operando\n ");

							}else{
								if(estadoUno==1){

									printf("\n Es necesario que ingrese el primer número para seguir operando.\n");

								}else{

									printf("\nEs necesario que ingrese el segundo número para seguir operando\n");

								}
							}

						}
					break;
			case 5:
					estadoUno=1;
					estadoDos=1;
					estadoR=1;
					estadoDivision=1;
					estadoFactUno=1;
					estadoFactDos=1;

					break;

			default:

				 printf("\nLa opción ingresada es incorrecta, intente nuevamente \n");

		}


	}while(opcion != 5);


	return EXIT_SUCCESS;
}
