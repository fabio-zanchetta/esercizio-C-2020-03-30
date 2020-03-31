#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

unsigned long fibonacci(unsigned int n);
unsigned long * fibonacci_array(unsigned int n);

int main(int argc, char *argv[]) {

	//A
	unsigned long a = 0, b = 0, n = 0;
	while(a <= b){
		a = b
		b = fibonacci(n)
		n++;
	}
	n--;
	printf("Il massimo valore di n per cui il risultato di fibonacci(n) è accurato è %lu",n);
	
	//B
	return 0;
}


unsigned long fibonacci(unsigned int n){
	unsigned long f;
	if(n = 0)
		return 0;
	else if(n = 1)
		return 1;
	else
		f = fibonacci(n-1) + fibonacci(n-2);
	
	return f;
}


unsigned long * fibonacci_array(unsigned int n){
	unsigned long *fib_array;
	
	fib_array = calloc(n+1, sizeof(unsigned long);
