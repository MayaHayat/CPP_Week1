/**
 * Demo program for ADT exercise.
 * 
 * Author: Evgeny Hershkovitch Neiterman
 * Since : 2023-02
 */

#include "AdptArray.h"
#include "book.h"
#include "Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main() {

	pbook bookA = creat_book("The Hunger Games",2008);
	pbook bookB= creat_book("1984",1949);
	pbook bookC= creat_book("Mecbeth",1623) ;

	PAdptArray mybooks = CreateAdptArray(copy_book,delete_book,print_book);
	SetAdptArrayAt(mybooks,3,bookA);
	SetAdptArrayAt(mybooks,5,bookB);
	SetAdptArrayAt(mybooks,9,bookC);

	printf("\nthe size is %d\n",GetAdptArraySize(mybooks)); 
	pbook check = GetAdptArrayAt(mybooks,4); 
	assert(check==NULL);

	check = GetAdptArrayAt(mybooks,3);
	printf("the name of the book in the third place is: %s\n",check->name); 
	assert(check->serial_number == 2008);

	check = GetAdptArrayAt(mybooks,9);
	printf("the year of publication of the book in the ninth place is: %d\n",check->serial_number); 

	assert(check->serial_number == 1623);

	printf("\n------Trying out the PRINTDB function-----\n");
	PrintDB(mybooks);

	printf("\n");

	pperson personA = creat_person("Bruce","Banner", 1050);
	pperson personB = creat_person("Peter","Parker", 73451);
	pperson personC = creat_person("Bruce","Wayne", 1234567);

	PAdptArray SuperHeros = CreateAdptArray(copy_person,delete_person,print_person);
	SetAdptArrayAt(SuperHeros,1,personA);
	SetAdptArrayAt(SuperHeros,2,personB);
	SetAdptArrayAt(SuperHeros,12,personC);
	SetAdptArrayAt(SuperHeros,15,personC); // entring the same book twice

	pperson check2 = GetAdptArrayAt(SuperHeros,1);
	assert(check2->id == 1050);

	printf("\nthe size is %d\n",GetAdptArraySize(SuperHeros)); // prints 9


	printf("\n------Trying out the PRINTDB function-----\n");
	PrintDB(SuperHeros); 



// ----------- freeing space at least --  checked using the make tidy at the end!
	DeleteAdptArray(mybooks);
	DeleteAdptArray(SuperHeros);
	delete_book(bookA);
	delete_book(bookB);
	delete_book(bookC);

	delete_book(check);
	delete_person(personA);
	delete_person(personB);
	delete_person(personC);
	
	return 0;

	
}
