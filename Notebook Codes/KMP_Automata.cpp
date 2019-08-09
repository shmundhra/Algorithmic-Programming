void compute_automaton(string s, vec <vll>& aut) {
    s += '#';
    int n = sz(s);
    vll pi = prefix_function(s);
    aut.assign(n, vll(26));
    lp(i,n) {
        lp(c,26) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
