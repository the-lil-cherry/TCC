#include <bits/stdc++.h> 
using namespace std;

struct Path{
    long long start;
    long long end;
    Path * l;
    Path * r;
    unordered_set <Path *> L;
    unordered_set <Path *> R;
    long long w;
    long long ID;
};

Path * newPath(long long start, long long end, long long w, Path * l, Path * r){
    Path * new_path;
    new_path->start = start;
    new_path->end = end;
    new_path->l = l;
    new_path->r = r;
    new_path->w = w;
    new_path->ID = start;
    return new_path;
}

vector < vector < long long> > newMatrix(long long n, vector < vector <Path *> > * initial_paths){
    vector < vector < long long> > P(n, vector<long long>(n, 0));
    long long initial_w;
    for(long long i = 0; i<n; i++){
        for(long long j = 0; j<n; j++){
            cin >> initial_w;
            P[i][j] = initial_w;
            initial_paths[i][j].push_back(newPath(i, j, initial_w, nullptr, nullptr));
        }
    }
    return P;
}

