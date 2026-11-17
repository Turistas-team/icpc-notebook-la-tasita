// Inverso Modular: a * inv(a) = 1 (mod MOD), con MOD primo y a no multiplo de MOD

const ll MOD = 1e9 + 7;

// ─── 1. Fermat (MOD primo) - O(log MOD) ─────────────────────────────────────
// Usa power(x, y, M) de binary-exponentiation.
ll inv(ll a) { return power(a % MOD, MOD - 2, MOD); }

// ─── 2. Arreglo de Inversos 1..N (MOD primo, N < MOD) - O(N) ────────────────
// inv(i) = -(MOD / i) * inv(MOD % i), con MOD % i < i ya calculado
const int MAXI = 1e6 + 5;
ll invs[MAXI];

void precomInv() {
    invs[1] = 1;
    for (int i = 2; i < MAXI; i++)
        invs[i] = (MOD - MOD / i) * invs[MOD % i] % MOD;
}
