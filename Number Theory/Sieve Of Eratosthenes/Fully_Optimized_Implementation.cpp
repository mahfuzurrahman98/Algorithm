/*
Fully optimized Sieve, we only check odd numbers to
find primes as we already know even numbers can't be
prime, then why do we check & mark them.......
*/


#include <iostream>
#include <string.h>
#define M 100
using namespace std;

bool isPrime[M + 2];
//'1' is not prime & '2' is prime

void sieve()
{
	// Here we only deal with odd numbers as even numbers are not prime
	// So skip marking them...........
	for (int i = 3; i * i <= M; i += 2)
	{
		if (isPrime[i] == true)
		{
			// i is a prime
			// assume i=3, start jump from i*i=9 at a rate of 2*i=6
			// then possible marking is [9,15,21,27,33,39,.....,99]
			for (int j = i * i; j <= M; j += i + i)
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
	for (int i = 4; i <= M; i += 2)
		isPrime[i] = false; //makes all even numbers not prime expect '2'


	for (int i = 1; i <= M; i++)
		if (isPrime[i])
			cout << i << " ";
}