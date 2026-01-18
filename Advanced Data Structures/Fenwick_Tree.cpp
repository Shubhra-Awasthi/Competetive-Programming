// Usage - sum, xor, freq cnt, pref min/max, k-th element
// Can do - pref sum, range sum, pt upd, range upd + pt qry, k-th element

int fen[n];

void add(int i, int val)
{ // O(log n)
    while (i < n)
    {
        fen[i] += val;
        i += (i & -i);
    }
}

// range sum query from 1 to i
void query(int i)
{ // O(log n)
    int sum = 0;
    while (i > 0)
    {
        sum += fen[i];
        i -= (i & -i);
    }
    return sum;
}

// binary lifting: lower bound for prefix sums
int find(int val)
{ // O(log n)
    int idx = 0;
    for (int i = log2(n); i >= 0; i--)
    {
        if (idx + (1 << i) < n && fen[idx + (1 << i)] < val)
        {
            val -= fen[idx + (1 << i)];
            idx += (1 << i);
        }
    }
    return idx + 1;
}