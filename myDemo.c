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
	SetAdptArrayAt(mybooks,9,bookB);

	printf("the size is %d\n",GetAdptArraySize(mybooks));  //should print 6
	pbook b = GetAdptArrayAt(mybooks,4); // should return null;
	assert(b==NULL); // doesn't fail
	b = GetAdptArrayAt(mybooks,3);
	printf("the book is %s\n",b->name); //should print "Harry Potter"
	PrintDB(mybooks);

	pperson p1 = creat_person("Harry","Potter", 934);
	pperson p2 = creat_person("Ron","Weasley", 789);
	PAdptArray HP_caracters = CreateAdptArray(copy_person,delete_person,print_person);
	SetAdptArrayAt(HP_caracters,2,p1);
	SetAdptArrayAt(HP_caracters,8,p2);
	printf("the size is %d\n",GetAdptArraySize(HP_caracters)); // prints 9
	PrintDB(HP_caracters); // prints:
	//first name: Harry last name: Potter id: 934
        //first name: Ron last name: Weasley id: 789
	
	DeleteAdptArray(mybooks);
	DeleteAdptArray(HP_caracters);
	delete_book(bookA);
	delete_book(bookB);
	delete_book(bookC);

	delete_book(b);
	delete_person(p1);
	delete_person(p2);
	return 0;
}
