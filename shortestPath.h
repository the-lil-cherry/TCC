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
        
        void fixup(long long v, vector<long long> w){

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
            cout << endl;
        }


};