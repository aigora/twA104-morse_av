//Aránzazu Carnero Tallón (53864); Victoria Jiménez Barbero (54019)
//CÓDIGO MORSE. El usuario introduce el motivo del mensaje (alerta o normal), y el mensaje. 
//El programa revisa que el mensaje este correctamente escrito, y lo traduce a código morse.
//El programa crea un fichero que contiene todas las frases que han sido introducidas durante el mismo, y el motivo de las mismas.
//El traductor se repite hasta que el usuario lo desee.
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#define N 100
struct DATOS {

	int opcion;
	char cad[N], *c;
};
int verificacion(struct DATOS);//verificacion del mensaje introducido por el usuario en la funcion main
void imprimir(struct DATOS);//traduccion del mensaje introducido por el usuario en la funcion main

int main()
{
	struct DATOS datos;
	int correcto;
	FILE *pf;
	errno_t err;
	err = fopen_s(&pf, "LIBRETA.txt", "a+");// fichero que recoge todos los mensajes introducidos por el usuario, y su motivo
	do
	{
		printf("introduce el motivo del mensaje:\n1- mensaje de emergencia\n2-mensaje ordinario\n0-salir del programa\n");
		scanf_s("%d", &datos.opcion);
		fprintf(pf, "%d\t", datos.opcion);
		if (datos.opcion != 0 && datos.opcion != 1 && datos.opcion != 2)
		{
			printf("opcion intriducida no valida, vuelva a intentarlo\n");
		}
		switch (datos.opcion)
		{
		case 1:
			printf("LED rojo ON\n");
			do
			{
				printf("introduzca el mensaje a traducir. Puede escribir los simbolos mas comunes, espacios, y letras minusculas\n");
				getchar();
				gets_s(datos.cad);//introduccion por el usuario del mensaje, para su proxima verificacion y traduccion.
				fprintf(pf, "%s", datos.cad);
				datos.c = (char*)calloc(strlen(datos.cad) + 1, sizeof(char));
				if (datos.cad == NULL)
				{
					printf("NO HAY SUFICIENTE ESPACIO\n");
					exit(-1);
				}
				if (verificacion(datos) == 1)
				{
					imprimir(datos);
				}

			} while (verificacion(datos) == 0);
			break;
		case 2:
			printf("LED verde ON\n");
			do
			{
				printf("introduzca el mensaje a traducir. Puede escribir los simbolos mas comunes, espacios, y letras minusculas\n");
				getchar();
				gets_s(datos.cad);//introduccion por el usuario del mensaje, para su proxima verificacion y traduccion.
				fprintf(pf, "%s", datos.cad);
				datos.c = (char*)calloc(strlen(datos.cad) + 1, sizeof(char));
				if (datos.cad == NULL)
				{
					printf("NO HAY SUFICIENTE ESPACIO\n");
					exit(-1);
				}
				if (verificacion(datos) == 1)
				{
					imprimir(datos);
				}
			} while (verificacion(datos) == 0);
			break;

		}
	} while (datos.opcion != 0);
	fclose(pf);
	system("pause");
}
int verificacion(struct DATOS datos) //funcion para comprobar que el mensaje introducido por el usuario es correcto. Sino, lo vuelve a pedir
{
	int i = 0, correcto = 0;
	while (datos.cad[i] != '\0')
	{
		if (datos.cad[i] >= 'a' && datos.cad[i] <= 'z' || datos.cad[i] >= '0' && datos.cad[i] <= '9' || datos.cad[i] == '.' || datos.cad[i] == ',' || datos.cad[i] == '?' || datos.cad[i] == '"' || datos.cad[i] == '!' || datos.cad[i] == ' ')
		{
			correcto++;
		}
		i++;
	}
	if (correcto == strlen(datos.c))//por cada caracter de la frase bien, sumamos 1 unidad al valor de correcto. si todos los caracteres de la frase estan bien, correcto= longitud frase.
	{
		correcto = 1;
	}
	else
	{
		correcto = 0;
		printf("frase introducida incorrecta, vuelva a intentarlo\n");
	}
	return correcto;
}
void imprimir(struct DATOS datos)//funcion para imprimir por pantalla el codigo morse
{
	int i = 0;
	while (datos.cad[i] != '\0')
	{
		switch (datos.cad[i])
		{
		case 'a':
		{
			printf(".-  ");
			break;
		}
		case 'b':
		{
			printf("-...  ");
			break;
		}
		case 'c':
		{
			printf("-.-.  ");
			break;
		}
		case 'd':
		{
			printf("-..  ");
			break;
		}
		case 'e':
		{
			printf(".  ");
			break;
		}
		case 'f':
		{
			printf("..-.  ");
			break;
		}
		case 'g':
		{
			printf("--.  ");
			break;
		}
		case 'h':
		{
			printf("....  ");
			break;
		}
		case 'i':
		{
			printf("..  ");
			break;
		}
		case 'j':
		{
			printf(".---  ");
			break;
		}
		case 'k':
		{
			printf("-.-  ");
			break;
		}
		case 'l':
		{
			printf(".-..  ");
			break;
		}
		case 'm':
		{
			printf("--  ");
			break;
		}
		case 'n':
		{
			printf("-.  ");
			break;
		}
		case 'o':
		{
			printf("---  ");
			break;
		}
		case 'p':
		{
			printf(".--.  ");
			break;
		}
		case 'q':
		{
			printf("--.-  ");
			break;
		}
		case 'r':
		{
			printf(".-.  ");
			break;
		}
		case 's':
		{
			printf("...  ");
			break;
		}
		case 't':
		{
			printf("-  ");
			break;
		}
		case 'u':
		{
			printf("..-  ");
			break;
		}
		case 'v':
		{
			printf("...-  ");
			break;
		}
		case 'w':
		{
			printf(".--  ");
			break;
		}
		case 'x':
		{
			printf("-..-  ");
			break;
		}
		case 'y':
		{
			printf("-.--  ");
			break;
		}
		case 'z':
		{
			printf("--..  ");
			break;
		}
		case '0':
		{
			printf("-----  ");
			break;
		}
		case '1':
		{
			printf(".----  ");
			break;
		}
		case '2':
		{
			printf("..---  ");
			break;
		}
		case '3':
		{
			printf("...--  ");
			break;
		}
		case '4':
		{
			printf("....-  ");
			break;
		}
		case '5':
		{
			printf(".....  ");
			break;
		}
		case '6':
		{
			printf("-....  ");
			break;
		}
		case '7':
		{
			printf("--...  ");
			break;
		}
		case '8':
		{
			printf("---..  ");
			break;
		}
		case '9':
		{
			printf("----.");
			break;
		}
		case '.':
		{
			printf(".-.-.-  ");
			break;
		}
		case ',':
		{
			printf("--..--  ");
			break;
		}
		case '?':
		{
			printf("..--..  ");
			break;
		}
		case '"':
		{
			printf(".-..-.  ");
			break;
		}
		case '!':
		{
			printf(".-.-.  ");
			break;
		}
		case ' ':
		{
			printf(" ");
			break;
		}
		}
		i++;
	}
	printf("\n");
}
