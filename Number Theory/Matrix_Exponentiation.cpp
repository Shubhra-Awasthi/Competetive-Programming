vector<vector<lli>> multiply(vector<vector<lli>> &A, vector<vector<lli>> &B)
{
    int n = A.size(), m = A[0].size(), p = B[0].size();
    vector<vector<lli>> C(n, vector<lli>(p, 0));

    for (int i = 0; i < n; i++)
        for (int k = 0; k < m; k++)
            for (int j = 0; j < p; j++)
                C[i][j] += A[i][k] * B[k][j];

    return C;
}

vector<vector<lli>> matrixPower(vector<vector<lli>> base, lli exp)
{
    int n = base.size();

    // Create identity matrix
    vector<vector<lli>> result(n, vector<lli>(n, 0));
    for (int i = 0; i < n; i++)
        result[i][i] = 1;

    // Fast exponentiation
    while (exp > 0)
    {
        if (exp & 1)
            result = multiply(result, base);

        base = multiply(base, base); // matrix squaring
        exp >>= 1;
    }

    return result;
}

// O(n^3 * log(exp))