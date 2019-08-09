typedef pair < double , double > pt 

bool cw(pt a, pt b, pt c) {
    return a.F*(b.S-c.S)+b.F*(c.S-a.S)+c.F*(a.S-b.S) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.F*(b.S-c.S)+b.F*(c.S-a.S)+c.F*(a.S-b.S) > 0;
}

void convex_hull(vector<pt>& a) {
    
    if (a.size() == 1) return;

    sort(all(a));
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.pb(p1);
    down.pb(p1);

    for (int i = 1; i < sz(a); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (sz(up) >= 2 && !cw(up[sz(up)-2], up[sz(up)-1], a[i]))
                up.pop_back();
            up.pb(a[i]);
        }
        if (i == sz(a) - 1 || ccw(p1, a[i], p2)) {
            while(sz(down) >= 2 && !ccw(down[sz(down)-2], down[sz(down)-1], a[i]))
                down.pop_back();
            down.pb(a[i]);
        }
    }

    a.assign(all(up)) ; 
    a.insert(a.end(),all(down)) ;
}