#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

unsigned long fibonacci(unsigned int n);
unsigned long * fibonacci_array(unsigned int n);

unsigned long * make_copy_of_array(unsigned long src_array [], unsigned int array_dimension);
void swap(unsigned long *x, unsigned long *y);
unsigned long * reverse(unsigned long * array, unsigned int i, unsigned int j);
unsigned long * complete_reverse(unsigned long * array, unsigned int array_len);
void bubble_sort(unsigned long * array, unsigned int array_dimension);

int main(int argc, char *argv[]) {

	//A
	unsigned long a = 0, b = 0;
	unsigned int n = 0;
	while(a <= b){
		a = b;
		b = fibonacci(n);
		n++;
	}
	n--;
	printf("Il massimo valore di n per cui il risultato di fibonacci(n) è accurato è %d, fibonacci(%d) = %lu",n,n,a);

	//C
	unsigned long *fibonacci_result;
	unsigned long *fibonacci_result_copy;

	n = 39;

	fibonacci_result  = fibonacci_array(n);

	fibonacci_result_copy = make_copy_of_array(fibonacci_result, n+1);

	fibonacci_result_copy = complete_reverse(fibonacci_result_copy, n+1);

	bubble_sort(fibonacci_result_copy, n+1);


	printf("\n\nRisultato di bubble_sort():\n");

		for (int i = 0; i < n+1; i++) {
			printf("%lu\t%lu \n", fibonacci_result[i],fibonacci_result_copy[i]);
		}

		printf("\n");

	int result_cmp;

	result_cmp = memcmp(fibonacci_result, fibonacci_result_copy, n*sizeof(unsigned long));

	if(result_cmp == 0){
		printf("Il risultato di memcmp() è 0, quindi i due array sono uguali.\n");
	}
	else{
		printf("ERRORE! I due array sono diversi.\n");
	}


	return 0;
}


/*unsigned long fibonacci(unsigned int n){
	unsigned long f;
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		f = fibonacci(n-1) + fibonacci(n-2);

	return f;
}*/

unsigned long fibonacci(unsigned int n){
	unsigned long f0 = 0, f1 = 1, f;

	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;

	for(int i = 2; i <= n; i++){
		f = f0 + f1;
		f0 = f1;
		f1 = f;
	}
	return f;
}


unsigned long * fibonacci_array(unsigned int n){
	unsigned long *fib_array;

	fib_array = calloc(n+1, sizeof(unsigned long));
	fib_array[1] = 1;

	for(int i = 2; i <= n; i++){
		fib_array[i] = fib_array[i-1] + fib_array[i-2];
	}

	return fib_array;
}



unsigned long * make_copy_of_array(unsigned long src_array [], unsigned int array_dimension) {

	if (src_array == NULL)
		return NULL;

	unsigned long * result;

	result = malloc(array_dimension * sizeof(long));

	if (result == NULL) {
		return NULL;
	}

	memcpy(result, src_array, array_dimension * sizeof(unsigned long));

	return result;
}


void swap(unsigned long *x, unsigned long *y) {
	unsigned long t = *x;
	*x = *y;
	*y = t;
}


unsigned long * reverse(unsigned long * array, unsigned int i, unsigned int j)
{


	while (i < j) {
		j--;
		swap(&array[i], &array[j]);
		i++;
	}

	return array;
}

unsigned long * complete_reverse(unsigned long * array, unsigned int array_len) {
	return reverse(array, 0, array_len);
}

void bubble_sort(unsigned long * array, unsigned int array_dimension){
	int n = array_dimension;
	do{
		int newn = 0;
		for(int i = 1; i < n; i++){
			if(array[i-1] > array[i]){
				swap(&array[i-1], &array[i]);
				newn = i;
			}
		}
		n = newn;
	}while(n>=1);
}
