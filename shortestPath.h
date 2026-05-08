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
                    // jogar fora o caminho i? 
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
                    // jogar fora o caminho i? 
                }
            }
        }
        
        void fixup(long long v,vector < vector<long long> > w){
            // ======== Phase 1 ========
            Path * path_v;
            Path * path_u;
            path_v = P[v][v].min();
            for(long long u = 0; u<n; u++){
                if(u != v){
                    path_u = P[u][u].min();
                    weight[v][u] = w[v][u];
                    weight[u][v] = w[u][v];

                    if(weight[u][v]<LLONG_MAX){
                        Path * new_path = new Path(u, v, weight[u][v],path_u, path_v ,n);
                        P[u][v].insert(new_path);
                        path_u->R.insert(new_path);
                        path_v->L.insert(new_path);
                    }

                    if(weight[v][u]<LLONG_MAX){
                        Path * new_path = new Path(v, u, weight[v][u],path_v, path_u ,n);
                        P[v][u].insert(new_path);
                        path_v->R.insert(new_path);
                        path_u->L.insert(new_path);
                    }
                }
            // ======== end Phase 1 ========

            // ======== Phase 2 ========

            // ======== end Phase 2 ========

            // ======== Phase 3 ========
            // ======== end Phase 3 ========
            }
        }
    
    public:
        shortestPaths(long long tamanho, vector < vector < long long > > w){
            n = tamanho;
            weight = w;
        }

        void distance(long long x, long long y){
            Path * aux = P[x][y].min();
            if(aux!= nullptr){
                cout << aux->weight<< endl;
            }
            else{
                cout << "INF" << endl;
            }
        }

        void path(long long x, long long y){
            Path * aux = P[x][y].min();
            if(aux != nullptr){
                do{
                    cout << aux->start << " ";
                    aux = aux->r;
                }
                while(aux->r!=nullptr);
            }
            else{
                cout << "There is no path from " << x << "to " << y; 
            }
            cout << endl;
        }

        void update(long long v, vector<vector < long long >> w){
            cleanup(v);
            fixup(v, w);
        }


};