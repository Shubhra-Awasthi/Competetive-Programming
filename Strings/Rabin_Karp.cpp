// (Monte Carlo version with 10 hash functions)
// O(n + m)
// use for multiple pattern searches to reduce collision probability

void rabinKarpMultiHash(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    vector<long long> primes = {31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
    vector<long long> moduli = {1e9 + 7, 1e9 + 9, 1e9 + 21, 1e9 + 33, 1e9 + 87, 1e9};

    int numHashes = primes.size();
    vector<long long> patternHashes(numHashes, 0);
    vector<long long> textHashes(numHashes, 0);
    vector<long long> h(numHashes, 1);

    // Calculate powers of primes for hash rolling
    for (int i = 0; i < numHashes; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            h[i] = (h[i] * primes[i]) % moduli[i];
        }
    }

    // Calculate initial hash for pattern and first text window
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < numHashes; j++)
        {
            patternHashes[j] = (patternHashes[j] * primes[j] + pattern[i]) % moduli[j];
            textHashes[j] = (textHashes[j] * primes[j] + text[i]) % moduli[j];
        }
    }

    // Rolling hash loop
    for (int i = 0; i <= n - m; i++)
    {
        bool match = true;

        // Compare hashes for current window
        for (int j = 0; j < numHashes; j++)
        {
            if (patternHashes[j] != textHashes[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            cout << "Pattern found at index " << i << endl;
        }

        if (i < n - m)
        {
            // Roll the hash for the next window
            for (int j = 0; j < numHashes; j++)
            {
                textHashes[j] = (primes[j] * (textHashes[j] - text[i] * h[j]) + text[i + m]) % moduli[j];
                if (textHashes[j] < 0)
                {
                    textHashes[j] = (textHashes[j] + moduli[j]);
                }
            }
        }
    }
}