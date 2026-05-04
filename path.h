#include <bits/stdc++.h> 
using namespace std;

class Path{
    public:
        long long start;
        long long end;
        Path * l;
        Path * r;
        unordered_set <Path *> L;
        unordered_set <Path *> R;
        long long weight;
        long long ID;
        long long indexPQ;
    
    public:
        Path(long long x){
            start = x;
            end = x;
            weight = LLONG_MAX;
            ID = x;
        }

        Path(long long x, long long y, long long w, Path * left, Path * right, long long n){
            start = x;
            end = y;
            weight = w;
            l = left;
            r = right;
            ID = x + n*y; 
        }

};