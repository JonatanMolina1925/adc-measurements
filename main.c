//Jonatan Ali Medina Molina
//6/03/2023
//Mediciones con el ADC usando C
//ADC0 <----- input
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ADC0 "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"
int main(int argc, char *argcc[]){
	printf("Script ejecutandose\n");
	FILE *fp;
	fp = fopen(ADC0, "rt");
	char reads[80];
	fgets(reads, 20, fp);
	printf("%s", reads);
	return 0;
}
