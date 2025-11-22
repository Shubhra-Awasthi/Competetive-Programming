vector<int> div(n + 1);
for (int i = 1; i <= n; i++)
{
    for (int j = i; j <= n; j += i)
    {
        div[j]++; // multiples of each i
    }
}

// O(n log n)