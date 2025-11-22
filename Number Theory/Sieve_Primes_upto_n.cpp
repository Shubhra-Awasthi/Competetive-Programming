// Sieve

vector<int> prime(n + 1, 1);
prime[1] = 0;

for (int i = 2; i <= n; i++)
{
    if (!prime[i])
        continue;

    for (int j = i * i; j <= n; j += i)
    {
        prime[j] = 0;
    }
}

// O(n log log n)

/*
2) Segmented Sieve(Primes from L to R where R-L+1 <= 10^6):
    Generate all Prime Numbers P upto sqrt(R).
    Create an array of R-L+1 size initialized to 0(primes).
    For each P, loop from L to R and mark all its multiple m to be ‘1’.
    At end, you have array from L to R with primes set to ‘0’.
*/