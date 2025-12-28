int fen[n];

void update(int i, int add)
{
    while (i < n)
    {
        fen[i] += add;
        i += (i & -i);
    }
}

void query(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += fen[i];
        i -= (i & -i);
    }
    return sum;
}