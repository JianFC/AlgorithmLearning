bool check(double mid) {;}

double bsearch(double l, double r) {
    const double eps = 1e-8;
    while(r - l> eps) {
        double mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid; 
    }

    // for (int i=1; i<=100; i++) {
    //     double mid = (l+r)/2;
    //     if (check(mid)) r = mid;
    //     else l = mid;
    // }

    return l;
}