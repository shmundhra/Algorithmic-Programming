vll rabin_karp(str const& s, str const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = sz(s), T = sz(t);

    vll p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < sz(p_pow) ; i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vll h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    ll h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vll occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        ll cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.pb(i);
    }
    return occurences;
}