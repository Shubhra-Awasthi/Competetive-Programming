// ax + by = c, find any solution (x0, y0) store in x and y
// works if ax + by = gcd(a, b) has solution
bool find_any_solution(int a, int b, int c, int &x, int &y)
{
    int x0, y0;
    int g = gcd(abs(a), abs(b), x0, y0);
    if (c % g)
    {
        return false;
    }

    x = x0 * c / g;
    y = y0 * c / g;

    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;
    return true;
}

// O(log(min(|a|, |b|)))