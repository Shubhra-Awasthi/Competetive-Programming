// Multiply 2 polynomials of degree n:

using cd = complex<double>;
const double PI = acos(-1);

// The recursive FFT function (Cooley-Tukey Radix-2)
vector<cd> fft(vector<cd> p, int n, int dir)
{
    if (n == 1)
        return p;

    // Even Odd split (Decimation-in-Frequency)
    vector<cd> Pe;
    Pe.reserve(n / 2);
    vector<cd> Po;
    Po.reserve(n / 2);
    for (int i = 0; 2 * i < n; ++i)
    {
        Pe.push_back(p[2 * i]);
        Po.push_back(p[2 * i + 1]);
    }

    // Recursion
    Pe = fft(Pe, n / 2, dir);
    Po = fft(Po, n / 2, dir);

    double ang = dir * (2 * PI) / n;
    cd w(1);                        // first value
    cd w_delta(cos(ang), sin(ang)); // 2nd value

    // Combine even odd
    for (int i = 0; i < n / 2; ++i)
    {
        p[i] = Pe[i] + w * Po[i];
        p[i + n / 2] = Pe[i] - w * Po[i];
        w *= w_delta; // update w
    }
    return p;
}

// The multiplication function using FFT
vector<long long> multiply(const vector<int> &a, const vector<int> &b)
{
    // Convert input polynomials to complex form
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());

    // Find nearest power of 2 >= deg(a)+deg(b)+1
    int n = 1;
    while (n < (int)a.size() + (int)b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    // value form (Forward FFT)
    fa = fft(fa, n, 1);
    fb = fft(fb, n, 1);

    // multiply (Pointwise multiplication)
    for (int i = 0; i < n; ++i)
        fa[i] *= fb[i];

    // coeff form (Inverse FFT)
    fa = fft(fa, n, -1);

    // remove complex and scale
    vector<long long> res(n);
    for (int i = 0; i < n; ++i)
        res[i] = (long long)llround(fa[i].real() / n);

    return res;
}