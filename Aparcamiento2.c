#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main() {

	int i = 0, opcion2;
	char opcion, matricula[8], matricula2[8], plaza1 = 0, plaza2 = 0, matricula3[8], opciontipo;

	while (i == 0) {

		printf("Seleccione que accion desea realizar:\n");
		printf("Seleccione R para reservar una plaza.\n");
		printf("Seleccione A para abandonar su plaza.\n");
		printf("Seleccione E para ver el estado de su plaza.\n");
		printf("Seleccione B para buscar un coche por su matricula\n");
		printf("Seleccione S para salir del programa\n");
		scanf_s("%c", &opcion, 1);

		system("cls");

		switch (opcion) {

		case 'R':
		case 'r':
			printf("Ha elegido reservar una plaza.\n");
			printf("Moto (M) o coche (C)\n");
			getchar();
			scanf_s("%c", &opciontipo, 1);

			switch (opciontipo) {
			case 'M':
			case 'm':
				if (plaza1 == 0) {
					printf("Ha elegido plaza de moto. Se le asigna la plaza 1\n");
					printf("Introduzca la matricula de su moto:\n");
					scanf_s("%s", matricula, 8);
					plaza1 = plaza1 + 1;
					printf("Su plaza ha sido reservada\n");
				}
				else if (plaza1 == 1) {
					printf("No hay plazas de moto libres. Vuelva mas tarde\n");
				}
				break;

			case 'C':
			case 'c':
				if (plaza2 == 0) {
					printf("Ha elegido plaza de coche. Se le asigna la plaza 2\n");
					printf("Introduzca la matricula de su coche:\n");
					scanf_s("%s", matricula2, 8);
					plaza2 = plaza2 + 1;
					printf("Su plaza ha sido reservada\n");
				}
				else if (plaza2 == 1) {
					printf("No hay plazas de coche libres. Vuelva mas tarde\n");
				}
				break;
			}
			break;

		case 'A':
		case 'a':
			printf("Ha elegido abandonar su plaza.\n");

			if (plaza1 == 0 && plaza2 == 0) {
				printf("No hay plazas ocupadas.\n");
			}
			else {
				printf("Elija la plaza que desea abandonar\n");
				scanf_s("%d", &opcion2);

				switch (opcion2) {

				case 1:
					if (plaza1 == 0) {
						printf("No hay ningun coche en la plaza 1.\n");
					}
					else if (plaza1 == 1) {
						plaza1 = plaza1 - 1;
						printf("Has abandonado la plaza 1.\n");
					}
					break;

				case 2:
					if (plaza2 == 0) {
						printf("No hay ningun coche en la plaza 2.\n");
					}
					else if (plaza2 == 1) {
						plaza2 = plaza2 - 1;
						printf("Has abandonado la plaza 2.\n");
					}
					break;
				}
			}
			break;

		case 'E':
		case 'e':
			printf("Ha elegido ver el estado del aparcamiento\n");
			if (plaza1 == 0 && plaza2 == 0) {
				printf("Plaza 1 (moto) - LIBRE\n");
				printf("Plaza 2 (coche) - LIBRE\n");
			}
			else if (plaza1 == 1 && plaza2 == 0) {
				printf("Plaza 1 (moto) - OCUPADA por %s\n", matricula);
				printf("Plaza 2 (coche) - LIBRE\n");
			}
			else if (plaza1 == 0 && plaza2 == 1) {
				printf("Plaza 1 (moto) - LIBRE\n");
				printf("Plaza 2 (coche) - OCUPADA por %s\n", matricula2);
			}
			else {
				printf("Plaza 1 (moto)- OCUPADA por %s\n", matricula);
				printf("Plaza 2 (coche)- OCUPADA por %s\n", matricula2);
			}
			break;

		case 'B':
		case 'b':
			printf("Introduce la matricula del coche a buscar\n");
			scanf_s("%s", matricula3, 8);

			if (strcmp(matricula3, matricula) == 0) {
				printf("El coche se encuentra en la plaza 1\n");
			}
			else if (strcmp(matricula3, matricula2) == 0) {
				printf("El coche se encuentra en la plaza 2\n");
			}
			else {
				printf("El coche no se encuentra en el aparcamiento\n");
			}
			break;

		case 'S':
		case 's':
			printf("Ha elegido salir del programa\n");
			i = 1;
			break;

		default: printf("No ha introducido ninguna de las opciones.\n");
		}

	system("PAUSE");
	system("cls");
	getchar();
	}
}
