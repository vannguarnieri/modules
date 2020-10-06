/* list.c --- 
 * 
 * 
 * Author: Francesco V. Guarnieri
 * Created: Mon Oct  5 10:08:12 2020 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "list.h"

#define MAXREG 10

static car_t *front=NULL;

/* put(): place a car at the beginning of the list
 * returns 0 if successful; nonzero otherwise 
 */
int32_t lput(car_t *cp){
  cp->next = front;
	front = cp;
	return 0;
	//should return nonzero somehow?
	//malloc?
}

/* get(): remove and return the first car in the list;
 * return NULL if the list is empty
 */
car_t *lget(){
	if (front == NULL){
		return NULL;
	}
	else {
		car_t *p1, *p2;
 		p1 = front;
		p2 = p1->next;
		front = p2;
		return p1;
	}
}
/* apply a function to every car in the list */
void lapply(void (*fn)(car_t *cp)){
	car_t *p = front;
	car_t *f;
	while (p != NULL){
		printf("p was not null");
		f = p;
		fn(p);
		p = f->next;
	}
}

/* remove(): find, remove, and return any car with
 * the designated plate; return NULL if not present
 */


car_t *lremove(char *platep){
	car_t *p = front;
	car_t *f = NULL;
	while (p != NULL){
		if (strcmp(p->plate, platep) == 0){
			f->next = p->next;
			return p;
		}
		f = p;
		p = p->next;
	}
	return NULL;
}
