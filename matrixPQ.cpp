#include <bits/stdc++.h> 
#include "path.h"
#include "priorityQueue.h"
using namespace std;

class P{
    private:
        vector< vector < MinPQ > > matrix;
    
    private:
        void cleanup(Path * v){
            queue < Path * > Q;
            Q.push(v);
            Path * aux;
            while(!Q.empty()){
                aux = Q.front();
                Q.pop();
                for(auto i:aux->L){
                    Q.push(i);
                    matrix[i->start][i->end].remove(i);
                    // Falta retirar L(r(π)) e R(l(π))
                }
                for(auto i:aux->R){
                    Q.push(i);
                    matrix[i->start][i->end].remove(i);
                }
            }
        }
    
    public:
        P(){

        }
};