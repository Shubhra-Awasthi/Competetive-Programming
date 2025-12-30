int a, b, mod; // mod is prime
a = a % mod;
inv_b = pw(b, mod - 2, mod); // binary exponentiation
res = a * inv_b % mod;

// Divide arithmodetic
//  O(log mod)