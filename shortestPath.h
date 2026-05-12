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

            // ======== Phase 2 ========

                priority_queue < Path *, vector <Path *>, ComparePath > H;

                for(long long i = 0; i< n; i++){
                    for(long long j = 0; j<n; j++){
                        if(P[i][j].min() != nullptr){
                            H.push( P[i][j].min());
                        }
                    }
                }

            // ======== Phase 3 ========
                Path * pi_xy;
                Path * r_xy;
                Path * l_xy;
                long long x, y, new_w, X, Y; // X = x' e Y = y'
                while(!H.empty()){
                    pi_xy = H.top();
                    H.pop();
                    x = pi_xy->start;
                    y = pi_xy->end;
                    r_xy = pi_xy->r;  // caminho πxb -> πxy =  πxb + <b, y>
                    l_xy = pi_xy->l;  // caminho πay -> πxy =  <x, a> + πay

                    if(Pstar[x][y] != pi_xy){
                        Pstar[x][y] = pi_xy;
                        Lstar[x][r_xy->end].insert(pi_xy);
                        Rstar[l_xy->start][y].insert(pi_xy);

                        for( auto pi_Xb : Lstar[l_xy->start][y]){
                            X = pi_Xb->start;

                            new_w = weight[X][x] + w[x][y];
                            Path * pi_Xy = new Path(X, y, new_w, pi_Xb, pi_xy, n);

                            P[X][y].insert(pi_Xy);
                            pi_xy->L.insert(pi_Xy);
                            pi_Xb->R.insert(pi_Xy);
                        }
                        
                        for(auto pi_aY : Rstar[x][r_xy->end]){
                            Y = pi_aY->end;

                            new_w = w[x][y] + weight[y][Y];
                            Path * pi_xY = new Path(x, Y, new_w, pi_xy, pi_aY, n);

                            P[x][Y].insert(pi_xY);
                            pi_xy->R.insert(pi_xY);
                            pi_aY->L.insert(pi_xY);
                        }
                    }
                }
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