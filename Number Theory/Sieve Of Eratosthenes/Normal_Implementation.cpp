/*
Normal and straight-forward immplementation of Sieve Algorithm
*/

#include <iostream>
#include <string.h>
#define M 100
using namespace std;

bool isPrime[M + 2];
//'1' is not prime & '2' is prime

void sieve()
{
	for (int i = 2; i <= M; i++)
	{
		if (isPrime[i] == true)
		{
			// i is a prime
			// assume i=3, start jump from i+i=6 at a rate of i=3
			// then possible marking is [6,9,12,15,18,21,.....,99]
			for (int j = i + i; j <= M; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	memset(isPrime, true, M + 2); //makes all numbers prime
	sieve(); //function call

	isPrime[1] = false; //as '1' is not prime

	for (int i = 1; i <= M; i++)
		if (isPrime[i])
			cout << i << " ";
}