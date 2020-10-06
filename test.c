/* test.c --- 
 * 
 * 
 * Author: Francesco V. Guarnieri
 * Created: Mon Oct  5 11:21:33 2020 (-0400)
 * Version: 
 * 
 * Description: Tests all possible error cases for car list
 * 
 * From module 3 Question 1
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "list.h"


#define MAXREG 10

car_t *make_car(char *platep, double price, int year){
	car_t *car;
	if (!(car = (car_t*)malloc(sizeof(car_t)))) {
		return NULL;
	}
	strcpy(car->plate, platep);
	car->price = price;
	car->year = year;
	car->next = NULL;
	return car;
}

void printcar(car_t *car) {
	if (car == NULL){
		printf ("Car is null");
	}
	else{
		printf("Plate number is %s\n", car->plate);
		printf("Price is %f\n", car->price);
		printf("Year is %d\n", car->year);
	}
}
								
int main(int argc, char *argv[]) {

	car_t *car0 = make_car("000000", 10000, 2000);
	car_t *car1 = make_car("111111", 11000, 2001);
	car_t *car2 = make_car("222222", 12000, 2002);
  printcar(car0);
	//	lput(car0);
	lput(car1);
	//lput(car2);
	//lapply(&printcar);
	printf("...");
	lremove("111111");
	//lremove("000000");
	//printf("all but 222222 got removed...hopefully");
	//lapply(&printcar);
	//lremove("222222");
	//printf("all got removed...hopefully");
	lapply(printcar);
	
}


