// Usage - sum, min, max, lcm, gcd, xor, and/or, range cnt, max subarr sum, custom merge quer
// Can do - range qry, pt upd, range upd, range sum/min/max/gcd/xor, lazy propagation

int arr[n], seg[4 * n];

void build(int idx, int lo, int hi)
{ // O(n)
    if (lo == hi)
        seg[idx] = arr[lo];
    else
    {
        int mid = (lo + hi) >> 1;

        build(2 * idx + 1, lo, mid);
        build(2 * idx + 2, mid + 1, hi);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2]; // change acc to que
    }
}

int query(int idx, int lo, int hi, int l, int r)
{ // O(log n)
    if (r < lo || hi < l)
        return 0; // change acc to que
    if (l <= lo && hi <= r)
        return seg[idx];

    int mid = (lo + hi) >> 1;

    int left = query(2 * idx + 1, lo, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, hi, l, r);

    return left + right; // change acc to que
}

void pointUpdate(int idx, int lo, int hi, int pos, int val)
{ // O(log n)
    if (lo == hi)
        seg[idx] = val; // change acc to que
    else
    {

        int mid = (lo + hi) >> 1;

        if (pos <= mid)
            pointUpdate(2 * idx + 1, lo, mid, pos, val);
        else
            pointUpdate(2 * idx + 2, mid + 1, hi, pos, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2]; // change acc to que
    }
}

// lazy propagation for range update
void rangeUpdate(int idx, int lo, int hi, int l, int r, int val)
{ // O(log n)
    // pending updates
    if (lazy[idx])
    {
        seg[idx] += (hi - lo + 1) * lazy[idx]; // change acc to que

        if (lo != hi)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    // no overlap
    if (r < lo || hi < l || lo > hi)
        return;

    // complete overlap
    if (l <= lo && hi <= r)
    {
        seg[idx] += (hi - lo + 1) * val; // change acc to que

        if (lo != hi)
        {
            lazy[2 * idx + 1] += val;
            lazy[2 * idx + 2] += val;
        }

        return;
    }

    // partial overlap
    int mid = (lo + hi) >> 1;

    rangeUpdate(2 * idx + 1, lo, mid, l, r, val);
    rangeUpdate(2 * idx + 2, mid + 1, hi, l, r, val);

    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2]; // change acc to que
}

int querySumLazy(int idx, int lo, int hi, int l, int r, int val)
{ // O(log n)
    // pending updates
    if (lazy[idx])
    {
        seg[idx] += (hi - lo + 1) * lazy[idx]; // change acc to que

        if (lo != hi)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    // no overlap
    if (r < lo || hi < l || lo > hi)
        return 0; // change acc to que

    // complete overlap
    if (l <= lo && hi <= r)
        return seg[idx];

    // partial overlap
    int mid = (lo + hi) >> 1;

    int left = querySumLazy(2 * idx + 1, lo, mid, l, r);
    int right = querySumLazy(2 * idx + 2, mid + 1, hi, l, r);

    return left + right; // change acc to que
}