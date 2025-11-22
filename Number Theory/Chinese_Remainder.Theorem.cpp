/*
 Solve a = a1 mod n1 = a2 mod n2 = … = ak mod nk
 where ni are pairwise coprime
 Returns a mod N where N = n1*n2*...*nk
*/

bool combine_congruences(long long a1, long long m1, long long a2, long long m2,
                         long long &A, long long &M)
{
    long long g, x, y;

    g = extended_gcd(m1, m2, x, y);

    if ((a2 - a1) % g != 0)
    {
        return false;
    }

    long long factor = (a2 - a1) / g;
    long long m_prime = m2 / g;

    long long k1 = (long long)(((unsigned long long)x * factor) % m_prime);

    if (k1 < 0)
        k1 += m_prime;

    M = (m1 / g) * m2;

    A = a1 + k1 * m1;
    A %= M;
    if (A < 0)
        A += M;

    return true;
}

pair<long long, long long> general_chinese_remainder_theorem(
    const vector<long long> &a, const vector<long long> &m)
{

    if (a.empty() || a.size() != m.size())
        return {-1, 0};

    long long current_A = a[0];
    long long current_M = m[0];

    for (size_t i = 1; i < a.size(); ++i)
    {
        long long next_A, next_M;

        bool solvable = combine_congruences(
            current_A, current_M, a[i], m[i], next_A, next_M);

        if (!solvable)
        {
            return {-1, 0};
        }

        current_A = next_A;
        current_M = next_M;
    }

    return {current_A, current_M};
}