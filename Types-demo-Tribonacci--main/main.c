#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

double triDoubleLoop(double n)
{
	double n0 = 0.0, n1 = 0.0, n2 = 1.0, tri;
	if (n == 0.0 || n == 1.0)
	{
		return n0;
	}
	else if (n == 2.0)
	{
		return n2;
	}
	else
	{
		for(int i=3; i<=(int)n; i++)
		{
			tri = n0 + n1 + n2;
			n0 = n1;
			n1 = n2;
			n2 = tri;
		}
		return n2;
	}
}

unsigned long long triIntLoop(unsigned long long n)
{
	unsigned long long n0 = 0, n1 = 0, n2 = 1, tri;
	if (n == 0 || n == 1)
	{
		return n0;
	}
	else if (n == 2)
	{
		return n2;
	}
	else
	{
		for(int i=3; i<=(int)n; i++)
		{
			tri = n0 + n1 + n2;
			n0 = n1;
			n1 = n2;
			n2 = tri;
		}
		return n2;
	}
}

void convertTri(unsigned long long n, double triDouble)
{

	printf("16bit Tribonacci %hu\n", (unsigned short int)n);
	printf("32bit Tribonacci %u\n", (unsigned int)n);
	printf("64bit Tribonacci %llu\n", n);
	printf("Float Tribonacci %.6e\n", (float)triDouble);
	printf("Double Tribonacci %.6e\n", triDouble);


}


int main()
{
	char userInput[1024];
	int number;

    printf("Tribonacci! Type in a positive tribonacci input:\n");
	fgets(userInput,1024,stdin);

	if (*userInput == '\n')
	{
		number = 1;
	}
	else
	{
		number = atoi(userInput);
	}

	for (size_t i = 0; i < strlen(userInput); i++)
	{
		if (isalpha(userInput[i]))
		{
			printf("Invalid input!\n");
			return 1;
		}
		
	}
	
	if (number < 0 || number > 1023)
	{
		printf("Invalid input!\n");
		return 1;
	}

	unsigned long long triLong = triIntLoop((unsigned long long)number);
	double triDouble = triDoubleLoop((double)number);

	convertTri(triLong, triDouble);

    return 0;
}
