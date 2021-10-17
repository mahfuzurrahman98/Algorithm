#include <bits/stdc++.h>
#define M 100
using namespace std;

bitset < M + 2 > isPrime;

vector<int> primes;
vector<pair<int, int>> divs;
//'1' is not prime & '2' is prime

void sieve()
{
	isPrime.set();
	// Here we only deal with odd numbers as even numbers are not prime
	// So skip marking them...........
	for (int i = 3; i * i <= M; i += 2)
	{
		if (isPrime[i] == 1)
		{
			// i is a prime
			// assume i=3, start jump from i*i=9 at a rate of 2*i=6
			// then possible marking is [9,15,21,27,33,39,.....,99]
			for (int j = i * i; j <= M; j += i + i)
			{
				isPrime[j] = 0;
			}
		}
	}

	primes.push_back(2);
	for (int i = 3; i <= M; i += 2) {
		if (isPrime[i]) {
			primes.push_back(i);
		}
	}
}

int countDivs(int n)
{
	int divi = 1, cnt;
	for (int i = 0; primes[i]*primes[i] <= n; i++)
	{
		if (n % primes[i] == 0)
		{

			cnt = 1;
			while (n % primes[i] == 0)
			{
				cnt++;
				n /= primes[i];
			}
			divi *= cnt;
			divs.push_back({primes[i], cnt - 1});
		}
	}
	cout << "last n: " << n << endl;
	if (n > 1) {
		divi *= 2;
		divs.push_back({n, 1});
	}
	return divi;
}

int main() {
	bs.set();
	cout << bs[1] << endl;
	sieve();
	/*for (int x : primes) {
		cout << x << " ";
	}
	cout << endl;*/
	cout << countDivs(60) << endl;
	for (pair<int, int> pp : divs) {
		cout << pp.first << " ^ " << pp.second << " = " << powl(pp.first, pp.second) << endl;
	}
}

/*
1
2
3
4
5
6
10
12
15
20
30
60
Total = 12 divisors


  2^2 x 3^1 x 5^1
= 4 x 3 x 5
= 60

2's power is 2
3's power is 1
5's power is 1

  (2's power + 1) x (2's power + 1) x (2's power + 1)
= (2 + 1) x (1 + 1) x (1 + 1)
= 3 x 2 x 2
= 12
Total = 12 divisors
*/