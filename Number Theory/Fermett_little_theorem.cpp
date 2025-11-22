int a, b, m; // m is prime
a = a % m;
inv_b = pw(b, m - 2, m); // binary exponentiation
res = a * inv_b % m;

// Divide arithmetic
//  O(log m)