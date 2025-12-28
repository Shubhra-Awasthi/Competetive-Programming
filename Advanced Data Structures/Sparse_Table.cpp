int arr[n];
int st[n][log(n) + 1];

void build()
{ // O(n log n)
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for (int j = 1; j < log(n) + 1; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r)
{ // O(1)
    int j = 31 - __builtin_clz(r - l + 1);
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}