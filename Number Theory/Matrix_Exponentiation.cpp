vector<vector<lli>> matrixPower(vector<vector<lli>> base, lli exp)
{
    int n = base.size();

    // Create identity matrix
    vector<vector<lli>> result(n, vector<lli>(n, 0));
    for (int i = 0; i < n; i++)
    {
        result[i][i] = 1;
    }

    // Fast exponentiation
    while (exp > 0)
    {
        if (exp & 1)
        {
            result = multiply(result, base);
        }
        base = multiply(base, base); // matrix squaring
        exp >>= 1;
    }

    return result;
}

// O(n^3 * log(exp))