#include <iostream>


	
int main() {
   /* printf ("What is your name?\n");
	char name[20];
	scanf ("%s", name) ;
	printf ("Hello,%s",name) ;*/
	unsigned int a,prime;
	do
	{
	
	printf ("Write a positive number:\n") ;
	scanf ("%i",&a);
	}
    while (a<=0) ;
    prime = 2 ;
			printf ("This number is consists of these prime numbers:" ) ;
	while (a>=prime)
		{ while (a % prime == 0) 
			{ a = a/prime ;
			printf("%i ", prime) ;
			}
		prime++ ;
		}
	return 0;
}
