#include<stdio.h>
#include<stdlib.h>

void main() {

	char opcion, matricula[8], matricula2[8], plaza1 = 0, plaza2 = 0;
	int opcion2;

	while (1) {

		printf("Seleccione que accion desea realizar:\n");
		printf("Seleccione R para reservar una plaza.\n");
		printf("Seleccione A para abandonar su plaza.\n");
		printf("Seleccione E para ver el estado de su plaza.\n");
		scanf_s("%c", &opcion, 1);

		system("cls");
	
		switch (opcion) {

		case 'R':
		case 'r':
			printf("Ha elegido reservar una plaza.\n");

			if(plaza1 == 0) {
				printf("Se le asigna la plaza 1\n");
				printf("Introduzca la matricula de su vehiculo:\n");
				scanf_s("%s", matricula, 8);
				plaza1 = plaza1 + 1;
				printf("Su plaza ha sido reservada\n");
			}
			else if (plaza2 == 0) {
				printf("Se le asigna la plaza 2\n");
				printf("Introduzca la matricula de su vehiculo:\n");
				scanf_s("%s", matricula2, 8);
				plaza2 = plaza2 + 1;
				printf("Su plaza ha sido reservada\n");
			}
			else {
				printf("No quedan plazas libres, vuelva mas tarde\n");
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
				scanf_s("%c", &opcion2); 

				switch (opcion2) {

				case '1':
					if (plaza1 == 0) {
						printf("No hay ningun coche en la plaza 1.\n");
					}
					else if (plaza1 == 1) {
						plaza1 = plaza1 - 1;
						printf("Has abandonado la plaza 1.\n");
					}
					break;

				case '2':
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
				printf("Plaza 1 - LIBRE\n");
				printf("Plaza 2 - LIBRE\n");
			}
			else if (plaza1 == 1 && plaza2 == 0) {
				printf("Plaza 1 - OCUPADA por %s\n", matricula);
				printf("Plaza 2 - LIBRE\n");
			}
			else if (plaza1 == 0 && plaza2 == 1) {
				printf("Plaza 1 - LIBRE\n");
				printf("Plaza 2 - OCUPADA por %s\n", matricula2);
			}
			else {
				printf("Plaza 1 - OCUPADA por %s\n", matricula);
				printf("Plaza 2 - OCUPADA por %s\n", matricula2);
			}
			break;

		default: printf("No ha introducido ninguna de las opciones.\n");
		}
		system("PAUSE");
		system("cls");
		getchar();	
	}
}
