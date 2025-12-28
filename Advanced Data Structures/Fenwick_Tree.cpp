int fen[n];

void update(int i, int add)
{
    while (i < n)
    {
        fen[i] += add;
        i += (i & -i);
    }
}

// range sum query from 1 to i
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

// binary lifting: lower bound for prefix sums
int find(int val)
{
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

/*
Concept:

Make an array of size n

Each node stores the sum of the range:
    Convert x to binary
    Turn off lsb
    Add 1, u get y
    The index stores sum of range [x,y]

Update operation:
    U need to update all indices which have x in their range.
    Start with idx x and add val(x)
    Repeateadly find next idx and do step 2:
        2's compliment of x = y
        And (x & y) = z
        Add x + z = new_idx
        Basically, i += (i & (-i))

Querry operation:
    start from right idx
    do the opposite of update to get prev idx and keep adding:
        2's compliment of x = y
        And (x & y) = z
        Add x - z = new_idx
        Basically, i -= (i & (-i))
*/