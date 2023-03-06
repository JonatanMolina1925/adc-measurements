//Jonatan Ali Medina Molina
//6/03/2023
//Mediciones con el ADC usando C
//ADC0 <----- input
/*
*	Descripcion:
 *	- [x] ADC0 test
 *	- [x] print ADC0 9 veces
 *	- [x] pass the n as argument
 *	- [x] print ADC0 n veces
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define ADC0 "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"
int main(int argc, char *argv[]){
	printf("Script ejecutandose\n");
	int i;
	//Cuando los argumentos no son dos
	if(argc != 2){
		printf("No. de argumentos: %d\n", argc);
		printf("El comando es: ./adc n\n");
		printf("Donde n es el numero de lecturas\n");
		return 2;
	}
	//Convertir el argumento a entero
	int Nmes =strtol(argv[1], NULL, 10);
	printf("No. de repeticiones: %d\n", Nmes);	
	FILE *fp;
	char reads[80];
	//Ciclos de n lecturas
	for(i = 0; i < Nmes; i++){		
		fp = fopen(ADC0, "rt");
		fgets(reads, 20, fp);
		printf("%s", reads);
		sleep(1);
	}
	return 0;
}
