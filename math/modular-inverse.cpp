// Inverso Modular: a * inv(a) = 1 (mod M), existe solo si gcd(a, M) = 1

const ll MOD = 1e9 + 7;

// ─── 1. Fermat (MOD primo) - O(log MOD) ─────────────────────────────────────
// Usa power(x, y, M) de binary-exponentiation.
ll inv(ll a) { return power(a % MOD, MOD - 2, MOD); }

// ─── 2. Euclides Extendido (M cualquiera, gcd(a, M) = 1) - O(log M) ─────────
// Encuentra x, y tal que a*x + b*y = gcd(a, b)
ll extgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Retorna -1 si no existe inverso
ll invGcd(ll a, ll m) {
    ll x, y;
    if (extgcd(((a % m) + m) % m, m, x, y) != 1) return -1;
    return ((x % m) + m) % m;
}

// ─── 3. Arreglo de Inversos 1..N (MOD primo, N < MOD) - O(N) ────────────────
// inv(i) = -(MOD / i) * inv(MOD % i), con MOD % i < i ya calculado
const int MAXI = 1e6 + 5;
ll invs[MAXI];

void precomInv() {
    invs[1] = 1;
    for (int i = 2; i < MAXI; i++)
        invs[i] = (MOD - MOD / i) * invs[MOD % i] % MOD;
}
