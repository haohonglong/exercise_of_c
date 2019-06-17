#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
 
int main(void)
{
	const size_t N = 100;
	int numbers[N];
	size_t ndx = 0;
	for (; ndx < N; ++ndx)
		numbers[ndx] = ndx;
	printf("SIZE_MAX = %zu\n", SIZE_MAX);
	size_t size = sizeof numbers;
	printf("size = %zu\n", size);
}
