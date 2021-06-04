bool check(int x) {;}

//两种情况,试check函数而定
//case 1: [L, R] 被分为[L, mid-1], [mid, R] "L=mid"
int bserach_1(int l, int r) {
    while(l<r) {
        int mid = (l+r+1) >> 1;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
    
    return l;
}

//case 2: [L,R]被分为[L, mid], [mid+1, R] "R=mid"
int bsearch_2(int l, int r) {
    while(l<r) {
        int mid = (l+r)>>1;
        if (check(mid)) r = mid;
        else l = mid+1;
    }
    return l;
}