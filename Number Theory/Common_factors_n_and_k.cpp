lli res = 1;
for (ii p : PF)
{
    lli cnt = 0;
    while (k % p.ff == 0)
        cnt++, k /= p.ff;
    if (cnt > p.ss)
    {
        res = 0;
        break;
    }
    res *= (p.ss - cnt + 1);
}
if (k > 1)
    res = 0;
cout << res << endl;

// PF stores prime factors of N