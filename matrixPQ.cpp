#include <bits/stdc++.h> 
#include "path.h"
#include "priorityQueue.h"
using namespace std;

class shortestPaths{
    public:
        vector < vector < long long> > weight;
        long long n; // tamanho da matriz

    private:
        vector< vector < MinPQ > > P;
        vector < vector < Path * > > Pstar;
        vector < vector < unordered_set <Path *> > > Lstar;
        vector < vector < unordered_set <Path *> > > Rstar;
        //matriz de pesos é publica


    private:
        void cleanup(long long v){
            queue < Path * > Q;
            Q.push(P[v][v].min());
            Path * aux;
            while(!Q.empty()){
                aux = Q.front();
                Q.pop();
                for(auto i:aux->L){
                    Q.push(i);
                    P[i->start][i->end].remove(i);
                    (i->r)->L.erase(i);
                    (i->l)->R.erase(i);

                    if(Pstar[i->start][i->end] == i){
                        Pstar[i->start][i->end] == nullptr;
                        Lstar[i->r->start][i->r->end].erase(i);
                        Rstar[i->l->start][i->l->end].erase(i);

                    }
                }
                for(auto i:aux->R){
                    Q.push(i);
                    P[i->start][i->end].remove(i);
                    (i->r)->L.erase(i);
                    (i->l)->R.erase(i);

                    if(Pstar[i->start][i->end] == i){
                        Pstar[i->start][i->end] == nullptr;
                        Lstar[i->r->start][i->r->end].erase(i);
                        Rstar[i->l->start][i->l->end].erase(i);

                    }
                }
            }
        }
    
    public:
        shortestPaths(long long n){

        }
};